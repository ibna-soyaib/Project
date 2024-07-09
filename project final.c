#include <stdio.h>
#include <stdlib.h>

#define MAX_ENTRIES 100

// Define a structure for phone book entry
struct PhoneBookEntry
{
    char name[50];
    long long int number;
};

// Function prototypes
void displayPhoneBook(struct PhoneBookEntry phoneBook[], int size);
void addNumber(struct PhoneBookEntry phoneBook[], int *size, long long int number);
void deleteNumber(struct PhoneBookEntry phoneBook[], int *size);

int main()
{
    struct PhoneBookEntry phoneBook[MAX_ENTRIES];
    int size = 0;

    int choice;
    long long int number;

    do
    {
        // Display menu
        printf("\nPhone Book Menu:\n");
        printf("1. Display Phone Book\n");
        printf("2. Add Number\n");
        printf("3. Delete Number\n");
        printf("4. Help\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            displayPhoneBook(phoneBook, size);
            break;
        case 2:
            printf("Enter the number to add: ");
            if (scanf("%lld", &number) != 1)
            {
                printf("Invalid number format. Please enter a valid number.\n");
                while (getchar() != '\n')
                    ; // Clear input buffer
            }
            else
            {
                addNumber(phoneBook, &size, number);
            }
            break;
        case 3:
            deleteNumber(phoneBook, &size);
            break;
        case 4:
            printf("\nPhone Book Help:\n");
            printf("1. To display the phone book, select option 1.\n");
            printf("2. To add a number, select option 2 and enter the number and name.\n");
            printf("3. To delete a number, select option 3.\n");
            printf("4. To exit the program, select option 5.\n");
            break;
        case 5:
            printf("Exiting the program. Goodbye!\n");
            break;
        default:
            printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}

void displayPhoneBook(struct PhoneBookEntry phoneBook[], int size)
{
    if (size == 0)
    {
        printf("Phone Book is empty.\n");
        return;
    }

    printf("\nPhone Book Entries:\n");
    for (int i = 0; i < size; i++)
    {
        printf("%s: %lld\n", phoneBook[i].name, phoneBook[i].number);
    }
}

void addNumber(struct PhoneBookEntry phoneBook[], int *size, long long int number)
{
    if (*size == MAX_ENTRIES)
    {
        printf("Phone Book is full. Cannot add more numbers.\n");
        return;
    }

    // Add the number to the stack (array)
    phoneBook[*size].number = number;

    // Prompt for the name (you can customize this part)
    printf("Enter the name for this number: ");
    scanf("%s", phoneBook[*size].name);

    (*size)++;
    printf("Number added successfully.\n");
}

void deleteNumber(struct PhoneBookEntry phoneBook[], int *size)
{
    if (*size == 0)
    {
        printf("Phone Book is empty. Cannot delete a number.\n");
        return;
    }

    // Delete the number from the queue (array)
    printf("Deleting number: %s - %lld\n", phoneBook[0].name, phoneBook[0].number);

    // Shift the remaining entries to fill the gap
    for (int i = 0; i < *size - 1; i++)
    {
        phoneBook[i] = phoneBook[i + 1];
    }

    (*size)--;
    printf("Number deleted successfully.\n");
}
