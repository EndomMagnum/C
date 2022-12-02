// Lab 8
// By Tommy Levasseur
// Tuesday 22

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h> // Imports "system("cls||clear")" and "system("pause")" function

struct info
{
    char name[20];
    char phone[20];
    char email[20];
    char years[20];
} info;

void menu();
void contactInfo(struct info info);
void seeMyContacts(struct info info[]);
struct info addContact();

void menu()
{
    printf("\n\n1. See My Contacts");
    printf("\n2. Edit My Contact");
    printf("\n3. Exit");
    printf("\n\nEnter your choice: ");
}

void seeMyContacts(struct info info[])
{
    for (int i = 0; i < 5; i++)
    {
        if (info[i].name[0] != '\0' && info[i].email[0] != '\0' && info[i].phone[0] != '\0' && info[i].years[0] != '\0')
        {
            printf("-----------------------------------------------\n");
            printf("Contact Slot %d:\n\n", i + 1);
            contactInfo(info[i]);
        }
        else
        {
        }
    }

    printf("\nPress ENTER to continue...");
    getchar();
    getchar();
    system("cls");
}

void contactInfo(struct info info)
{
    if (info.name[0] == '\0' && info.email[0] == '\0' && info.phone[0] == '\0' && info.years[0] == '\0')
    {
        printf("\n");
    }
    else
    {
        printf("Name:\t\t\t%s", strcmp(info.name, "\0") != 0 ? info.name : "N/A\n");
        printf("Phone:\t\t\t%s", strcmp(info.phone, "\0") != 0 ? info.phone : "N/A\n");
        printf("Email:\t\t\t%s", strcmp(info.email, "\0") != 0 ? info.email : "N/A\n");
        printf("Years friends:\t\t%s\n", strcmp(info.years, "\0") != 0 ? info.years : "N/A");
    }
}

struct info addContact()
{
    system("cls");
    getchar();

    struct info newContact;
    char input[20] = {'\0'};
    printf("Enter the name: ");
    fgets(input, 20, stdin);
    if (strcmp(input, "\n") == 0)
        strcpy(newContact.name, "\0");
    else
        strcpy(newContact.name, input);

    printf("Enter the phone number: ");
    fgets(input, 20, stdin);
    if (strcmp(input, "\n") == 0)
        strcpy(newContact.phone, "\0");
    else
        strcpy(newContact.phone, input);

    printf("Enter the email address: ");
    fgets(input, 20, stdin);
    if (strcmp(input, "\n") == 0)
        strcpy(newContact.email, "\0");
    else
        strcpy(newContact.email, input);

    printf("Enter the amount of years you've been friends: ");
    fgets(input, 20, stdin);
    if (strcmp(input, "\n") == 0)
        strcpy(newContact.years, "\0");
    else
        strcpy(newContact.years, input);

    printf("-----------------------------------------------\n");
    contactInfo(newContact);
    printf("-----------------------------------------------\n");

    printf("\nPress ENTER to continue...");

    getchar();
    system("cls");
    return newContact;
}

void main()
{
    struct info info[5];   // Create an array of 5 contacts
    struct info *p = info; // Create a pointer to the array

    for (int i = 0; i < 5; i++)
    {
        strcpy(info[i].name, "\0");
        strcpy(info[i].phone, "\0");
        strcpy(info[i].email, "\0");
        strcpy(info[i].years, "\0");
    }

    bool run = true;
    while (run == true)
    {
        menu();

        int choice;
        scanf(" %d", &choice);

        if (choice == 1)
            seeMyContacts(info);

        else if (choice == 2)
        {
            printf("\nWhat slot do you want to edit? (1-5): ");
            int slot;
            scanf(" %d", &slot);
            if (slot > 0 && slot < 6)
            {
                info[slot - 1] = addContact();
            }
            else
            {
                printf("Invalid slot number!\n");
            }
        }

        else if (choice == 3)
        {
            run = false;

            printf("\nGoodbye!\n");
        }

        else
        {
            printf("Invalid choice, try again!\n");
        }
    }
}