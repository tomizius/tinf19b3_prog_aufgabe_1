#include <stdio.h>
#include <string.h>

int main(int arg, char *argv[]) {

    FILE *file = fopen("/home/thomas/CLionProjects/Uebung_14_02_2020/characters.txt", "r");
    if (file == NULL){
        printf("Datei nicht gefunden\n");
        return 1;
    }

    char characterInFile;
    int characterCounter = 0;
    int spaceAndReturnCounter = 0;

    printf("\nFile content:\n");

    while((characterInFile = getc(file)) != EOF ) {
        printf("%c", characterInFile);
        printf("%d", characterInFile);
        if (characterInFile == 32 || characterInFile == 10){
            spaceAndReturnCounter++;
        } else{
            characterCounter++;
        }
    }

    printf("\nAnzahl der Characters in der Text-Datei: %i\n", characterCounter);

    printf("\nUebergabe: %s \n", argv[1]);


    return 0;
}
