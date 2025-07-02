#include <stdio.h>
#include <conio.h>

int main()
{
    int num_items, capacity, weights[100], profits[100], ratio[100], i, j, remaining_capacity, temp;
    float fraction, solution[100], total_profit = 0, total_weight = 0;
    int comparisons = 0, assignments = 0; // Counters for comparisons and assignments

    printf("Enter the number of items: ");
    scanf("%d", &num_items);

    printf("Enter the capacity of the knapsack: ");
    scanf("%d", &capacity);

    remaining_capacity = capacity;

    for (i = 0; i < num_items; i++)
    {
        solution[i] = 0;
    }

    printf("Enter the weights of items: ");
    for (i = 0; i < num_items; i++)
    {
        printf("\nWeight of item %d = ", i + 1);
        scanf("%d", &weights[i]);
    }

    printf("Enter the profit values of items: ");
    for (i = 0; i < num_items; i++)
    {
        printf("\nProfit of item %d = ", i + 1);
        scanf("%d", &profits[i]);
    }

    for (i = 0; i < num_items; i++)
    {
        ratio[i] = profits[i] / weights[i];
    }

    for (i = 0; i < num_items; i++)
    {
        for (j = 0; j < num_items - 1; j++)
        {
            comparisons++; // Increment comparison counter
            if (ratio[j] < ratio[j + 1])
            {
                temp = ratio[j];
                ratio[j] = ratio[j + 1];
                ratio[j + 1] = temp;

                temp = weights[j];
                weights[j] = weights[j + 1];
                weights[j + 1] = temp;

                temp = profits[j];
                profits[j] = profits[j + 1];
                profits[j + 1] = temp;

                assignments += 3; // Increment assignment counter for the three swaps
            }
        }
    }

    printf("\nThe Table After Sorting based on the Ratio:\n");
    printf("Item:\t");
    for (i = 0; i < num_items; i++)
    {
        printf("%d\t", i + 1);
    }

    printf("\nProfit:\t");
    for (i = 0; i < num_items; i++)
    {
        printf("%d\t", profits[i]);
    }

    printf("\nWeights:\t");
    for (i = 0; i < num_items; i++)
    {
        printf("%d\t", weights[i]);
    }

    printf("\nRatio:\t");
    for (i = 0; i < num_items; i++)
    {
        printf("%d\t", ratio[i]);
    }

    for (i = 0; i < num_items; i++)
    {
        if (weights[i] <= remaining_capacity)
        {
            solution[i] = 1;
            remaining_capacity -= weights[i];
        }
        else if (weights[i] > remaining_capacity)
        {
            break;
        }
    }

    if (i < num_items)
    {
        fraction = (float)remaining_capacity / weights[i];
        solution[i] = fraction;
    }

    printf("\nX = [");
    for (i = 0; i < num_items; i++)
    {
        printf("%.3f, ", solution[i]);
    }
    printf("]");

    for (i = 0; i < num_items; i++)
    {
        total_profit += solution[i] * profits[i];
        total_weight += solution[i] * weights[i];
    }

    printf("\nTotal Profit = %.2f\nTotal Weight = %.2f", total_profit, total_weight);

    printf("\nNumber of Comparisons: %d", comparisons);
    printf("\nNumber of Assignments: %d", assignments);

    getch(); // Wait for a key press before closing the console window
    return 0;
}
