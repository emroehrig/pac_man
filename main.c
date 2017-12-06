#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <time.h>

//déclaration des fonctions
void clrscr (void);
char get_key(void);
void hidecursor(void);
void affichage(void);

int tableau1[22][22]={0};

int main()
{

// déclaration des variables
    int pacman=5;
    int fantome1=3;

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
    int compteur;
    int f1_pos_x=15;
    int f1_pos_y=15;
    int distance_x;
    int distance_y;
    int f1_temp_x=15;
    int f1_temp_y=15;
    int nombre=1;
    int temps_pause_2=1000;


//intialisation du fichier à importer
    FILE* fichier=NULL;
    char chaine[22]="";
    int ligne=0;
    int colonne=0;

//initialisation des variables
    tempy=1;
    tempx=1;
    positionx=1;
    positiony=1;
    temps_de_pause=100;
    compteur=0;
//importation du fichier texte
    fichier=fopen("Grille1.txt","r");

    if(fichier != NULL)
    {
        for(ligne=0;ligne<22;ligne++)
        {
            fgets(chaine,22,fichier);

            for(colonne=0;colonne<22;colonne++)
           {
               if(chaine[colonne]=='0' || chaine[colonne]=='1' || chaine[colonne]=='2')
               {
                  tableau1[colonne][ligne]=chaine[colonne]-48; //importation de la chaine dans le tableau
               }
            }
        }
    }

    while(quitter!='p')
    {
    hidecursor(); //effacement du curseur
//rafraichissement de l'écran
       Sleep(temps_de_pause);
        clrscr();
//gestion de la position
    tableau1[positionx][positiony]=pacman;
    tableau1[f1_pos_x][f1_pos_y]=fantome1;
    tempy=positiony;
    tempx=positionx;
    f1_temp_x=f1_pos_x;
    f1_temp_y=f1_pos_y;

//affichage de la grille
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
//gestion des collisions
    tableau1[tempx][tempy]=0;


    if(tableau1[positionx][positiony]==1)
    {
        positiony=tempy;
        positionx=tempx;
    }

  if(tableau1[positionx][positiony]==2)
    {
      tableau1[positionx][positiony]=0;
      compteur=compteur+1;
    }
    printf("votre score est : %d",compteur);


//gestion des déplacements du fantome
    tableau1[f1_temp_x][f1_temp_y]=0;
    distance_x=(positionx-f1_pos_x);
    distance_y=(positiony-f1_pos_y);

if((distance_x*distance_x)<35 && (distance_y*distance_y)<35)
{
       if(distance_x*distance_x>=distance_y*distance_y)
    {
        if(distance_x>0)
        {
            f1_pos_x=f1_pos_x+1;
        }
    else
        {
            f1_pos_x=f1_pos_x-1;
        }
    }
    else
    {
    if(distance_y>0)
        {
            f1_pos_y=f1_pos_y+1;
        }
    else
        {
            f1_pos_y=f1_pos_y-1;
        }
    }

}
else
{

printf("chiffre %d", nombre);

 switch(nombre)
 {
     case 0 : {f1_pos_x=f1_pos_x+1;}break;
     case 1 : {f1_pos_x=f1_pos_x-1;}break;
     case 2 : {f1_pos_y=f1_pos_y+1;}break;
     case 3 : {f1_pos_y=f1_pos_y-1;}break;
 }

}

    if(tableau1[f1_pos_x][f1_pos_y]==1)
    {
        f1_pos_x=f1_temp_x;
        f1_pos_y=f1_temp_y;
        nombre=rand()%4;
    }

    if(tableau1[f1_pos_x][f1_pos_y]==2)
    {
      tableau1[f1_temp_x][f1_temp_y]=2;
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
//affichage de la grille
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
                 if (tableau1[i][j]==2)
                {
                    printf(". ");
                }
                  if (tableau1[i][j]==3)
                {
                    printf("M ");
                }

           }
            printf("\n");
        }
}
