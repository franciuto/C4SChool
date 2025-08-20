#include <stdio.h> // printf(), getchar()
#include <stdlib.h> // calloc(), free()

// -- PREFERENCES --
// File path stored as a constant so it can be changed hard coded
#define FILEPATH "questionario.txt"
#define responses 4

// Functions
void menu();

void add_question();
void delete_question();
void give_questionnaire();

void check_file(FILE *file_descriptor);

int main()
{
    while (1)
    {
        menu();
    }
}

/*
Function: menu
Description: Displays a menu and calls a function based on user input.
Input: None
Output: Void
*/
void menu()
{
    // Local char variable to store the user choice
    char choice;

    // Repeat until a valid choice is made
    while (1)
    {
        printf("1. Add a question\n2. Delete question\n3. Administer the questionnaire\n4. Exit\n");
        
        // Prompt user for choice
        printf("Choose an option: ");
        choice = getchar();
        while (getchar() != '\n'); // Remove \n if in the buffer
        
        // Call correct function according to the user choice
        switch (choice)
        {
        case '1':
            add_question();
            return;
        case '2':
            delete_question();
            return;
        case '3':
            give_questionnaire();
            return;
        case '4':
            exit(0);
        default:
            printf("\nInvalid choice, please try again\n");
            break;
        }
    }
}

void add_question() {
    // Open file in append mode and check if successfull
    FILE *file_descriptor = fopen(FILEPATH, "a");
    check_file(file_descriptor);

    // -- QUESTION --
    // Declare a dynamic 500 chars buffer
    char* question = calloc(500, sizeof(char));

    // Ask user to insert the question
    printf("\nInsert the question (500 letters max): ");
    fgets(question, 500, stdin);

    // Append the question in the file
    fprintf(file_descriptor, "%s", question);
    free(question);

    // -- RESPONSES --
    for (int i = 0; i < responses; i++)
    {
        char response[100] = {};
        printf("Insert response (100 letters max): ");
        fgets(response, 100, stdin);
        fprintf(file_descriptor, "%s", response);
    }
    
    // Save changes to file
    fclose(file_descriptor);
}
void delete_question() {}
void give_questionnaire() {}

/*
Function: check_file
Description: This function checks if the file descriptor passed through input is valid by comparing it with NULL
Input: FILE Pointer (file descriptor)
Output: Void, if the file descriptor is not valid, the function prints an error and exits with error code 1 the program
*/
void check_file(FILE *file_descriptor)
{
    if (file_descriptor == NULL)
    {
        printf("Error opening file\n");
        exit(1);
    }
}