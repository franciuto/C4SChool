#include <stdio.h> // printf(), scanf(), fgets()
#include <stdlib.h> // calloc(), free()

// Definizione delle funzioni
void user_id(char *username);
char **add_subjects(int subject_qta);
float **add_grades(int subject_qta, char **subjects, int *grades_per_subject);
void print_grades(char **subjects, float **grades, int *grades_per_subject, int subjects_n);
void free_all(char** subjects, float** grades, int* grades_per_subject, int subject_n);

int main()
{
    char username[40];
    int subject_n;

    user_id(username);
    printf("Registro voti scolastici di: %s", username);

    printf("\nN. Materie: ");
    scanf("%d", &subject_n);

    char **subjects = add_subjects(subject_n);
    int *grades_per_subject = calloc(subject_n, sizeof(int));
    float **grades = add_grades(subject_n, subjects, grades_per_subject);

    print_grades(subjects, grades, grades_per_subject, subject_n);

    free_all(subjects, grades, grades_per_subject, subject_n);

    return 0;
}

// Implementazioni delle funzioni

/*
Funzione: user_id
Descrizione: Chiede all'utente l'username
Input: Riceve l'indirizzo di un buffer statico nel main dove salvare il nome utente
Output: Void
*/
void user_id(char *username)
{
    printf("Inserire username: ");
    fgets(username, 39, stdin);
    return;
}


/*
Funzione: add_subjects
Descrizione: Chiede all'utente di inserire N materie (max 20 char per materia)
Input: N materie
Output: Puntatore ad array di puntatori contenente stringhe di materie
*/
char **add_subjects(int subject_qta)
{
    char **subjects = calloc(subject_qta, sizeof(char *));
    for (int i = 0; i < subject_qta; i++)
    {
        subjects[i] = calloc(20, sizeof(char));
        printf("Materia %d: ", i + 1);
        scanf("%19s", subjects[i]);
    }
    return subjects;
}


/*
Funzione: add_grades
Descrizione: Chiede all'utente quanti voti vuole aggiungere per una determinata materia e gli chiede di inserirli
Input: Numero di materie, array di puntatori a stringhe delle materie, puntatore ad array dinamico dove salvare n. di voti per materia
Output: array di puntatori ad array di float
*/
float **add_grades(int subject_qta, char **subjects, int *grades_per_subject)
{
    float **grades = calloc(subject_qta, sizeof(float *));
    for (int i = 0; i < subject_qta; i++)
    {
        int subject_grades;
        printf("Quanti voti vuoi inserire in %s: ", subjects[i]);
        scanf("%d", &subject_grades);
        grades_per_subject[i] = subject_grades;
        grades[i] = calloc(subject_grades, sizeof(float));
        for (int j = 0; j < subject_grades; j++)
        {
            printf("Inserisci voto %d: ", j + 1);
            scanf("%f", &grades[i][j]);
        }
    }
    return grades;
}

/*
Funzione: print_grades
Descrizione: Stampa voti per ogni materia + media dei voti per materia
Input: Array di puntatori a stringhe di materie, array di puntatori ad array di float (voti), numero di materie
Output: Void
*/
void print_grades(char **subjects, float **grades, int *grades_per_subject, int subjects_n)
{
    for (int i = 0; i < subjects_n; i++)
    {
        printf("\nMateria: %s\n", subjects[i]);
        float somma = 0;
        for (int j = 0; j < grades_per_subject[i]; j++)
        {
            printf("  Voto %d: %.2f\n", j + 1, grades[i][j]);
            somma += grades[i][j];
        }
        printf("  Media: %.2f\n", somma / grades_per_subject[i]);
    }
}

/* 
Functione: free_all
Descrizione: Libera tutta la memoria allocata dinamicamente
Input: memorie da liberare
Output: Void
*/
void free_all(char** subjects, float** grades, int* grades_per_subject, int subject_n) {
    for (int i = 0; i < subject_n; i++) {
        free(subjects[i]);
        free(grades[i]);
    }
    free(subjects);
    free(grades);
    free(grades_per_subject);
}