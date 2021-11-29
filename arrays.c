/* Mateus David de Souza
   U93384434
   This program will show the duplicated integers of the array using information entered by the user.
*/

#include <stdio.h>

void find_duplicates(int *arrElements,int inputArrayLength, int *outputArr, int *size) {
    int *p = NULL;  // pointer p
    int *q = NULL;  // pointer q

    for(p = arrElements + 1; p < arrElements + inputArrayLength; p++) { // p pointing to arrElements + 1
        int arrElement = *p;    // getting the current element being referenced by pointer p

        for (q = p + 1; q < arrElements + inputArrayLength; q++) {  // q pointing to p + 1
            if(arrElement == *q) {  // checking if element in pointer p is the same as the element in pointer q
                *(outputArr + *(size)) = arrElement;    // storing outputArr + size into arrElement
                *(size) = *(size) + 1;  // incrementing size
                break;
            }
        }
    }
}

int main () {

    int inputArrLength = 0;
    int j = 0;  // loop variable
    int k = 0;  // loop variable

    printf("Enter the length of the array: ");    // asking for the input (inputArrLength)
    scanf("%d", &inputArrLength);   // storing the value in the variable

    int arrElements[inputArrLength];

    printf("Enter the elements of the array: ");  // asking for the input (arrElements)

    for(j = 0; j < inputArrLength; j++)
    {
        scanf("%d", &arrElements[j]); //storing the array elements in arrElements
    }

    int outputArr[inputArrLength/2];
    int size = 0;

    find_duplicates(arrElements, inputArrLength, outputArr, &size);   // calling the function

    printf("Output: ");

    for(k = 0; k < size; k++) {
        printf("%d ", outputArr[k]); // printing the duplicated elements in the output array
    }

    return 0;

}
