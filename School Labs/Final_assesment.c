#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h> // Imports "system("@cls")" and "system("pause")" function

// Data structure for the student record
typedef struct
{
    char first_name[20];
    char last_name[20];
    int grade[2][5];
} student;

// Function prototypes
void menu(int *counter_p);
student create_student_record();
void display_student_records(student *students, int *student_num_p, int *counter_p);
void display_all_student_records(student *students, int *student_num_p, int *counter_p);
void display_class_average(student *students, int *counter_p);

//---------------------------------------------------------------------------------------
//                                      MENU
//---------------------------------------------------------------------------------------

void menu(int *counter_p)
{
    system("@cls");
    printf("\n    Number of students: %d", *counter_p);
    printf("\n\n******************************");
    printf("\n* 1. Create New Record       *");
    printf("\n* 2. See Student Records     *");
    printf("\n* 3. See All Student Records *");
    printf("\n* 4. See Class Average       *");
    printf("\n* 5. Exit                    *");
    printf("\n******************************");
    printf("\n\nEnter your choice: ");
}

//---------------------------------------------------------------------------------------
//                             CREATE STUDENT RECORD
//---------------------------------------------------------------------------------------

student create_student_record()
{
    student newStudent;
    printf("\nWhat is your first name?: ");
    scanf(" %s", newStudent.first_name);

    printf("What is your last name?: ");
    scanf(" %s", newStudent.last_name);

    // Sets the class code number to the corresponding place in grade array
    int course[5] = {121, 323, 434, 234, 111};

    for (int i = 0; i < 5; i++)
    {
        newStudent.grade[0][i] = course[i];
    }

    // Sets the class grades
    printf("Enter the grade for the following class: ");

    for (int i = 0; i < 5; i++)
    {
        printf("\n\n\t%d: ", course[i]);
        scanf(" %d", &newStudent.grade[1][i]);

        if (newStudent.grade[1][i] > 100)
        {
            newStudent.grade[1][i] = 100;
        }
        else if (newStudent.grade[1][i] < 0)
        {
            newStudent.grade[1][i] = 0;
        }
        else
        {
            newStudent.grade[1][i] = newStudent.grade[1][i];
        }
    }
    printf("\n");
    system("pause");
    return newStudent;
}

//---------------------------------------------------------------------------------------
//                             DISPLAY STUDENT RECORDS
//---------------------------------------------------------------------------------------

void display_student_records(student *students, int *student_num_p, int *counter_p)
{
    int student_average = 0;

    printf("What student would you like to see?:");
    scanf(" %d", &*student_num_p);

    // Checks if student record exists
    if (*student_num_p < 1 || *student_num_p > *counter_p)
    {
        printf("\nStudent %d does not exist\n\n", *student_num_p);
        system("pause");
        return;
    }

    printf("\n-----------------------------------");
    printf("\n%d - \t%s %s", *student_num_p, students[*student_num_p - 1].first_name, students[*student_num_p - 1].last_name);
    printf("\n-----------------------------------");
    printf("\n\tClass");
    printf("\tGrade");

    // Prints Class code and Grade percentage
    for (int i = 0; i < 5; i++)
    {
        printf("\n\t%d\t%d%%", students[*student_num_p - 1].grade[0][i], students[*student_num_p - 1].grade[1][i]);

        // Adds all grades together
        student_average += students[*student_num_p - 1].grade[1][i];
    }

    // Divides total grade by 5 to make average
    printf("\n\n\tAverage: %d%%\n\n", student_average /= 5);
    system("pause");
}
//---------------------------------------------------------------------------------------
//                           DISPLAY ALL STUDENT RECORDS
//---------------------------------------------------------------------------------------

void display_all_student_records(student *students, int *student_num_p, int *counter_p)
{
    // Iterate through all student records in the students array
    for (int i = 0; i < *counter_p; i++)
    {
        int student_average = 0;

        printf("\n-----------------------------------");
        printf("\n%d - \t%s %s", i + 1, students[i].first_name, students[i].last_name);
        printf("\n-----------------------------------");
        printf("\n\tClass");
        printf("\tGrade");

        // Prints Class code and Grade percentage
        for (int j = 0; j < 5; j++)
        {
            printf("\n\t%d\t%d%%", students[i].grade[0][j], students[i].grade[1][j]);
            // Adds all grades together
            student_average += students[i].grade[1][j];
        }

        // Calculates and prints average grade for student
        student_average = student_average / 5;
        printf("\n\n\tAverage: %d%%\n\n", student_average);
    }
    system("pause");
}

//---------------------------------------------------------------------------------------
//                             DISPLAY CLASS AVERAGE
//---------------------------------------------------------------------------------------
void display_class_average(student *students, int *counter_p)
{
    // Class average array
    int class_average[5] = {0};
    // Number of students in the class
    int num_students = *counter_p;

    printf("\n\tClass");
    printf("\tGrade");

    // loop through each course
    for (int i = 0; i < 5; i++)
    {
        // Sum the grades for the course for all students
        int course_sum = 0;

        for (int j = 0; j < num_students; j++)
        {
            course_sum += students[j].grade[1][i];
        }

        // Calculate the average grade for the course
        class_average[i] = course_sum / num_students;

        printf("\n\t%d\t%d%%", students[0].grade[0][i], class_average[i]);
    }
    printf("\n\n");
    system("pause");
}

//---------------------------------------------------------------------------------------
//                                      MAIN
//---------------------------------------------------------------------------------------
int main()
{
    student students[5]; // Create an array of 5 students
    int counter = 0;
    int *counter_p;
    counter_p = &counter;

    while (true)
    {
        menu(counter_p);

        int choice;
        int student_num;
        int *student_num_p;
        student_num_p = &student_num;

        scanf(" %d", &choice);

        // Adds new student
        if (choice == 1)
        {
            if (counter >= 5)
            {
                printf("\nYou reached the maximum number of students!\n\n");
                system("pause");
            }
            else
            {
                students[counter] = create_student_record();
                counter++;
            }
        }

        // Displays a student
        else if (choice == 2)
        {
            if (counter != 0)
            {
                display_student_records(students, student_num_p, counter_p);
            }
            else
            {
                printf("\nThere are no students added!\n\n");
                system("pause");
            }
        }

        // Displays all students
        else if (choice == 3)
        {
            if (counter != 0)
            {
                display_all_student_records(students, student_num_p, counter_p);
            }
            else
            {
                printf("\nThere are no students added!\n\n");
                system("pause");
            }
        }

        // Displays class average
        else if (choice == 4)
        {
            if (counter != 0)
            {
                display_class_average(students, counter_p);
            }
            else
            {
                printf("\nThere are no students added!\n\n");
                system("pause");
            }
        }

        else if (choice == 5)
        {
            printf("\n   Good Bye!!! ");
            return false;
        }

        else
        {
            printf("\nThat is not a valid option!\n\n");
            system("pause");
        }
    }
}