/* Mateus David de Souza
   U93384434
   This program will show the Chinese animal sign for a user entered year of birth.
*/

#include <stdio.h>
#include <stdlib.h>

int main () {
 int yearOfBirth;
 int animalSign;

 printf("Enter the year of birth: ");                                    //asking for the input (yearOfBirth)
 scanf("%d", &yearOfBirth);                                             // storing the value in the variable

 if (yearOfBirth <= 0) {                                                // input validation of the year entered
  printf("Invalid input. Please enter a positive number.");
  exit(0);
 }

 animalSign = yearOfBirth % 12; // calculating the remainder since each one corresponds to an animal sign

 switch (animalSign) {          // getting the animal sign related to the remainder result
  case 0:
   printf("\nThe Chinese animal sign for %d is Monkey\n", yearOfBirth);
   break;
  case 1:
   printf("\nThe Chinese animal sign for %d is Rooster\n", yearOfBirth);
   break;
  case 2:
   printf("\nThe Chinese animal sign for %d is Dog\n", yearOfBirth);
   break;
  case 3:
   printf("\nThe Chinese animal sign for %d is Pig\n", yearOfBirth);
   break;
  case 4:
   printf("\nThe Chinese animal sign for %d is Rat\n", yearOfBirth);
   break;
  case 5:
   printf("\nThe Chinese animal sign for %d is Ox\n", yearOfBirth);
   break;
  case 6:
   printf("\nThe Chinese animal sign for %d is Tiger\n", yearOfBirth);
   break;
  case 7:
   printf("\nThe Chinese animal sign for %d is Rabbit\n", yearOfBirth);
   break;
  case 8:
   printf("\nThe Chinese animal sign for %d is Dragon\n", yearOfBirth);
   break;
  case 9:
   printf("\nThe Chinese animal sign for %d is Snake\n", yearOfBirth);
   break;
  case 10:
   printf("\nThe Chinese animal sign for %d is Horse\n", yearOfBirth);
   break;
  case 11:
   printf("\nThe Chinese animal sign for %d is Sheep\n", yearOfBirth);
   break;
  default:
   printf("\nNo zodiac sign");
   break;
 }

 return 0;

 }
