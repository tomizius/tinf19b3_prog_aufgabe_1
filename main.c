#include <stdio.h>
#include <string.h>
int checkFirstChar;
int usedOption;


void validateUserInput(int firstInputChar, int secondInputChar){
    if (firstInputChar == 45 && secondInputChar == 104){
        printf("\n\nSie haben die Hilfe gewählt! \n");
    } else if (firstInputChar == 45 && secondInputChar == 98){
        printf("\n\nSie haben die Großbuchstaben-Variante gewählt! \n");
    } else if (firstInputChar == 45 && secondInputChar == 115){
        printf("\n\nSie haben die Kleinbuchstaben-Variante gewählt! \n");
    } else if (firstInputChar == 45 && secondInputChar == 119){
        printf("\n\nSie haben die word-Variante gewählt! \n");
    } else {
        printf("\nUsage: ./main.c {-h for help|-b|-s|-c \"word\"}\n");
    }
}

int main(int argc, char *argv[]) {

    checkFirstChar = argv[1][0];

    printf("FIRST LETTER %d\n\n", checkFirstChar);

    usedOption = argv[1][1];
    validateUserInput(checkFirstChar, usedOption);

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

    return 0;
}
