#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int checkFirstChar;
int usedOption;
int choosedOption;

char characterInFile;
int lowerCaseCounter = 0;
int upperCaseCounter = 0;

int spaceAndReturnCounter = 0;

int programmResult = 0;

int validateUserInput(int firstInputChar, int secondInputChar){
    if (firstInputChar == 45 && secondInputChar == 104){
        return secondInputChar;
    } else if (firstInputChar == 45 && secondInputChar == 98){
        return secondInputChar;
    } else if (firstInputChar == 45 && secondInputChar == 115){
        return secondInputChar;
    } else if (firstInputChar == 45 && secondInputChar == 119){
        return secondInputChar;
    } else {
        printf("\nUsage: ./main.c {-h for help|-b|-s|-c \"word\"}\n");
        exit(1);
    }
}
void printHelp(){
    printf("\n====================\t HELPPAGE \t==================\n");
    printf("\nUsage: ./main.c [Options] \n");
    printf("OPTIONS:\n");
    printf("-b: count all upper cases in the choosed file.\n");
    printf("-s: count all lowercases in the choosed file. \n");
    printf("-c <word>:  check if word is in the file.\n");
    printf("\n====================\t HELPPAGE \t==================\n");
    exit(1);
}

int countUpperCases(FILE *file){
    int lowestCase = 65;
    int biggestUpperCase = 90;
    while((characterInFile = getc(file)) != EOF ) {
        if (characterInFile >= lowestCase && characterInFile <= biggestUpperCase){
            upperCaseCounter++;
        }
    }
    return upperCaseCounter;
}

int countLowerCases(FILE *file){
    int lowestCase = 97;
    int biggestLowerCase = 122;
    while((characterInFile = getc(file)) != EOF ) {
        if (characterInFile >= lowestCase && characterInFile <= biggestLowerCase){
            lowerCaseCounter++;
        }
    }
    return lowerCaseCounter;
}

int wordIsInFile(){

}

int main(int argc, char *argv[]) {

    checkFirstChar = argv[1][0];
    usedOption = argv[1][1];

    FILE *file = fopen("/home/thomas/CLionProjects/Uebung_14_02_2020/characters.txt", "r");
    if (file == NULL){
        printf("Datei nicht gefunden\n");
        exit(1);
    }


    choosedOption = validateUserInput(checkFirstChar, usedOption);

    if (choosedOption == 104){
        printHelp();
    } else if (choosedOption == 98){
        programmResult = countUpperCases(file);
        printf("\nEs befinden sich %d Grossbuchstaben in der Datei.\n", programmResult);
    } else if (choosedOption == 115){
        programmResult = countLowerCases(file);
        printf("\nEs befinden sich %d Kleinbuchstaben in der Datei.\n", programmResult);
    } else if (choosedOption == 119){

    }

    printf("\nFile content:\n");




    printf("\nAnzahl der Characters in der Text-Datei: %i\n", lowerCaseCounter);

    return 0;
}
