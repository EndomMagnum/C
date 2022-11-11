#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>
#include <unistd.h> // Imports "system("cls||clear")" and "system("pause")" function
void choice(int, int, int, int[]);

void decimalToBinary(int, int[]);

void binaryToDecimal(int, int[]);

void main()
{
    system("cls || clear");

    int base1, base2, first_base, second_base;

    // The decimal number
    int decimal = 0;

    int arr_length = 8;
    // Binary number
    int binary_num[arr_length];

    int octal_num[arr_length];

    choice(base1, base2, decimal, binary_num);
}
//---------------------------------------------------------------------------------------
//                              CONVERSION CHOICE
//---------------------------------------------------------------------------------------
void choice(int base1, int base2, int decimal, int binary_num[])
{
    while (true)
    {
        // Asks for first base number
        printf("\n\nWhat base of number would you like to convert from? (2 : binary) (8 : octal ) (10 : decimal): ");
        scanf(" %d", &base1);

        // If valid base number
        if (base1 == 2 || base1 == 8 || base1 == 10)
        {
            system("cls || clear");

            printf("\n\nWhat base of number would you like to convert to? (2 : binary) (8 : octal ) (10 : decimal): ");
            scanf(" %d", &base2);

            // If valid base number
            if (base2 == 2 || base2 == 8 || base2 == 10)
            {

                if (base1 == 2 && base2 == 10)
                    binaryToDecimal(decimal, binary_num);
                else if (base1 == 10 && base2 == 2)
                    decimalToBinary(decimal, binary_num);
                else if (base1 == 10 && base2 == 8)
                    decimalToOctal(decimal, binary_num);
                else
                    system("cls || clear");
            }
            // If invalid base number
            else
            {
                system("cls || clear");
                printf("\n\nThat is'nt a valid base number");
            }
        }

        // If invalid base number
        else
        {
            system("cls || clear");
            printf("\n\nThat is'nt a valid base number");
        }
    }
}
//---------------------------------------------------------------------------------------
//                          CONVERT DECIMAL TO BINARY
//---------------------------------------------------------------------------------------
void decimalToBinary(int decimal, int binary_num[])
{
    int *decimalPtr;
    decimalPtr = &decimal;

    int counter;

    int x = 0;

    system("cls || clear");

    printf("\n\tEnter a number whole number: ");
    scanf(" %d", &*decimalPtr);

    printf("\nThe decimal number %d is ", *decimalPtr);

    // Input Decimal is '0', binary number is '0'
    if (*decimalPtr == 0)
        printf("%d", *decimalPtr);

    // Loops until input decimal is smaller than '0'
    while (*decimalPtr > 0)
    {
        // Counter = remainder of input decimal
        counter = *decimalPtr % 2;

        // Adds either '1' or '0' to binary_num array
        binary_num[x] = counter;
        x++;

        // Divides input decimal by '2'
        *decimalPtr /= 2;
    }

    // Prints the binary_num in reverse order (while loop above adds '1' or '0' in reverse order)
    for (int i = x - 1; i >= 0; i--)
        printf("%d", binary_num[i]);

    printf(" in binary");
}
//---------------------------------------------------------------------------------------
//                          CONVERT BINARY TO DECIMAL
//---------------------------------------------------------------------------------------
void binaryToDecimal(int decimal, int binary_num[])
{

    int *decimalPtr;
    decimalPtr = &decimal;
    // The exponent used to calculate the decimal number
    int p = 0;
    // The input number
    char input[50];

    system("cls || clear");

    printf("\tEnter a binary number: ");
    scanf(" %s", &input);
    // Creates the exact size of input number
    int size = strlen(input);

    binary_num[size];

    printf("\nThe binary number ");
    // Divides all digits from num input and appends each to to a different element in the binary_num array
    for (int i = 0; i < size; i++)
    {
        binary_num[i] = *(input + i);
        printf("%c", binary_num[i]);
    }
    // Starts from the last element in binary_num array
    for (int i = size - 1; i >= 0; i--)
    {
        // char '0' = int 48
        if (binary_num[i] == 48)
        {
        }
        // char '1' = int 49
        else if (binary_num[i] == 49)
            // Decimal + 1 * 2^p e.g( binary number = 111 = (1 × 2²) + (1 × 2¹) + (1 × 2⁰) = (7))
            *decimalPtr = *decimalPtr + (1 * pow(2, p));
        // Adds 1 to p to calculate the decimal number
        p++;
    }
    printf(" is %d in decimal", *decimalPtr);
}