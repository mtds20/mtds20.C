/* Mateus David de Souza
   U93384434
   This program will validate a word entered by the user as a command line argument if it meets certain conditions.
*/

#include <stdio.h>
#include <stdlib.h>

int validate(char *input) {
    char *p;
    int isValid = 1;
    int checkUpperCase = 0;
    int checkLowerCase = 2;

    for (p = input; *p != '\0'; p++) {
        if ((!(*p >= 'A' && *p <= 'Z')) && (*p < 'a' || *p > 'z')) {  // checking if "input" is not valid
                isValid = 0;
        }

        else {
                if (*p >= 'A' && *p <= 'Z') { // checking if "input" is upper case
                    checkUpperCase = 1; // updating the variable
                }
                if (*p >= 'a' && *p <= 'z') {  // checking if "input" is lower case
                    checkLowerCase = 1; // updating the variable
                }

        }

    }

    if (checkUpperCase ==  checkLowerCase) {    // checking if there is only lower case or only upper case
            isValid = 0;
    }


    return isValid;

}

int main (int argc, char *argv[]) {
    if (argc != 2) {    // input validation of number of arguments
        printf("Output: Incorrect number of arguments. Usage: ./a.out word");
    }
    else if (argc == 2) {
        if(validate(argv[1]) == 1) {    // checking if input is valid or invalid
            printf("Output: valid");
        }
        else {
            printf("Output: invalid");
        }

    }

    return 0;

}
