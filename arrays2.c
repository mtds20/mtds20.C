/* Mateus David de Souza
   U93384434
   This program will display true if two arrays of same length match when the first one is shifted (n times). Otherwise, it will display false.
*/

#include <stdio.h>

void shift(int arrElements[], int inputArrayLength) {
    int i = 0;
    int x;

    x = arrElements[0]; // storing first element of arrElements

    for(i = 0; i < inputArrayLength - 1; i++)
    {

       arrElements[i] = arrElements[i + 1]; // changing the position of the elements; Ex: [0] to [1], [1] to [2]

    }

    arrElements[inputArrayLength - 1] = x; // updating the last element of the arrElements

}

int main () {
    int inputArrLength = 0;
    int i = 0;  // loop variable
    int j = 0;  // loop variable
    int k = 0;  // loop variable
    int l = 0;  // loop variable
    int count = 0;

    printf("Enter the length of the input array: ");    // asking for the input (inputArrLength)
    scanf("%d", &inputArrLength);   // storing the value in the variable

    int arrElements[inputArrLength];
    int arr2Elements[inputArrLength];

    printf("Enter the elements of the first array: ");  // asking for the input (arrElements)

    for(i = 0; i < inputArrLength; i++)
    {
        scanf("%d", &arrElements[i]); // storing the array elements in arrElements
    }

    printf("Enter the elements of the second array: "); //asking for the input (arr2Elements)

    for(j = 0; j < inputArrLength; j++)
    {
        scanf("%d", &arr2Elements[j]); // storing the array2 elements in arr2Elements
    }

    for(k = 0; k < inputArrLength; k++)
    {
        count = 0;
        shift(arrElements, inputArrLength); // calling the function shift

        for(l = 0; l < inputArrLength; l++)
        {

            if (arrElements[l] == arr2Elements[l]) {    // comparing the elements
                 count++;   // updating the variable
            }

        }

        if (count == inputArrLength) {  // if all the elements are equal
            printf("Output: true");
            break;
        }
        if (k == inputArrLength - 1){   // if it is on the last iteration of the loop
            printf("Output: false");
        }

    }

    return 0;

}
