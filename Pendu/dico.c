#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>
#include "dico.h"

int takeWord(char *takenWord)
{
    FILE* dico = NULL;
    int numberWords = 0, numberWordChose = 0, i = 0;
    int readChar = 0;
    //ligne ? changer ver le dictionnaire 
    dico = fopen("C:/Users/Elie/Documents/GitHub/Rattrapage-C/Pendu/dico.txt", "r");

    if (dico == NULL)
    {
        printf("\nImpossible d'ouvrir le fichier donn?es en lecture\n");
        return 0;
    }

    do
    {
        readChar = fgetc(dico);
        if (readChar == '\n')
            numberWords++;
    } while(readChar != EOF);

    numberWordChose = randomNumber(numberWords);

    rewind(dico);
    while (numberWordChose > 0)
    {
        readChar = fgetc(dico);
        if (readChar == '\n')
            numberWordChose--;
    }

    fgets(takenWord, 100, dico);

    takenWord[strlen(takenWord) - 1] = '\0';
    fclose(dico);

    return 1;
}

int randomNumber(int numberMax)
{
    srand(time(NULL));
    return (rand() % numberMax);
}
