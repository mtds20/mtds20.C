/* Mateus David de Souza
   U93384434
   This program will show the parking charges of a garage using information entered by the user.
*/

#include <stdio.h>
#include <stdlib.h>

int main () {
 int hoursParked;
 int minutesParked;
 int additionalMinutes;
 int daysParked;
 int amountDue;

 amountDue = 0;

 printf("Enter hours parked: ");  // getting the value of hoursParked
 scanf("%d", &hoursParked);

 printf("Enter minutes parked: "); // getting the value of minutesParked
 scanf("%d", &minutesParked);

 if (hoursParked < 0) { // input validation of hoursParked
    printf("Invalid input.");
    exit(0);
 } else if (minutesParked > 60 || minutesParked < 0) {  // input validation of minutesParked
    printf("Invalid input.");
    exit(0);
 }

 minutesParked = minutesParked + (hoursParked * 60); // converting hours to minutes and storing in minutesParked variable
 minutesParked = minutesParked - 30; // updating minutesParked variable


 if (minutesParked > 0) {
    daysParked = minutesParked / 1440; // checking the number of daysParked

    amountDue = amountDue + (daysParked * 12); // updating amountDue variable
    minutesParked = minutesParked % 1440;

    additionalMinutes = minutesParked / 20; // checking how many additional minutes exists in the last day

    if (additionalMinutes >= 12) {  // updating amountDue variable (maximum 12 dollars a day)
        amountDue = amountDue + 12;
    } else {
        amountDue = amountDue + additionalMinutes;
        if (minutesParked % 20 != 0) {
                amountDue++;

        }
    }
 }

 printf("Amount due ($): $%d", amountDue);

 return 0;
}
