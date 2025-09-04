#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100

typedef struct Student       // Structure to hold student details
{
    char name[50];
    int roll;
    float marks;
}Student;

Student students[MAX];  // Array to store student records

// Variable for file handling
int count = 0;
const char *filename = "students.dat";

// Function prototypes
void load();
void save();
void addStudent();
void displayAll();
void searchByRoll();

int main() {
    int choice;

    load(); // Load existing data

    while (1) 
    {
        printf("\n--- Student Management System ---\n");
        printf("1. Add Student\n");
        printf("2. Display All Students\n");
        printf("3. Search by Roll Number\n");
        printf("4. Save & Exit\n");
        printf("Enter your choice(1-4): ");
        scanf("%d", &choice);

        switch (choice) // Perform action according to choice
        {
            case 1:
                addStudent();
                break;
            case 2:
                displayAll();
                break;
            case 3:
                searchByRoll();
                break;
            case 4:
                save();
                printf("Data saved.\n");
                exit(0);
            default:
                printf("Invalid choice. Try again.\n");
        }
    }
    return 0;
}

void load()   // Load student data from file
{
    FILE *f = fopen(filename, "rb");
    if (f == NULL) 
    {
        return; // no file yet
    }
    fread(&count, sizeof(int), 1, f);
    fread(students, sizeof(Student), count, f);
    fclose(f);
}

// Save student data to file
void save() 
{
    FILE *f = fopen(filename, "wb");
    if (f == NULL) {
        printf("Error saving file.\n");
        return;
    }
    fwrite(&count, sizeof(int), 1, f);
    fwrite(students, sizeof(Student), count, f);
    fclose(f);
}

// Add a new student
void addStudent() 
{
    if (count >= MAX) 
    {
        printf("Database full. Cannot add more students.\n");
        return;
    }

    Student s;
    printf("Enter roll number: ");
    scanf("%d", &s.roll);

    // Check for duplicate roll number
    for (int i = 0; i < count; i++) 
    {
        if (students[i].roll == s.roll) 
        {
            printf("Error: Roll number already exists.\n");
            return;
        }
    }

    printf("Enter name: ");
    getchar(); // clear newline
    fgets(s.name, sizeof(s.name), stdin); // input name
    s.name[strcspn(s.name, "\n")] = '\0'; // remove newline

    printf("Enter marks: ");
    scanf("%f", &s.marks); // input marks

    students[count++] = s;
    printf("Student added successfully.\n");
}

// Display all students
void displayAll() 
{
    if (count == 0) 
    {
        printf("No records available.\n");
        return;
    }

    printf("\n--- Student Records ---\n");
    for (int i = 0; i < count; i++) 
    {
        printf("Roll: %d | Name: %s | Marks: %.2f\n",students[i].roll, students[i].name, students[i].marks);
    }
}

// Search student by roll number
void searchByRoll() 
{
    int roll;
    printf("Enter roll number to search: ");
    scanf("%d", &roll);

    for (int i = 0; i < count; i++) 
    {
        if (students[i].roll == roll) 
        {
            printf("Record Found: Roll: %d | Name: %s | Marks: %.2f\n",students[i].roll, students[i].name, students[i].marks);
            return;
        }
    }
    printf("No record found with roll number %d.\n", roll);
}

