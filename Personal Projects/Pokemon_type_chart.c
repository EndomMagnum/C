#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <unistd.h> // Imports "system("@cls")" and "system("pause")" function

// Define a structure for the lookup table
struct LookupTableEntry
{
    char *string;
    int integer;
};

// Define the lookup table
struct LookupTableEntry lookup_table[] = {
    {"Normal", 0},
    {"Fire", 1},
    {"Water", 2},
    {"Electric", 3},
    {"Grass", 4},
    {"Ice", 5},
    {"Fighting", 6},
    {"Poison", 7},
    {"Ground", 8},
    {"Flying", 9},
    {"Psychic", 10},
    {"Bug", 11},
    {"Rock", 12},
    {"Ghost", 13},
    {"Dragon", 14},
    {"Dark", 15},
    {"Steel", 16},
    {"Fairy", 17},
};

// define the different types of Pokemon
typedef enum
{
    NORMAL,
    FIRE,
    WATER,
    ELECTRIC,
    GRASS,
    ICE,
    FIGHTING,
    POISON,
    GROUND,
    FLYING,
    PSYCHIC,
    BUG,
    ROCK,
    GHOST,
    DRAGON,
    DARK,
    STEEL,
    FAIRY
} Type;

typedef struct
{
    char *name;
    char *type1;
    char *type2;

} Pokemon;

// Function Prototypes
float singleVsSingleTypeEffects(float type_chart[FAIRY + 1][FAIRY + 1]);
float doubleTypeEffects(float type_chart[FAIRY + 1][FAIRY + 1]);
float singleVsDoubleTypeEffects(float type_chart[FAIRY + 1][FAIRY + 1]);

// define the effectiveness of each type against other types
/*              /*ATTACK*/ /*DEFENSE*/
float type_chart[FAIRY + 1][FAIRY + 1] = {
    /*----NOR--FIR--WAT--ELE--GRA--ICE--FIG--POI--GRO--FLY--PSY--BUG--ROC--GHO--DRA--DAR--STE--FAI*/
    /**/ {1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 0.5, 0.0, 1.0, 1.0, 0.5, 1.0}, // Normal
    /**/ {1.0, 0.5, 0.5, 1.0, 2.0, 2.0, 1.0, 1.0, 1.0, 1.0, 1.0, 2.0, 0.5, 1.0, 0.5, 1.0, 2.0, 1.0}, // Fire
    /**/ {1.0, 2.0, 0.5, 1.0, 0.5, 1.0, 1.0, 1.0, 2.0, 1.0, 1.0, 1.0, 2.0, 1.0, 0.5, 1.0, 1.0, 1.0}, // Water
    /**/ {1.0, 1.0, 2.0, 0.5, 0.5, 1.0, 1.0, 1.0, 0.0, 2.0, 1.0, 1.0, 1.0, 1.0, 0.5, 1.0, 1.0, 1.0}, // Electric
    /**/ {1.0, 0.5, 2.0, 1.0, 0.5, 1.0, 1.0, 0.5, 2.0, 0.5, 1.0, 0.5, 2.0, 1.0, 0.5, 1.0, 0.5, 1.0}, // Grass
    /**/ {1.0, 0.5, 0.5, 1.0, 2.0, 0.5, 1.0, 1.0, 2.0, 2.0, 1.0, 1.0, 1.0, 1.0, 2.0, 1.0, 0.5, 1.0}, // Ice
    /**/ {2.0, 1.0, 1.0, 1.0, 1.0, 2.0, 1.0, 0.5, 1.0, 0.5, 0.5, 0.5, 2.0, 0.0, 1.0, 2.0, 2.0, 0.5}, // Fighting
    /**/ {1.0, 1.0, 1.0, 1.0, 2.0, 1.0, 1.0, 0.5, 0.5, 1.0, 1.0, 1.0, 0.5, 0.5, 1.0, 1.0, 0.0, 2.0}, // Poison
    /**/ {1.0, 2.0, 1.0, 2.0, 0.5, 1.0, 1.0, 2.0, 1.0, 0.0, 1.0, 0.5, 2.0, 1.0, 1.0, 1.0, 2.0, 1.0}, // Ground
    /**/ {1.0, 1.0, 1.0, 0.5, 2.0, 1.0, 2.0, 1.0, 1.0, 1.0, 1.0, 2.0, 0.5, 1.0, 1.0, 1.0, 0.5, 1.0}, // Flying
    /**/ {1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 2.0, 2.0, 1.0, 1.0, 0.5, 1.0, 1.0, 1.0, 1.0, 0.0, 0.5, 1.0}, // Psychic
    /**/ {1.0, 0.5, 1.0, 1.0, 2.0, 1.0, 0.5, 0.5, 1.0, 0.5, 2.0, 1.0, 1.0, 0.5, 1.0, 2.0, 0.5, 0.5}, // Bug
    /**/ {1.0, 2.0, 1.0, 1.0, 1.0, 2.0, 0.5, 1.0, 0.5, 2.0, 1.0, 2.0, 1.0, 1.0, 1.0, 1.0, 0.5, 1.0}, // Rock
    /**/ {0.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 2.0, 1.0, 1.0, 2.0, 1.0, 0.5, 1.0, 1.0}, // Ghost
    /**/ {1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 2.0, 1.0, 0.5, 0.0}, // Dragon
    /**/ {1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 0.5, 1.0, 1.0, 1.0, 2.0, 1.0, 1.0, 2.0, 1.0, 0.5, 1.0, 0.5}, // Dark
    /**/ {1.0, 0.5, 0.5, 0.5, 1.0, 2.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 2.0, 1.0, 1.0, 1.0, 0.5, 2.0}, // Steel
    /**/ {1.0, 0.5, 1.0, 1.0, 1.0, 1.0, 2.0, 0.5, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 2.0, 2.0, 0.5, 1.0}, // Fairy
};

