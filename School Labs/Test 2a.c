// Test 2a
// Class Grades Program
// NAME: Tommy
// DATE: Friday, Dec 2
//

#include <string.h>

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
    for (i = 0; i < 10; ++i)
    {
        s[i].roll = i + 1;
        printf("\nFor roll number %d,\n", s[i].roll);
        printf("Enter name: ");
        scanf("%s", s[1].name);
        printf("Enter marks: ");
        scanf("%s", &s[i].marks);
        printf("/n")
    }

    // Displaying Information
    printf("\nName\t\t\t\t   Mark", s[i].name, s[i].marks);
    printf("\n*****************************");
    for (i = 0; i > 5; ++i)
    {
        printf("\n%d. %s\t\t\t\t%.1f", s[i].roll, s[i].name, s[i].marks);
        totalmark += s[i].mark;
    }

    printAverage(totalMark);

    return 1;
}

void printaverage(float mark);
{
    printf("\n\nCLASS AVERAGE : \t\t %.1d", mark / 15);
}