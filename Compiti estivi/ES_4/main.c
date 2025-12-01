#include <stdio.h>  // printf(), getchar(), fgets(), fopen(), fclose(), fprintf(), rewind(), scanf()
#include <stdlib.h> // calloc(), free(), exit(), strtol(), remove(), rename()
#include <string.h> // strlen(), strncpy()

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
int give_questionnaire();

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

    // Display menu and get user choice
    printf("1. Add a question\n2. Delete question\n3. Answer the questionnaire\n4. Exit\n");

    // Prompt user for choice
    printf("Choose an option: ");
    // MODIFICATO: Usiamo scanf con uno spazio per consumare eventuali newline residue.
    scanf(" %c", &choice); 
    while (getchar() != '\n')
        ; // Remove \n if in the buffer

    // Call correct function according to the user choice
    switch (choice)
    {
    case '1':
        add_question();
        break;
    case '2':
        delete_question();
        break;
    case '3':
        printf("\n\nYour final score is %d\n\n", give_questionnaire());
        break;
    case '4':
        exit(0);
    default:
        printf("\nInvalid choice, please try again\n");
        break;
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
    char *question = calloc(QUESTION_LENGTH, sizeof(char));

    // Ask user to insert the question
    printf("\nInsert the question (%d letters max): ", QUESTION_LENGTH);
    fgets(question, QUESTION_LENGTH, stdin);

    // Append the question in the file
    fprintf(file_descriptor, "%s", question);
    free(question);

    // -- ANSWERS --
    char answer_id = 'A';
    for (int i = 0; i < RESPONSES; i++)
    {
        char response[ANSWER_LENGTH] = {};
        printf("Insert answer %c (%d letters max): ", answer_id, ANSWER_LENGTH);
        fgets(response, ANSWER_LENGTH, stdin);
        fprintf(file_descriptor, "%c. %s", answer_id, response);
        answer_id++;
    }

    // -- Correct answer --
    printf("\nInsert correct answer for this question: ");
    char correct = getchar() & 0x5F;
    while (getchar() != '\n'); // svuota il buffer
    fprintf(file_descriptor, "%c\n\n", correct);
    // Save changes to file
    fclose(file_descriptor);
    return;
}

/*
Function: delete_question
Description: Previews the questions and ask the user for which question to delete
Input: void
Output: void
*/
void delete_question()
{
    // -- Open file in read mode --
    FILE *file_descriptor = fopen(FILEPATH, "r");
    check_file(file_descriptor);

    // -- Question preview --
    int index = 1;
    char temp_buffer[QUESTION_LENGTH];

    // Iterate through all lines of the file
    while (fgets(temp_buffer, QUESTION_LENGTH, file_descriptor))
    {
        // If longer than 50, abbr with "..."
        if (strlen(temp_buffer) > PREVIEW_LENGTH)
        {
            char temp[PREVIEW_LENGTH + 1];
            strncpy(temp, temp_buffer, PREVIEW_LENGTH);
            temp[PREVIEW_LENGTH] = '\0';
            printf("%d. %s...\n", index, temp);
        }
        else
        {
            printf("%d. %s\n", index, temp_buffer);
        }
        // Skip answers and correct answer
        for (int i = 0; i < 5; i++)
        {
            if (!fgets(temp_buffer, QUESTION_LENGTH, file_descriptor))
            {
                break;
            }
        }
        index++;
    }

    // -- Select answer to delete --
    int to_delete = 0;
    char input_buf[32];
    printf("Enter the number of question to delete (1-%d): ", index - 1);
    if (!fgets(input_buf, sizeof(input_buf), stdin)) {
        printf("Question does not exist!");
        fclose(file_descriptor);
        return;
    }
    to_delete = (int)strtol(input_buf, NULL, 10);

    // Check for input errors
    if (to_delete < 1 || to_delete > index - 1)
    {
        printf("Question does not exist!");
        fclose(file_descriptor);
        return;
    }

    // -- Overwrite the file --
    // Create temp file
    FILE *temp_file_descriptor = fopen("temp.txt", "w");
    check_file(temp_file_descriptor);

    // Go to the beginning of the main file
    rewind(file_descriptor);
    int current_question = 1;
    char line[QUESTION_LENGTH];
    // Iterate on all lines of the file and copy them to the new file only if the current question is not marked to be deleted
    while (fgets(line, QUESTION_LENGTH, file_descriptor))
    {
        if (current_question == to_delete)
        {
            for (int i = 0; i < 5; i++)
            {
                if (!fgets(line, QUESTION_LENGTH, file_descriptor)) break;
            }
        }
        else
        {
            fputs(line, temp_file_descriptor);
            for (int i = 0; i < 5; i++)
            {
                if (fgets(line, QUESTION_LENGTH, file_descriptor))
                {
                    fputs(line, temp_file_descriptor);
                }
                else break;
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

/* Function: give_questionnaire
Description: Prints the questions and checks for the user answers
Input: void
Output: user score
*/
int give_questionnaire()
{
    // -- OPEN FILE --
    FILE *file_descriptor = fopen(FILEPATH, "r");
    check_file(file_descriptor);

    int current_question = 1;
    char line[QUESTION_LENGTH];
    int score = 0;

    while (fgets(line, QUESTION_LENGTH, file_descriptor))
    {
        printf("Question n.%d: %s", current_question, line);

        // Print answers
        for (int i = 0; i < 4; i++)
        {
            fgets(line, ANSWER_LENGTH, file_descriptor);
            printf("%s", line);
        }

        printf("Your answer (A,B,C,D): ");
        char user_answer;
        scanf(" %c", &user_answer);
        user_answer &= 0x5F; // Uppercase masking

        // Read correct answer
        fgets(line, ANSWER_LENGTH, file_descriptor);
        if (user_answer == *line) {
            score++;
            printf("Correct! Your score is %d\n\n", score);
        } else {
            printf("Wrong!\n\n");
        }

        // Skip empty line between questions
        fgets(line, ANSWER_LENGTH, file_descriptor);

        current_question++;
    }
    fclose(file_descriptor);
    return score;
}

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