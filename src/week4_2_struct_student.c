/*
/*
 * week4_2_struct_basics.c
 * Author: Devansh Chugh
 * Student ID: 241ADB054
 * Description:
 *   Demonstrates defining and using a struct in C.
 *   Defines a 'Student' struct with fields like name, id, and grade.
 *   Creates a few instances and prints their details.
 */

#include <stdio.h>
#include <string.h>

// Define struct Student with fields: name, id, and grade
struct Student {
    char name[50];
    int id;
    float grade;
};

int main(void) {
    // Declare Student variables
    struct Student s1, s2;

    // Assign values manually
    strcpy(s1.name, "Alice Johnson");
    s1.id = 101;
    s1.grade = 89.5;

    strcpy(s2.name, "Devansh Chugh");
    s2.id = 102;
    s2.grade = 94.2;

    // Print struct contents
    printf("Student 1:\n");
    printf("  Name:  %s\n", s1.name);
    printf("  ID:    %d\n", s1.id);
    printf("  Grade: %.2f\n\n", s1.grade);

    printf("Student 2:\n");
    printf("  Name:  %s\n", s2.name);
    printf("  ID:    %d\n", s2.id);
    printf("  Grade: %.2f\n", s2.grade);

    return 0;
}
