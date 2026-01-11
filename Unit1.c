#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

#define N 45

// Función para posicionar el cursor
void gotoxy(int x, int y) {
    COORD coord = {x, y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

// Función para limpiar la pantalla
void clrscr() {
    system("cls");
}

// Función para pausar y esperar tecla
void waitForKey() {
    printf("\nPress any key to continue...\n");
    getchar();
}

int main() {
    int i, numero;
    float sueldo[N], sueldo_nuevo[N], mayor = 0;
    char sexo[N], res;

    // CARGA DE DATOS
    for(i = 0; i < N; i++) {
        printf("\nIngrese el sexo del trabajador N.%d (m=masculino/f=femenino): ", i + 1);
        fflush(stdin);
        scanf(" %c", &sexo[i]); // Espacio antes de %c para capturar correctamente
        printf("Ingrese el sueldo del trabajador N.%d: ", i + 1);
        scanf("%f", &sueldo[i]);
        clrscr();
    }

    // PARTE A: Calculo de sueldo nuevo
    for(i = 0; i < N; i++) {
        if((sexo[i] == 'f' || sexo[i] == 'F') && sueldo[i] < 350000) {
            sueldo_nuevo[i] = sueldo[i] * 1.12;
        } else if((sexo[i] == 'm' || sexo[i] == 'M') && sueldo[i] >= 350000 && sueldo[i] <= 676000) {
            sueldo_nuevo[i] = sueldo[i] * 1.07;
        } else {
            sueldo_nuevo[i] = sueldo[i];
        }
    }

    // Mostrar tabla
    gotoxy(5,5);
    printf("Empleado N.");
    gotoxy(28,5);
    printf("Sueldo anterior");
    gotoxy(57,5);
    printf("Sueldo actual");
    getchar();

    for(i = 0; i < N; i++) {
        gotoxy(5, 8 + i);
        printf("%d", i + 1);
        gotoxy(28, 8 + i);
        printf("%0.2f", sueldo[i]);
        gotoxy(57, 8 + i);
        printf("%0.2f", sueldo_nuevo[i]);
    }

    waitForKey();
    clrscr();

    // PARTE B: Consulta individual
    do {
        do {
            printf("Introduzca el numero de empleado que desea consultar: ");
            scanf("%d", &numero);
            if(numero < 1 || numero > N) {
                printf("Por favor introduzca un numero entre 1 y %d.\n", N);
                waitForKey();
                clrscr();
            }
        } while(numero < 1 || numero > N);
        clrscr();

        gotoxy(5,5);
        printf("Empleado N.");
        gotoxy(28,5);
        printf("Sueldo anterior");
        gotoxy(57,5);
        printf("Sueldo actual");

        gotoxy(5,8);
        printf("%d", numero);
        gotoxy(28,8);
        printf("%0.2f", sueldo[numero-1]);
        gotoxy(57,8);
        printf("%0.2f", sueldo_nuevo[numero-1]);

        waitForKey();
        clrscr();

        printf("Otro empleado a consultar? (s/n): ");
        fflush(stdin);
        scanf(" %c", &res);
    } while(res == 's' || res == 'S');

    clrscr();

    // PARTE C: Mayor sueldo incrementado
    for(i = 0; i < N; i++) {
        if(sueldo_nuevo[i] > mayor)
            mayor = sueldo_nuevo[i];
    }

    gotoxy(5,5);
    printf("El mayor sueldo incrementado fue de %0.2f y la posicion de los trabajadores con el mismo sueldo es: ", mayor);

    for(i = 0; i < N; i++) {
        if(sueldo_nuevo[i] == mayor) {
            gotoxy(5, 10 + i);
            printf("%d", i + 1);
        }
    }

    waitForKey();
    return 0;
}
