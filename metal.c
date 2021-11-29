/* Mateus David de Souza
   U93384434
   This program will show how many letters that are in string 2 are also in string 1 using input from the user.
*/

#include <stdio.h>

#define STR_LEN 1000

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

int count(char *string1, char *string2) {
    char *p = string2;  // pointer p to string 2
    int lettersCount = 0;

    while(*string1 != '\0') // loop to each character in string 1
    {
        while(*p != '\0') //  loop to each character in p
        {
            if(*string1 == *p) {    // comparing characters
                lettersCount++; // increasing count
            }
            p++;    // increasing p
        }

        string1++;  // increasing string1
        p = string2;
    }

    return lettersCount;

}

int main () {
    char string1[STR_LEN + 1];

    printf("Enter s1: ");    //asking for the input (string1)
    read_line(string1, 1000);

    char string2[STR_LEN + 1];

    printf("Enter s2: ");    //asking for the input (string2)
    read_line(string2, 1000);

    int matches = count(string1, string2);

    printf("Output: %d", matches);

    return 0;

}
