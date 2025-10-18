#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STUDENTS 100
#define NAME_LEN 50
#define DATA_FILE "students.txt"

typedef struct {
    char name[NAME_LEN];
    int id;
    float gpa;
} Student;

// Function prototypes
int load_students(Student arr[]);
void save_students(Student arr[], int count);
void add_student(Student arr[], int *count);
void list_students(Student arr[], int count);

int main(void) {
    Student students[MAX_STUDENTS];
    int count = 0;
    int choice;

    // Load existing data from file using load_students()
    count = load_students(students);
    printf("Loaded %d students from file.\n", count);

    do {
        printf("\n=== Student Management System ===\n");
        printf("1. List students\n");
        printf("2. Add student\n");
        printf("3. Save and Exit\n");
        printf("Select an option: ");
        scanf("%d", &choice);
        getchar(); // clear newline

        switch (choice) {
            case 1:
                list_students(students, count);
                break;
            case 2:
                add_student(students, &count);
                break;
            case 3:
                save_students(students, count);
                printf("Data saved. Goodbye!\n");
                break;
            default:
                printf("Invalid option. Try again.\n");
        }
    } while (choice != 3);

    return 0;
}

// Implement load_students()
int load_students(Student arr[]) {
    FILE *fp = fopen(DATA_FILE, "r");
    int count = 0;
    
    if (fp == NULL) {
        printf("No existing data file found. Starting fresh.\n");
        return 0;
    }
    
    // Read records until EOF or max capacity
    while (count < MAX_STUDENTS && 
           fscanf(fp, "%s %d %f", arr[count].name, &arr[count].id, &arr[count].gpa) == 3) {
        count++;
    }
    
    fclose(fp);
    return count;
}

// Implement save_students()
void save_students(Student arr[], int count) {
    FILE *fp = fopen(DATA_FILE, "w");
    
    if (fp == NULL) {
        printf("Error: Cannot open file for writing!\n");
        return;
    }
    
    // Write all students to file
    for (int i = 0; i < count; i++) {
        fprintf(fp, "%s %d %.2f\n", arr[i].name, arr[i].id, arr[i].gpa);
    }
    
    fclose(fp);
}

// Implement add_student()
void add_student(Student arr[], int *count) {
    if (*count >= MAX_STUDENTS) {
        printf("Error: Maximum student capacity reached!\n");
        return;
    }
    
    Student *s = &arr[*count]; // Pointer to the new student
    
    printf("Enter name: ");
    scanf("%49s", s->name);  // Limit to prevent buffer overflow
    getchar(); // Clear newline
    
    printf("Enter ID: ");
    scanf("%d", &s->id);
    
    printf("Enter GPA: ");
    scanf("%f", &s->gpa);
    
    (*count)++; // Increment student count
    printf("Student added successfully!\n");
}

// Implement list_students()
void list_students(Student arr[], int count) {
    if (count == 0) {
        printf("No students to display.\n");
        return;
    }
    
    printf("\n=== Student List ===\n");
    printf("ID\tName\tGPA\n");
    printf("----------------------\n");
    
    for (int i = 0; i < count; i++) {
        printf("%d\t%s\t%.2f\n", arr[i].id, arr[i].name, arr[i].gpa);
    }
    printf("Total: %d students\n", count);
}