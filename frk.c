#include <stdio.h>

struct item
{
    int weight;
    int value;
    float ratio;
};

void bubbleSort(struct item items[], int no_items)
{
    struct item temp;
    for (int i = 0; i < no_items - 1; i++)
    {
        for (int j = 0; j < no_items - i - 1; j++)
        {
            if (items[j].ratio < items[j + 1].ratio)
            {
                temp = items[j];
                items[j] = items[j + 1];
                items[j + 1] = temp;
            }
        }
    }
}

int main()
{
    int no_items, capacity;
    printf("Enter number of items: ");
    scanf("%d", &no_items);

    struct item items[no_items];
    int cur_weight = 0, rem_weight;

    printf("Enter capacity of sack: ");
    scanf("%d", &capacity);

    for (int i = 0; i < no_items; i++)
    {
        printf("Enter weight for item %d: ", i + 1);
        scanf("%d", &items[i].weight);
        printf("Enter value for item %d: ", i + 1);
        scanf("%d", &items[i].value);
        printf("\n");

        items[i].ratio = (float)items[i].value / items[i].weight;
    }

    bubbleSort(items, no_items);

    float total_profit = 0.0;
    for (int i = 0; i < no_items; i++)
    {
        rem_weight = capacity - cur_weight;
        if (items[i].weight <= rem_weight)
        {
            cur_weight += items[i].weight;
            total_profit += items[i].value;
        }
        else
        {
            total_profit += items[i].value * ((float)rem_weight / items[i].weight);
            cur_weight = capacity;
            break;
        }
    }

    printf("Maximum profit: %.2f\n", total_profit);
    return 0;
}
