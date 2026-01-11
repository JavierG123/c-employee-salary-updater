//EJERCICIO 31------------------------------------------------------------------

#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#define N 45
#pragma hdrstop

//---------------------------------------------------------------------------

#pragma argsused
void main()
{
        int i,numero;
        float sueldo[N],sueldo_nuevo[N],mayor=0;
        char sexo[N],res;




        //CARGA DE DATOS.

        for(i=0;i<N;i++)
        {
                printf("\n\nIngrese el sexo del trabajador N.%d (m=masculino/f=femenino)\n\n",i+1);
                fflush(stdin);
                scanf("%c",&sexo[i]);
                printf("\n\nIngrese el sueldo del trabajador N.%d\n\n",i+1);
                scanf("%f",&sueldo[i]);
                clrscr();
        }


        //PARTE A.


        for(i=0;i<N;i++)
        {
                if((sexo[i]=='f'||sexo[i]=='F')&&sueldo[i]<350000)
                {
                        sueldo_nuevo[i]=sueldo[i]+sueldo[i]*0.12;
                }
                else
                        if((sexo[i]=='m'||sexo[i]=='M')&&(sueldo[i]>=350000&&sueldo[i]<=676000))
                        {
                                sueldo_nuevo[i]=sueldo[i]+sueldo[i]*0.07;
                        }
                                else
                                sueldo_nuevo[i]=sueldo[i];


        }

        gotoxy(5,5);
        printf("Empleado N.");
        gotoxy(28,5);
        printf("Sueldo anterior");
        gotoxy(57,5);
        printf("Sueldo actual");
        getche();

        for(i=0;i<N;i++)
        {
                gotoxy(5,8+i);
                printf("%d",i+1);
                gotoxy(28,8+i);
                printf("%0.2f",sueldo[i]);
                gotoxy(57,8+i);
                printf("%0.2f",sueldo_nuevo[i]);
        }
        getche();
        clrscr();


        //PARTE B.

        do
        {
                do
                {
                        printf("\n\nIntroduzca el numero de empleado que desea consultar: \n\n");
                        scanf("%d",&numero);
                        if(numero<1||numero>N)
                        {
                                printf("\n\nPor favor introdusca un numero comprendido entre 1-%d.\n\n",N);
                                system("pause");
                                clrscr();
                        }
                }while(numero<1||numero>N);
                clrscr();


                gotoxy(5,5);
                printf("Empleado N.");
                gotoxy(28,5);
                printf("Sueldo anterior");
                gotoxy(57,5);
                printf("Sueldo actual");
                getche();
                for(i=0;i<N;i++)
                {
                        if(i+1==numero)
                        {
                                gotoxy(5,8);
                                printf("%d",i+1);
                                gotoxy(28,8);
                                printf("%0.f",sueldo[i]);
                                gotoxy(57,8);
                                printf("%0.2f",sueldo_nuevo[i]);
                        }
                }
                getche();
                clrscr();

                printf("otro empleado a consultar? (s/n)\n\n");
                fflush(stdin);
                scanf("%c",&res);
        }while((res=='s'||res=='S')&&(res!='s'||res!='S'));
        getche();
        clrscr();




        //PARTE C.


        for(i=0;i<N;i++)
        {
                if(sueldo_nuevo[i]>mayor)
                        mayor=sueldo_nuevo[i];
        }

        gotoxy(5,5);
        printf("\n\nEl mayor sueldo incrementado fue de %0.2f y la posicion de los trabajadores con el mismo incremento de sueldo es:",mayor);


        for(i=0;i<N;i++)
        {
                if(sueldo_nuevo[i]==mayor)
                {
                        gotoxy(5,10+i);
                        printf("%d",i+1);
                }
        }
        printf("\n\n");
        system("pause");









}
//FIN DEL PROGRAMA-----------------------------------------------------------

