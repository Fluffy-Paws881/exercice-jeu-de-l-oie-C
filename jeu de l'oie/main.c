#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#define CASE 66 //nb de case sur le plateau

int posJoueur =0  , resDee;
char recup;

int getRando() //initialisation du random
{
    time_t t;

    /* Intializes random number generator */
    srand((unsigned) time(&t));

    return (rand()%12)+2;
}

void lanceDee()// lancee des 2 dees
{
    int rando = getRando();

     printf("vous venez de faire un %d\n",rando);
     scanf("%c",& recup);

     resDee = rando;

     system("cls");

}

void intialisation()// affichage du debut
{
    system("cls");

    printf("appuyer sur entrer pour commencer");
    scanf("%c",& recup);

    system("cls");
}

void caseMort()// fonctionnement de la case piegé
{
    if (posJoueur == 58)
    {
        posJoueur = 0;
        printf("oh non, vous etes tomber sur la tete de mort, vous retournez au depart");
        scanf("%c",& recup);
    }
}

void verifPos()//verification de la position du joueur
{
    if ((posJoueur % 9 == 0) && (posJoueur < 62))
    {
        posJoueur += resDee;
        printf("bravo, vous etes tombee sur une oie, vous doublez votre deplacement");
        scanf("%c",& recup);
    }

    if (posJoueur > CASE)
    {
        resDee = (posJoueur - CASE);

        posJoueur = CASE - resDee;

        if (posJoueur == 58)
        {
            caseMort();
        }else{
        printf("mince vous avez depasse la case, vous reculez");
        scanf("%c",& recup);
        }
    }
}



int main()
{
    intialisation();

    do
    {
        lanceDee();

        posJoueur += resDee;
        verifPos();


        printf("vous etes sur la case %d\n",posJoueur);
        scanf("%c",& recup);
        system("cls");

    }
    while (posJoueur != CASE);

        printf("felicitation, vous avez gagne");
        scanf("%c",& recup);


}
