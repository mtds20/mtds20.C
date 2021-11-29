/* Mateus David de Souza
   U93384434
   This program will calculate the snacks´ cost per person in a group of 10 people using information entered by the user.
*/

#include <stdio.h>

int main () {
    int userInput = 0;

    int nOfBoxes = 0;
    int nOfBags = 0;
    int nOfDrinks = 0;
    int nOfPeople = 0;

    double fullPrice = 0;
    double pricePerPerson = 0;
    double pricePerUnit = 0;

    int flag = 1;   // loop variable

    printf("Enter the number of people: ");
    scanf("%d", &nOfPeople);

    printf("\nPlease select from the list: ");
    printf("\n0. Stop selection and see the cost per person,");
    printf("\n1. Energy bars - $3.99 /box,");
    printf("\n2. Candy bars - $2.39 /box,");
    printf("\n3. Chips - $4.79 /bag,");
    printf("\n4. Pretzels - $2.99/bag,");
    printf("\n5. Popcorns - $3.50 /bag,");
    printf("\n6. Energy drinks - $4.99/half dozen\n");

    printf("\n");

    while (flag) {  // the loop will run while flag = 1 (true)

        printf("\nEnter selection: ");    // asking for the input (userInput)
        scanf("%d", &userInput);    // storing the value in the variable

        switch (userInput) {    // getting the fullPrice related to the userInput
            case 1:
                printf("Enter number of boxes: ");
                scanf("%d", &nOfBoxes);
                pricePerUnit = 3.99;
                fullPrice = fullPrice + (pricePerUnit * nOfBoxes);
                break;
            case 2:
                printf("Enter number of boxes: ");
                scanf("%d", &nOfBoxes);
                pricePerUnit = 2.39;
                fullPrice = fullPrice + (pricePerUnit * nOfBoxes);
                break;
            case 3:
                printf("Enter number of bags: ");
                scanf("%d", &nOfBags);
                pricePerUnit = 4.79;
                fullPrice = fullPrice + (pricePerUnit * nOfBags);
                break;
            case 4:
                printf("Enter number of bags: ");
                scanf("%d", &nOfBags);
                pricePerUnit = 2.99;
                fullPrice = fullPrice + (pricePerUnit * nOfBags);
                break;
            case 5:
                printf("Enter number of bags: ");
                scanf("%d", &nOfBags);
                pricePerUnit = 3.50;
                fullPrice = fullPrice + (pricePerUnit * nOfBags);
                break;
            case 6:
                printf("Enter number of drinks as multiples of six (6, 12, 18...): ");
                scanf("%d", &nOfDrinks);
                pricePerUnit = 4.99 / 6;    // half dozen (/6)
                fullPrice = fullPrice + (pricePerUnit * nOfDrinks);
                break;
            case 0:
                flag = 0;   // the loop will stop running since flag is now 0 (false) and not 1
                break;
            default:
                printf("Invalid selection, select from 1 to 6, enter 0 to stop selection\n");
                break;

        }

    }

    pricePerPerson = fullPrice / nOfPeople; // calculating the pricePerPerson
    printf("\nCost per person ($): %.2lf\n", pricePerPerson); // printing the pricePerPerson formatted to 2 decimal digits

    return 0;

}
