// Program_3
// By Tommy Levasseur
// Friday 23

#include <stdio.h>

int main(void)
{
    // creates variables
    int rate;
    int sales_price;
    int cost;
    // user input for the rate
    printf("Enter the rate : ");
    scanf(" %d", &rate);
    // user input for sales price
    printf("Enter the sales_price : ");
    scanf(" %d", &sales_price);
    // user input for cost
    printf("Enter the cost : ");
    scanf(" %d", &cost);
    // Prints the commission
    printf("The commission rate is of %d", rate * (sales_price - cost));
}
