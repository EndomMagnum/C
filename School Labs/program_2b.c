// Program_2b
// By Tommy Levasseur
// Friday 23

#include <stdio.h>

int main(void)
{
    // creates variables for nums
    int first_num;
    int second_num;
    int third_num;
    int fourth_num;
    // user input for num 1
    printf("Enter the first number : ");
    scanf(" %d", &first_num);
    // user input for num 2
    printf("Enter the second number : ");
    scanf(" %d", &second_num);
    // user input for num 3
    printf("Enter the third number : ");
    scanf(" %d", &third_num);
    // user input for num 4
    printf("Enter the fourth number : ");
    scanf(" %d", &fourth_num);
    // print the equation
    printf("%d", (first_num + second_num) * (third_num - fourth_num));
}
