/* Mateus David de Souza
   U93384434
   This program will read a file ("cars.csv"), and print the top 10 cars with highest city mpg in the output file.
*/

#include <stdio.h>
#include <string.h>

#define MAX_NUM_OF_CARS 6000
#define MAX_NUM_OF_FIELDS 150

struct car {    // declaring structure (car)
    char id[MAX_NUM_OF_FIELDS + 1];
    char classification[MAX_NUM_OF_FIELDS + 1];
    char engineType[MAX_NUM_OF_FIELDS + 1];
    char transmission[MAX_NUM_OF_FIELDS + 1];
    int cityMpg;
    char fuelType[MAX_NUM_OF_FIELDS + 1];
    int highwayMpg;
};

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

int find_highest (struct car list[], int length) { // function to find the highest cityMpg cars
    int i = 0;
    int maximum = 0;

	for(i = 1; i < length; i++) // iterating to find the highest value
	{
		if(list[i].cityMpg > list[maximum].cityMpg)
			maximum = i;
	}
	return maximum;

}

void sort_city_mpg (struct car list[], int length) {    // function to sort the cars with highest cityMpg
    struct car temp;
    int highest = 0;

    highest = find_highest(list, length);   // calling the function find_highest

    if(highest < length - 1)    // sorting
	{
		temp = list[length - 1];
		list[length - 1] = list[highest];
		list[highest] = temp;
	}

	if(length > 1)
		sort_city_mpg(list, length - 1);
}

int main() {
    struct car cars[MAX_NUM_OF_CARS];
    char inputFile[MAX_NUM_OF_CARS + 1];
    int i = 0;  // loop variable
    int j = 0;  // loop variable

    FILE *fInput;
    FILE *fOutput;

    printf("Enter the file name: ");   // getting input file name
    read_line(inputFile, MAX_NUM_OF_CARS + 1);

    fInput = fopen(inputFile, "r"); // opening file and reading

    if(fInput == NULL) { // input validation of fInput
        printf("Error opening file\n");
        return 1;
    }

    while(!feof(fInput) && !ferror(fInput)) // reading through the file
	{
		fscanf(fInput, "%[^,], %[^,], %[^,], %[^,], %d, %[^,], %d\n" , cars[i].id, cars[i].classification, cars[i].engineType, cars[i].transmission, &cars[i].cityMpg, cars[i].fuelType, &cars[i].highwayMpg);
		i++;
	}

	sort_city_mpg(cars, i); // calling the function

	fOutput = fopen("Top10_city_mpg.csv", "w"); // opening file and writing

	if(fOutput == NULL) { // input validation of fOutput
        printf("Error opening file\n");
        return 1;
    }

    printf("Output file name:");
    printf("\nTop10_city_mpg.csv");

	for(j = i - 1; j > i - 11; j--) // looping to print all the info from the 10 cars with the highest cityMpg
	{
		printf("%s, %s, %s, %s, %d, %s, %d\n" , cars[j].id, cars[j].classification, cars[j].engineType, cars[j].transmission, cars[j].cityMpg, cars[j].fuelType, cars[j].highwayMpg);
		fprintf(fOutput, "%s, %s, %s, %s, %d, %s, %d\n" , cars[j].id, cars[j].classification, cars[j].engineType, cars[j].transmission, cars[j].cityMpg, cars[j].fuelType, cars[j].highwayMpg);
	}

	fclose(fInput);
	fclose(fOutput);

    return 0;

}
