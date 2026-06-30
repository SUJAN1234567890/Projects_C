#include <stdio.h>
#include <string.h>

typedef struct expese
{
    int amount;
    char category[36];
} expense;


int main()
{
    expense e;
    int input;
    int am;
    char cat[36];
    FILE *ptr;

    while (1)
    {
        printf("Choose the Action to perform :\n1. Add an Expense\n2. View All Expenses\n3. Show Total Spent\n4. Exit\n");
        printf("Enter :");
        scanf("%d", &input);
        if (input == 1)
        {
            ptr = fopen("expenses.txt", "a");
            printf("Enter the category :");
            getchar();
            fgets(cat, sizeof(cat), stdin);
            cat[strcspn(cat, "\n")] = 0; //Learn this line
            strcpy(e.category , cat);
            printf("Enter the amount :");
            scanf("%d", &am);
            e.amount = am;
            fprintf(ptr, "%s , %d\n", cat, am);
            fclose(ptr);
        }
        else if (input == 2)
        {
            int amount2;
            char cat2[36];
            ptr = fopen("expenses.txt", "r");
            if (ptr != NULL)
            {
                printf("----The Expenses----\n");
                while (1)
                {
                    if (fscanf(ptr, "%s , %d", cat2, &amount2) == EOF)
                    {
                        break;
                    }
                    printf("%s , %d\n", cat2, amount2);
                }
                fclose(ptr);
                printf("----The END----\n");
            }
            else
            {
                printf("No Expense Recorded Yet. \n");
            }
        }
        else if (input == 3)
        {
            int amount2;
            int total_spent = 0;
            char cat2[36];
            ptr = fopen("expenses.txt", "r");
            if (ptr != NULL)
            {
                while (1)
                {
                    if (fscanf(ptr, "%s , %d", cat2, &amount2) == EOF)
                    {
                        break;
                    }
                    total_spent += amount2;
                }
                fclose(ptr);
                printf("The Total spent is %d\n", total_spent);
            }
            else
            {
                printf("There is no expense");
            }
        }
        else if (input == 4)
        {
            printf("Thanks For using.\n Visit Again");
            break;
        }
    }

    return 0;
}