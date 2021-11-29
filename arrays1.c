/* Mateus David de Souza
   U93384434
   This program will show all the integers in range [1,inputArrayLength] that are not in the arrayElements using information entered by the user.
*/

#include <stdio.h>

void find(int arrElements[],int inputArrayLength, int arr2Elements[]) {
    int i = 0;  // loop variable

    printf("Output: ");

    for(i = 0; i < inputArrayLength; i++)
    {
        if (arr2Elements[i] == 0) { // if any array element is equal to 0, print the i + 1
            printf("%d ", i + 1);
        }
        else {
            continue;
        }
    }
}

int main () {

    int inputArrLength = 0;
    int j = 0;  // loop variable
    int k = 0;  // loop variable

    printf("Enter the length of the input array: ");    // asking for the input (inputArrLength)
    scanf("%d", &inputArrLength);   // storing the value in the variable

    int arrElements[inputArrLength];
    int arr2Elements[inputArrLength];

    printf("Enter the elements of the input array: ");  // asking for the input (arrElements)

    for(j = 0; j < inputArrLength; j++)
    {
        scanf("%d", &arrElements[j]); //storing the array elements in arrElements
    }

    for(j = 0; j < inputArrLength; j++)
    {
        for(k = 0; k < inputArrLength; k++) {
            if (j + 1 == arrElements[k]) {
                arr2Elements[j] = 1;    // updating the elements to 1
                break;
            }
            else {
                arr2Elements[j] = 0;    // updating the elements to 0
                continue;
            }
        }
    }

    find(arrElements, inputArrLength, arr2Elements);    // calling the function find

    return 0;

}
