/* Mateus David de Souza
   U93384434
   This program will validate an email address read from a file entered by the user if it is a USF email, printing all of the USF emails in the output file.
*/

#include <stdio.h>
#include <string.h>

#define EMAIL_LEN 2000
#define INPUT_LEN 100

int read_line(char* str, int n) {
    int ch, i = 0;
    while((ch = getchar()) != '\n') {
            if(i < n){
                *str++ = ch;
                i++;
            }
    }
    *str = '\0';    // terminates string
    return i;   // number of characters stored
}

int is_USF_email(char *emailAddress) {
    char *output;

    output =  strstr(emailAddress, "usf.edu"); // finding string in emailAddress

    if (output) {
        return 1;
    }
    else {
        return 0;

    }

}


int main () {
    char emailAddress[EMAIL_LEN + 1];
    char inputFile[INPUT_LEN + 1];
    char outputFile[INPUT_LEN + 1];

    FILE *fInput;
    FILE *fOutput;

    printf("Enter input file: ");   // getting input file name
    read_line(inputFile, INPUT_LEN + 1); 

    strcpy(outputFile, "USF_"); // copying string to outputFile
    strcat(outputFile, inputFile);  // copying inputFile to the end of outputFile

    fInput = fopen(inputFile, "r"); // opening file to read it

    if(inputFile == NULL) { // input validation of inputFile
        printf("Error opening file\n");
        return 1;
    }

    fOutput = fopen(outputFile, "w");   // opening outputFile to write

    while(fgets(emailAddress, EMAIL_LEN + 1, fInput) != NULL) { // reading the fInput
        if (is_USF_email(emailAddress) == 1) {  // checking if the function returns true
            fputs(emailAddress, fOutput);   // writing emailAddress to fOutput
        }
    }

    printf("Output file name:  %s", outputFile);

    return 0;

}