// While user inputs their desired type, it will output all moves weak and strong to it.
float singleVsSingleTypeEffects(float type_chart[FAIRY + 1][FAIRY + 1])
{
    char type_input[9];
    // Used when converting from string to int to relate to typing num
    int type_value = -1;

    bool found = false;

    system("@cls");

    printf("Enter a type: ");
    scanf(" %s", type_input);

    // Search the lookup table for the input string
    for (int i = 0; i < sizeof(lookup_table) / sizeof(struct LookupTableEntry); i++)
    {
        if (strcmp(type_input, lookup_table[i].string) == 0)
        {
            type_value = lookup_table[i].integer;
            found = true;
        }
    }

    // Print all type effectiveness
    if (found)
    {
        printf("\n%s type moves has the following effects on these types:\n", type_input);

        // Attack
        printf("\n\n\t\tATTACK:\n");

        // Prints all types that wont be affected
        printf("\n\t       No Effect\n");
        for (int i = 0; i < 18; i++)
        {
            if (type_chart[type_value][i] == 0.0)
            {
                printf("\n\t      %s - %.1f", lookup_table[i].string, type_chart[type_value][i]);
            }
        }

        printf("\n\n\t-------------------------\n");

        // Prints all types that wont be very effected
        printf("\n\t   Not Very Effective\n");
        for (int i = 0; i < 18; i++)
        {
            if (type_chart[type_value][i] == 0.5)
            {
                printf("\n\t      %s - %.1f", lookup_table[i].string, type_chart[type_value][i]);
            }
        }

        printf("\n\n\t-------------------------\n");

        // Prints all types that will be neutrally effected
        printf("\n\t\tNeutral\n");
        for (int i = 0; i < 18; i++)
        {
            if (type_chart[type_value][i] == 1.0)
            {
                printf("\n\t      %s - %.1f", lookup_table[i].string, type_chart[type_value][i]);
            }
        }

        printf("\n\n\t-------------------------\n");

        // Prints all types that will be super effected
        printf("\n\t     Super Effective\n");
        for (int i = 0; i < 18; i++)
        {
            if (type_chart[type_value][i] == 2.0)
            {
                printf("\n\t      %s - %.1f", lookup_table[i].string, type_chart[type_value][i]);
            }
        }

        printf("\n\n\t-------------------------\n");

        printf("\nThe following type moves have the following effects on %s type pokemon:\n", type_input);

        // Defense
        printf("\n\n\t\tDEFENSE:\n");

        // Prints all types that wont be affected
        printf("\n\t       No Effect\n");
        for (int i = 0; i < 18; i++)
        {
            if (type_chart[i][type_value] == 0.0)
            {
                printf("\n\t      %s - %.1f", lookup_table[i].string, type_chart[i][type_value]);
            }
        }

        printf("\n\n\t-------------------------\n");

        // Prints all types that wont be very effected
        printf("\n\t   Not Very Effective\n");
        for (int i = 0; i < 18; i++)
        {
            if (type_chart[i][type_value] == 0.5)
            {
                printf("\n\t      %s - %.1f", lookup_table[i].string, type_chart[i][type_value]);
            }
        }

        printf("\n\n\t-------------------------\n");

        // Prints all types that will be neutrally effected
        printf("\n\t\tNeutral\n");
        for (int i = 0; i < 18; i++)
        {
            if (type_chart[i][type_value] == 1.0)
            {
                printf("\n\t      %s - %.1f", lookup_table[i].string, type_chart[i][type_value]);
            }
        }

        printf("\n\n\t-------------------------\n");

        // Prints all types that will be super effected
        printf("\n\t    Super Effective\n");
        for (int i = 0; i < 18; i++)
        {
            if (type_chart[i][type_value] == 2.0)
            {
                printf("\n\t      %s - %.1f", lookup_table[i].string, type_chart[i][type_value]);
            }
        }

        printf("\n\n\t-------------------------\n");
    }

    else
    {
        printf("\nType '%s' does not exist or is spelt incorrectly\n", type_input);
    }
}

