#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <time.h>

void clrscr (void);
char get_key(void);
void hidecursor(void);
void affichage(void);

int tableau1[22][22]={0};

int main()
{


    int pacman=5;

    int i=0;
    int j=0;
    int dieze=0;
    int positionx;
    int positiony;
    int temps_de_pause;
    int tempy;
    int tempx;
    char quitter;
    char lettre;

    FILE* fichier=NULL;
    char chaine[22]="";
    int ligne=0;
    int colonne=0;

    tempy=1;
    tempx=1;
    positionx=1;
    positiony=1;
    temps_de_pause=100;

    while(quitter!='p')
    {
    hidecursor();

    //initialisation des tableaux
       for(j=0;j<20;j++)
        {

        for(i=0;i<20;i++)
            {
                tableau1[i][j]=0;
            }
        }

    //ouverture et lecture du fichier texte

    fichier=fopen("Grille1.txt","r");

    if(fichier != NULL)
    {
        for(ligne=0;ligne<22;ligne++)
        {
            fgets(chaine,22,fichier);

            for(colonne=0;colonne<22;colonne++)
           {
               if(chaine[colonne]=='0' || chaine[colonne]=='1')
               {
                  tableau1[colonne][ligne]=chaine[colonne]-48;
               }
            }
        }
    }

       Sleep(temps_de_pause);
        clrscr();

    tableau1[positionx][positiony]=pacman;
    tempy=positiony;
    tempx=positionx;
    affichage();

    printf("\n");

//gestion des touches
   lettre=get_key();

    switch(lettre)
    {
        case's':{positiony=positiony+1;}break;
        case'z':{positiony=positiony-1;}break;
        case'q':{positionx=positionx-1;}break;
        case'd':{positionx=positionx+1;}break;
    }

    if(tableau1[positionx][positiony]==1)
    {
       positiony=tempy;
    }

       if(tableau1[positionx][positiony]==1)
    {
       positionx=tempx;
    }

}
}

// vide l'écran
void clrscr(void)
{
    HANDLE handle;
    COORD coord= { 0, 0 };
    DWORD nbcar;
    CONSOLE_SCREEN_BUFFER_INFO info;
    handle = GetStdHandle(STD_OUTPUT_HANDLE);
    GetConsoleScreenBufferInfo(handle,&info);
    FillConsoleOutputCharacter(handle, (TCHAR) ' ',info.dwSize.X *
                               info.dwSize.Y,coord,&nbcar);
    SetConsoleCursorPosition(handle,coord);
}
//Recherche du dernier caractère (renvoie 0 si il n'y a pas de caractère)
char get_key(void)
{
    char lettre=0;
    while(_kbhit()) {
        lettre = _getch();
    }
    return lettre;
}
//Supression du curseur sur l'ecran
void hidecursor()
{
   HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
   CONSOLE_CURSOR_INFO info;
   info.dwSize = 100;
   info.bVisible = FALSE;
   SetConsoleCursorInfo(consoleHandle, &info);
}

void affichage(void)
{
    int i;
    int j;

        for(j=0;j<20;j++)
    {

        for(i=0;i<20;i++)
            {
                if (tableau1[i][j]==0)
                {
                    printf("  ");
                }
                if (tableau1[i][j]==1)
                {
                    printf("%c%c",219,219);
                }
                if (tableau1[i][j]==5)
                {
                    printf("O ");
                }
           }
            printf("\n");
        }
}
