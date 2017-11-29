#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <time.h>

void clrscr (void);
char get_key(void);
void hidecursor(void);


int main()
{
//ouverture et lecture du fichier texte
    FILE* fichier=NULL;
    char chaine[20]="";
    int ligne=0;

    fichier=fopen("Grille1.txt","r");

    if(fichier != NULL)
    {
        for(ligne=0;ligne<40;ligne++)
        {
            fgets(chaine,20,fichier);
        printf("%s",chaine);
        }
    }

/*    int pacman='o';
    char tableau1[20][20]={0};
    int i=0;
    int j=0;
    int dieze=0;
    int positionx;
    int positiony;
    int temps_de_pause;
    char quitter;
    char lettre;

    positionx=0;
    positiony=0;
    temps_de_pause=150;

    while(quitter!='p')
    {

        hidecursor();
    //initialisation des tableaux
         for(j=0;j<20;j++)
        {

        for(i=0;i<20;i++)
            {
                tableau1[i][j]=' ';

            }
        }

        tableau1[2][0]='#';
        Sleep(temps_de_pause);
        clrscr();

//affichage du bord
    for(dieze=0;dieze<20;dieze++)
    {
        tableau1[dieze][0]='#';
        tableau1[dieze][19]='#';
        tableau1[0][dieze]='#';
        tableau1[19][dieze]='#';
    }
//affichage des obstables



// définition des limites
    if(positionx>18)
    {
        positionx=18;
    }

    if(positionx<1)
    {
        positionx=1;
    }

    if(positiony>18)
    {
        positiony=18;
    }

    if(positiony<1)
    {
        positiony=1;
    }

//affichage de la grille
    tableau1[positionx][positiony]=pacman;
    for(j=0;j<20;j++)
        {

        for(i=0;i<20;i++)
            {
                printf("%c ",tableau1[i][j]);

            }
            printf("\n");
        }

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
    }*/

}

// vide l'écran
/*void clrscr(void)
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
}*/