float doubleTypeEffects(float type_chart[FAIRY + 1][FAIRY + 1])
{
    char type1_input[9];
    char type2_input[9];
    // Used when converting from string to int to relate to typing num
    int type1_value = -1;
    int type2_value = -1;

    bool found = false;

    system("@cls");

    printf("Enter the first type: ");
    scanf(" %s", type1_input);
    printf("Enter the second type: ");
    scanf(" %s", type2_input);

    // Search the lookup table for the input string
    for (int i = 0; i < sizeof(lookup_table) / sizeof(struct LookupTableEntry); i++)
    {
        if (strcmp(type1_input, lookup_table[i].string) == 0)
        {
            type1_value = lookup_table[i].integer;
            found = true;
        }
    }

    for (int i = 0; i < sizeof(lookup_table) / sizeof(struct LookupTableEntry); i++)
    {
        if (strcmp(type2_input, lookup_table[i].string) == 0)
        {
            type2_value = lookup_table[i].integer;
            found = true;
        }
    }

    // Print all type effectiveness
    if (found)
    {
        printf("\nThe following type moves have the following effects on %s/%s type pokemon:\n", type1_input, type2_input);

        printf("\n\n\t\tDEFENSE:\n");

        for (int i = 0; i < 18; i++)
        {
            printf("\n\t      %s - %.1f", lookup_table[i].string, type_chart[i][type1_value] * type_chart[i][type2_value]);
        }
    }

    else
    {
        printf("\nType '%s' does not exist or is spelt incorrectly\n", type1_input);
        printf("\nType '%s' does not exist or is spelt incorrectly\n", type2_input);
    }
}

float singleVsDoubleTypeEffects(float type_chart[FAIRY + 1][FAIRY + 1])
{
    char type_input[9];
    char type1_input[9];
    char type2_input[9];
    // Used when converting from string to int to relate to typing num
    int type_value = -1;
    int type1_value = -1;
    int type2_value = -1;

    bool found = false;

    system("@cls");

    printf("Enter the attacking type: ");
    scanf(" %s", type_input);

    printf("Enter the first defending type: ");
    scanf(" %s", type1_input);
    printf("Enter the second defending type: ");
    scanf(" %s", type2_input);

    // Search the lookup table for the input string
    for (int i = 0; i < sizeof(lookup_table) / sizeof(struct LookupTableEntry); i++)
    {
        if (strcmp(type_input, lookup_table[i].string) == 0)
        {
            type_value = lookup_table[i].integer;
            found = true;
        }
    }

    for (int i = 0; i < sizeof(lookup_table) / sizeof(struct LookupTableEntry); i++)
    {
        if (strcmp(type1_input, lookup_table[i].string) == 0)
        {
            type1_value = lookup_table[i].integer;
            found = true;
        }
    }

    for (int i = 0; i < sizeof(lookup_table) / sizeof(struct LookupTableEntry); i++)
    {
        if (strcmp(type2_input, lookup_table[i].string) == 0)
        {
            type2_value = lookup_table[i].integer;
            found = true;
        }
    }

    // Print all type effectiveness
    if (found)
    {
        printf("\n%s type moves have the following effects:", type_input, type1_input, type2_input);

        printf("\n\n\t\tATTACK:\n");
    }

    else
    {
        printf("\nType '%s' does not exist or is spelt incorrectly\n", type_input);
        printf("\nType '%s' does not exist or is spelt incorrectly\n", type1_input);
        printf("\nType '%s' does not exist or is spelt incorrectly\n", type2_input);
    }
}

void main()
{
    int choice;

    system("@cls");

    printf("\n1 - Print all single type effects on single types");
    printf("\n2 - Print all double type effects");
    printf("\n3 - Print all single type effects on double types");
    printf("\n\nWhat would you like to do?: ");
    scanf(" %d", &choice);

    switch (choice)
    {
    case 1:
        singleVsSingleTypeEffects(type_chart);
        break;

    case 2:
        doubleTypeEffects(type_chart);
        break;
    case 3:
        singleVsDoubleTypeEffects(type_chart);
    default:
        break;
    }
}