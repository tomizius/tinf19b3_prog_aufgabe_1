#include <stdio.h>
#include <string.h>
int usedOption;

void validateUserInput(int inputChar){
    if (inputChar == 104){
        printf("\n\nSie haben die Hilfe gewählt! \n");
    } else if (inputChar == 98){
        printf("\n\nSie haben die Großbuchstaben-Variante gewählt! \n");
    } else if (inputChar == 115){
        printf("\n\nSie haben die Kleinbuchstaben-Variante gewählt! \n");
    } else if (inputChar == 119){
        printf("\n\nSie haben die word-Variante gewählt! \n");
    } else {
        printf("\nUsage: ./main.c {-h for help|-b|-s|-c \"word\"}\n");
    }
}

int main(int argc, char *argv[]) {

    usedOption = argv[1][1];
    validateUserInput(usedOption);

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
