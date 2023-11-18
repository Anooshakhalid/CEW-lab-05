// QUESTION 1
#include <stdio.h>

int main() {
    FILE *file;
    char filename[] = "lab5.txt";

    file = fopen(filename, "w");
    if (file == NULL) {
        fprintf(stderr, "Error in creating a file.\n");
        return 1;
    }

    fprintf(file, "Hello, I'm Anoosha Khalid.\n");
    fclose(file);

    file = fopen(filename, "a");
    if (file == NULL) {
        fprintf(stderr, "Unable to open the file in append mode.\n");
        return 1;
    }

    fprintf(file, "I'm student of CIS Department.\n");
    fclose(file);

    file = fopen(filename, "r");
    if (file == NULL) {
        fprintf(stderr, "Unable to open the file.\n");
        return 1;
    }

    char buffer[100];
    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        printf("%s", buffer);
    }

    fclose(file);

    return 0;
}


// QUESTION 2
#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *file;
    char filename[] = "example.txt";

    file = fopen(filename, "r");
    if (file == NULL) {
        fprintf(stderr, "Unable to open the file.\n");
        return 1;
    }

    int wordCount = 0;
    char ch;
    while ((ch = fgetc(file)) != EOF) {
        if (ch == ' ' || ch == '\n' || ch == '\t') {
            wordCount++;
        }
    }
    fclose(file);
    printf("Total number of words: %d\n", wordCount);

    return 0;
}



// QUESTION 3
#include <stdio.h>
#include <stdlib.h>

#define MAX_NAME_LENGTH 50

// Structure to represent a student record
typedef struct {
    char name[MAX_NAME_LENGTH];
    int rollNumber;
    float marks;
} Student;

// Function to add a student record to the file
void addStudentToFile(const char *fileName, const Student *student) {
    FILE *file = fopen(fileName, "a");

    if (file == NULL) {
        perror("Error opening file for appending");
        exit(EXIT_FAILURE);
    }

    fprintf(file, "%s %d %.2f\n", student->name, student->rollNumber, student->marks);

    fclose(file);
}

// Function to display the current student records from the file
void displayStudentRecords(const char *fileName) {
    FILE *file = fopen(fileName, "r");

    if (file == NULL) {
        perror("Error opening file for reading");
        exit(EXIT_FAILURE);
    }

    printf("Student Records:\n");

    Student student;
    while (fscanf(file, "%s %d %f", student.name, &student.rollNumber, &student.marks) == 3) {
        printf("Name: %s, Roll Number: %d, Marks: %.2f\n", student.name, student.rollNumber, student.marks);
    }

    fclose(file);
}

int main() {
    const char *fileName = "students.txt";
    Student student;
    int choice;

    do {
        printf("\nStudent Record Management\n");
        printf("1. Add Student\n");
        printf("2. View Students\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter student name: ");
                scanf("%s", student.name);
                printf("Enter student roll number: ");
                scanf("%d", &student.rollNumber);
                printf("Enter student marks: ");
                scanf("%f", &student.marks);

                addStudentToFile(fileName, &student);
                printf("Student record added.\n");
                break;

            case 2:
                displayStudentRecords(fileName);
                break;

            case 3:
                printf("Exiting program.\n");
                break;

            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }

    } while (choice != 3);

    return 0;
}
