/* Mateus David de Souza
   U93384434
   This program will validate a word entered by the user if it meets certain conditions.
*/

#include <stdio.h>

int main () {
    char input = 'm';
    int isValid = 1;
    int checkUpperCase = 0;
    int checkLowerCase = 2;

    printf("Input: ");

    while (input != '\n') {
            input = getchar();

            if (input != 10)
            {
                if ((!(input >= 'A' && input <= 'Z')) && (input < 'a' || input > 'z')) {  // checking if "input" is not valid
                isValid = 0;
            }

            else {
              if (input >= 'A' && input <= 'Z') { // checking if "input" is upper case
                checkUpperCase = 1; // updating the variable
              }
              if (input >= 'a' && input <= 'z') {  // checking if "input" is lower case
                checkLowerCase = 1; // updating the variable
              }

            }

            }

    }

    if (checkUpperCase ==  checkLowerCase) {    // checking if there is only lower case or only upper case
            isValid = 0;
    }

    if (isValid == 1) printf("Output: Valid");
    else printf("Output: Invalid");

    return 0;

}
