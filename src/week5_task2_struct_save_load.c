#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LEN 50

typedef struct {
    char name[MAX_NAME_LEN];
    int age;
    float gpa;
} Student;

// Function prototypes
void save_student(Student s, const char *filename);
Student load_student(const char *filename);

int main(void) {
    Student s1;
    strcpy(s1.name, "Alice");
    s1.age = 21;
    s1.gpa = 3.75f;

    const char *filename = "student.txt";

    // Call save_student() to save student data to file
    printf("Saving student to file...\n");
    save_student(s1, filename);

    // Call load_student() to read data back into a new struct
    printf("Loading student from file...\n");
    Student loaded_student = load_student(filename);

    // Print loaded data to confirm correctness
    printf("Loaded student: %s, %d, GPA: %.2f\n", 
           loaded_student.name, loaded_student.age, loaded_student.gpa);

    return 0;
}

// Implement save_student()
void save_student(Student s, const char *filename) {
    FILE *fp = fopen(filename, "w");
    
    // Check if file opened successfully
    if (fp == NULL) {
        printf("Error opening file for writing!\n");
        return;
    }
    
    // Write student data to file in format: name age gpa
    fprintf(fp, "%s %d %.2f\n", s.name, s.age, s.gpa);
    
    fclose(fp);
    printf("Student saved successfully.\n");
}

// Implement load_student()
Student load_student(const char *filename) {
    Student s;
    FILE *fp = fopen(filename, "r");
    
    // Check if file opened successfully
    if (fp == NULL) {
        printf("Error opening file for reading!\n");
        // Return empty student if file can't be opened
        strcpy(s.name, "Unknown");
        s.age = 0;
        s.gpa = 0.0f;
        return s;
    }
    
    // Read student data from file
    fscanf(fp, "%s %d %f", s.name, &s.age, &s.gpa);
    
    fclose(fp);
    printf("Student loaded successfully.\n");
    
    return s;
}