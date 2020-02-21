#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int checkFirstChar;
int usedOption;
int choosedOption;
char *wordToFind;

char characterInFile;
int lowerCaseCounter = 0;
int upperCaseCounter = 0;
char temp[512];
int numberOfWordMatchesInFile = 0;
int programmResult = 0;

int validateUserInput(int firstInputChar, int secondInputChar){
    if (firstInputChar == 45 && secondInputChar == 104){
        return secondInputChar;
    } else if (firstInputChar == 45 && secondInputChar == 98){
        return secondInputChar;
    } else if (firstInputChar == 45 && secondInputChar == 115){
        return secondInputChar;
    } else if (firstInputChar == 45 && secondInputChar == 99){
        return secondInputChar;
    } else {
        printf("\nUsage: ./main.c {-h for help|-b|-s|-c word}\n");
        exit(1);
    }
}
void printHelp(){
    printf("\n====================\t HELPPAGE \t==================\n");
    printf("\nUsage: ./main.c {-h for help|-b|-s|-c word}\n");
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

int wordIsInFile(FILE *file, char *wordWhichIsToFind){
    while(fgets(temp, 512, file) != NULL) {
        if((strstr(temp, wordWhichIsToFind)) != NULL) {
            numberOfWordMatchesInFile++;
        }
    }
    return numberOfWordMatchesInFile;
}

int main(int argc, char *argv[]) {

    checkFirstChar = argv[1][0];
    usedOption = argv[1][1];

    FILE *readFile = fopen("/home/thomas/CLionProjects/Uebung_14_02_2020/characters.txt", "r");
    if (readFile == NULL){
        printf("Readable file not found!\n");
        exit(1);
    }

    FILE *writeFile = fopen("/home/thomas/CLionProjects/Uebung_14_02_2020/result.txt", "w");
    if (writeFile == NULL){
        printf("Writeable file not found!\n");
        exit(1);
    }

    choosedOption = validateUserInput(checkFirstChar, usedOption);

    if (choosedOption == 104){
        printHelp();
    } else if (choosedOption == 98){
        programmResult = countUpperCases(readFile);
        char result[] = "Es befinden sich folgende Anzahl an Grossbuchstaben in der Datei: ";
        fputs(result, writeFile);
        fprintf(writeFile, "%d", programmResult);
        printf("### write result to result.txt ###\n");
    } else if (choosedOption == 115){
        programmResult = countLowerCases(readFile);
        char result[] = "Es befinden sich folgende Anzahl an Kleinbuchstaben in der Datei: ";
        fputs(result, writeFile);
        fprintf(writeFile, "%d", programmResult);
        printf("### write result to result.txt ###\n");
    } else if (choosedOption == 99){
        if (argc > 2){
            wordToFind = argv[2];
        } else {
            printf("\nUsage: ./main.c {-h for help|-b|-s|-c word}\n");
            exit(1);
        }
        programmResult = wordIsInFile(readFile, wordToFind);
        if (programmResult > 0){
            char result[] = "Das Wort befindet sich folgende Anzahl in der Datei: ";
            fputs(result, writeFile);
            fprintf(writeFile, "%d", programmResult);
        } else{
            char result[] = "Das Wort befindet sich nicht in der Datei! ";
            fputs(result, writeFile);
        }
        printf("### write result to result.txt ###\n");
    }


    fclose(readFile);
    fclose(writeFile);
    return 0;
}
