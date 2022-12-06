// Test 2a
// Class Grades Program
// NAME: Tommy
// DATE: Friday, Dec 2
//

#include <string.h>
#include <stdio.h>

struct student
{
    char name[50];
    int roll;
    float marks;
} s[5];

int printAverage(float);

int main()
{
    int i;
    float totalMark = 0;

    printf("Enter information of students:\n");

    // storing information
    for (i = 0; i < 5; ++i)
    {
        s[i].roll = i + 1;
        printf("\nFor roll number %d,\n", s[i].roll);
        printf("Enter name: ");
        scanf(" %s", &s[i].name);
        printf("Enter marks: ");
        scanf(" %f", &s[i].marks);
        printf("\n");
    }

    // Displaying Information
    printf("\nName\t\t\tMark");
    printf("\n*****************************");
    for (i = 0; i < 5; ++i)
    {
        printf("\n%d. %s\t\t%.1f", s[i].roll, s[i].name, s[i].marks);
        totalMark += s[i].marks;
    }

    printAverage(totalMark);

    return 1;
}

int printAverage(float totalMark)
{
    printf("\n\nCLASS AVERAGE : \t\t %.1f", totalMark / 5);
}