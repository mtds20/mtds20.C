/* Mateus David de Souza
   U93384434
   This program will manage a database of books requested by teachers to libraries, using information entered by the user.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define TITLE_LEN 100
#define NAME_LEN 30
#define ROOM_LEN 20

struct book{
	char title[TITLE_LEN+1];
	char first[NAME_LEN+1];
	char last[NAME_LEN+1];
	char classroom[ROOM_LEN+1];
	double price;
	struct book *next;
};


struct book *add_to_end(struct book *list);
void search(struct book *list);
void print_list(struct book *list);
void clear_list(struct book *list);
int read_line(char str[], int n);

/**********************************************************
 * main: Prompts the user to enter an operation code,     *
 *       then calls a function to perform the requested   *
 *       action. Repeats until the user enters the        *
 *       command 'q'. Prints an error message if the user *
 *       enters an illegal code.                          *
 **********************************************************/
int main(void)
{
  char code;

  struct book *book_list = NULL;
  printf("\nOperation Code: a for adding to the list, s for searching a book"
	  ", p for printing the list; q for quit.\n");
  for (;;) {
    printf("\n------------------------------------------------------------------------------------------------------\n");
    printf("\n Enter operation code: ");
    scanf(" %c", &code);
    while (getchar() != '\n')   /* skips to end of line */
      ;
    switch (code) {
      case 'a': book_list = add_to_end(book_list);
                break;
      case 's': search(book_list);
                break;
      case 'p': print_list(book_list);
                break;
      case 'q': clear_list(book_list);
		return 0;
      default:  printf("Illegal code\n");
    }
    printf("\n");
  }
}

struct book *add_to_end(struct book *list){
    char title[TITLE_LEN+1];
	char first[NAME_LEN+1];
	char last[NAME_LEN+1];
	char classroom[ROOM_LEN+1];

    printf("\n Enter title: ");
    read_line(title, TITLE_LEN);  // reading the title

    printf("\n Enter first name: ");
    read_line(first, NAME_LEN);   // reading the first name

    printf("\n Enter last name:  ");
    read_line(last, NAME_LEN);    // reading the last name

    printf("\n Enter classroom: ");
    read_line(classroom, ROOM_LEN);   // reading the classroom

    struct book *p = list;  // pointer to list
    struct book *q = list;  // pointer to list

    while(p != NULL)
    {
        if((strcmp(p->title,title)==0) && (strcmp(p->first,first)==0) && (strcmp(p->last,last)==0) && (strcmp(p->classroom,classroom)==0)) // if book already exists in the list
        {
            printf("\nBook already exists in the list.\n");
            return list;

        }


    q = p;
    p = p->next;

    }


    struct book *new_node = (struct book*)malloc(sizeof(struct book));  // allocating memory

    strcpy(new_node->title,title);  // copying title into new_node
    strcpy(new_node->first,first);  // // copying first into new_node
    strcpy(new_node->last,last);    // copying last into new_node
    strcpy(new_node->classroom,classroom);  // copying classroom into new_node
    new_node->next = NULL;  // initializing new_node->next

    printf("\n Enter price: ");
    scanf("%lf", &new_node->price); // reading the price

    if(list == NULL)    // if there is nothing in list
    {

    new_node->next = list;
    return new_node;

    }

    q->next = new_node;

    return list;

}

void search(struct book *list){
    char title[TITLE_LEN+1];
    int found = 0;

    printf("\n Enter title: "); // asking for the title
    read_line(title, TITLE_LEN);  // reading the title

    struct book *p = list;  // pointer to list

    while(p != NULL) {
            if(((strcmp(p->title,title) == 0)))    // if title searched is equal to a title in database, print all of the book´s data
            {
                printf("\nTitle : %s \n", p->title);
                printf("First Name: %s \n", p->first);
                printf("Last Name : %s \n", p->last);
                printf("Classroom : %s \n", p->classroom);
                printf("Price : %.2f \n", p->price);
                found = 1;

            }

    p = p->next;

    }

    if(found == 0) {

        printf("\nBook was not found\n");

    }


}


void print_list(struct book *list){ // function to print all of the items of the list

    struct book *p = NULL;

    for(p = list; p != NULL; p = p->next) { // iterating p until NULL pointer, printing all the items

        printf("\nTitle : %s \n", p->title);
        printf("First Name: %s \n", p->first);
        printf("Last Name : %s \n", p->last);
        printf("Classroom : %s \n", p->classroom);
        printf("Price : %.2f \n", p->price);

    }

}
void clear_list(struct book *list){ // function to delete all of the items in the list

    struct book *p = list;  // pointer to list
    struct book *q = list;  // pointer to list

    while(p != NULL)
    {
        q = p;
        p = p->next;
        free(q);    // deallocate memory

    }

}

int read_line(char str[], int n)
{
  int ch, i = 0;

  while (isspace(ch = getchar()))
    ;
  str[i++] = ch;
  while ((ch = getchar()) != '\n') {
    if (i < n)
      str[i++] = ch;

   }
   str[i] = '\0';
   return i;
}
