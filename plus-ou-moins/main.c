#include <stdio.h>
#include <stdlib.h>
#include <time.h>

    /* |~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|
       |                    Developpé par :                           |
       |                    Elie Ryckelynck                           |
       |                        ESI 1                                 |
       |~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|
    */

int main(int argc, char *argv[])
{

    printf("--- Le juste Prix---\n\n");
     printf("--- Reussirez-vous a trouver le juste Prix ?---\n");

//Declaration des variable
    int NombreMystere = 0, NombreEntre = 0, NombreCoups = 0, Max = 0,Difficulte=0,Recommencer=0;
    const int Min = 1;
    //demarrage de la boucle du jeu pour pouvoir recommencer
    do
    {
    printf("Choix de la difficultee : \n");
    printf("1 Niveau facile : Entre 1 et 100\n");
    printf("2 Niveau moyen : Entre 1 et 1000\n");
    printf("3 Niveau difficile : Entre 1 et 10000\n");
    printf("Selection :");
    srand(time(NULL));


        //Recuperation de la difficulté
        do
        {

                scanf("%d", &Difficulte);
        } while (Difficulte < 1 || Difficulte > 3);

        if (Difficulte == 1 )
        {
            Max = 100;
            NombreMystere = (rand() % (Max - Min + 1)) + Min;
        }
        else if (Difficulte ==2 )
        {
            Max = 1000;
            NombreMystere = (rand() % (Max - Min + 1)) + Min;
        }
        else if (Difficulte ==3 )
        {
            Max = 10000;
            NombreMystere = (rand() % (Max - Min + 1)) + Min;
        }
        //flush du terminal
        system("cls");
        //affichage des parametre :
        printf("\n Difficulte choisis :%d \n", Difficulte);
        printf(" Max :%d \n", Max);


            do{
                //on compte le nombre de coups
                NombreCoups++;
                printf("Quel est le Montant ? ");
                scanf("%d", &NombreEntre);

                // On compare le Nombre entré avec le Montant mystere

                if (NombreMystere > NombreEntre)
                    printf("C'est plus !\n\n");
                else if (NombreMystere < NombreEntre)
                    printf("C'est moins !\n\n");
                else
                    printf ("Bravo, vous avez trouve le Montant !!! en %d coups \n\n", NombreCoups);
            } while (NombreEntre != NombreMystere);
            system("cls");
    printf("Souhaitez-vous refaire une partie ?\n");
    printf("1. Oui\n");
    printf("2. Non\n");
    printf("Votre choix ? ");
    //choix pour redemarrer la boucle
    scanf("%d", &Recommencer);
} while (Recommencer == 1);
    return 0;
}
