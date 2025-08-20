#include <stdio.h>  // printf(), getchar()
#include <stdlib.h> // calloc(), free()
#include <string.h> // strlen()

// -- PREFERENCES --
// File path stored as a constant so it can be changed hard coded
#define FILEPATH "questionario.txt"
#define RESPONSES 4
#define QUESTION_LENGTH 500
#define ANSWER_LENGTH 100
#define PREVIEW_LENGTH 50

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
    return 0;
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
        printf("1. Add a question\n2. Delete question\n3. Answer the questionnaire\n4. Exit\n");

        // Prompt user for choice
        printf("Choose an option: ");
        choice = getchar();
        while (getchar() != '\n')
            ; // Remove \n if in the buffer

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

/*
Function: add_question
Description: Add question, possible answers and correct answer to file
Input: Void
Output: Void
*/

void add_question()
{
    // Open file in append mode and check if successfull
    FILE *file_descriptor = fopen(FILEPATH, "a");
    check_file(file_descriptor);

    // -- QUESTION --
    // Declare a dynamic ANSWER_LENGTH chars buffer
    char *question = calloc(ANSWER_LENGTH, sizeof(char));

    // Ask user to insert the question
    printf("\nInsert the question (%d letters max): ", ANSWER_LENGTH);
    fgets(question, ANSWER_LENGTH, stdin);

    // Append the question in the file
    fprintf(file_descriptor, "%s", question);
    free(question);

    // -- ANSWERS --
    for (int i = 0; i < RESPONSES; i++)
    {
        char response[ANSWER_LENGTH] = {};
        printf("Insert response (%d letters max): ", ANSWER_LENGTH);
        fgets(response, ANSWER_LENGTH, stdin);
        fprintf(file_descriptor, "%s", response);
    }

    // -- Correct answer --
    printf("\nInsert correct answer for this question: ");
    fprintf(file_descriptor, "%c\n\n", getchar());

    // Save changes to file
    fclose(file_descriptor);
    return;
}

void delete_question()
{
    // -- Open file in read mode --
    FILE *file_descriptor = fopen(FILEPATH, "r");
    check_file(file_descriptor);

    // -- Question preview --
    int index = 1;
    char temp_buffer[PREVIEW_LENGTH];

    // Iterate trought all lines of the file
    while (fgets(temp_buffer, PREVIEW_LENGTH, file_descriptor))
    {   
        // If longer than 50, abbr with "..."
        if (strlen(temp_buffer) > 50)
        {
            char temp[51];
            strncpy(temp, temp_buffer, 50);
            temp[50] = '\n';
            printf("%d. %s...\n", index, temp);
        }
        else
        {
            printf("%d. %s\n", index, temp_buffer);
        }
        // Skip answers and correct answer
        for (int i = 0; i < 6; i++)
        {
            if (!fgets(temp_buffer, PREVIEW_LENGTH, file_descriptor))
            {
                break;
            }
        }
        index++;
    }

    // -- Select answer to delete --
    int to_delete = 0;
    printf("Enter the number of question to delete (1-%d): ", index - 1);
    scanf("%d", &to_delete);

    // Check for input errors
    if (to_delete < 1 || to_delete > index)
    {
        printf("Question does not exist!");
        return;
    }

    // -- Overwrite the file --
    // Create temp file
    FILE *temp_file_descriptor = fopen("temp.txt", "w");
    check_file(temp_file_descriptor);
    
    // Go to the beginning of the main file
    rewind(file_descriptor);
    int current_question = 1;
    // Biggest line present in the file
    char line[QUESTION_LENGTH];
    // Iterate on all lines of the file and copy them to the new file only if the current question is not marked to be deleted
    while (fgets(line, QUESTION_LENGTH, file_descriptor))
    {
        if (current_question == to_delete)
        {
            for (int i = 0; i < 6; i++)
            {
                fgets(line, QUESTION_LENGTH, file_descriptor);
            }
        }
        else
        {
            for (int i = 0; i < 6; i++)
            {
                if (fgets(line, QUESTION_LENGTH, file_descriptor))
                {
                    fputs(line, temp_file_descriptor);
                }
            }
        }
        current_question++;
    }

    // -- Replace the file --
    fclose(file_descriptor);
    fclose(temp_file_descriptor);
    remove(FILEPATH);
    rename("temp.txt", FILEPATH);
    return;
}

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