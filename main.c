#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
int main()
{

    int pacman=1;
    int tableau1[6][6]={0};
    int i=0;
    int j=0;
    int positionx;
    int positiony;
    char quitter;
    char lettre;
    positionx=0;
    positiony=0;


    while(quitter!='p')
    {
         for(j=0;j<6;j++)
        {

        for(i=0;i<6;i++)
            {
                tableau1[i][j]=0;

            }
        }

    tableau1[positionx][positiony]=pacman;

    for(j=0;j<6;j++)
        {

        for(i=0;i<6;i++)
            {
                printf("%d ",tableau1[i][j]);

            }
            printf("\n");
        }

    printf("\n");
    lettre=getch();

    switch(lettre)
    {
        case's':{positiony=positiony+1;}break;
        case'z':{positiony=positiony-1;}break;
        case'q':{positionx=positionx-1;}break;
        case'd':{positionx=positionx+1;}break;
    }
    }

}
