/* Mateus David de Souza
   U93384434
   This program will show the two indices of the array that adds up to the key value using information entered by the user.
*/

#include <stdio.h>

void find_indices(int arrElements[],int inputArrayLength, int keyValue, int *index1, int *index2) {
    int j = 0;  // loop variable
    int k = 0;  // loop variable

    for(j = 0; j < inputArrayLength; j++) {
            for(k = j + 1; k < inputArrayLength; k++) {
                if(arrElements[j] + arrElements[k] == keyValue) {   // comparing the two indices summed with the keyValue
                        *index1 = j;    // storing index1 in j
                        *index2 = k;    // storing index2 in k
                        return;
                }
            }
    }
}

int main () {

    int inputArrLength = 0;
    int j = 0;  // loop variable

    printf("Enter the length of the array: ");    // asking for the input (inputArrLength)
    scanf("%d", &inputArrLength);   // storing the value in the variable

    int arrElements[inputArrLength];

    printf("Enter the elements of the array: ");  // asking for the input (arrElements)

    for(j = 0; j < inputArrLength; j++)
    {
        scanf("%d", &arrElements[j]); //storing the array elements in arrElements
    }

    int keyValue = 0;
    int index1 = 0;
    int index2 = 0;

    printf("Enter the key value: ");    // asking for the input (keyValue)
    scanf("%d", &keyValue);   // storing the value in the variable

    find_indices(arrElements, inputArrLength, keyValue, &index1, &index2);  // calling the function

    printf("Output: %d %d", index1, index2);

    return 0;

}
