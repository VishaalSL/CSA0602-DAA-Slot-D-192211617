#include <stdio.h>
#include <stdlib.h>
typedef struct {
    int value;
    int weight;
    double ratio;
} Item;
int compare(const void *a, const void *b) {
    Item *item1 = (Item *)a;
    Item *item2 = (Item *)b;
    if (item1->ratio < item2->ratio) return 1;
    if (item1->ratio > item2->ratio) return -1;
    return 0;
}
double fractionalKnapsack(int capacity, Item items[], int n) {
    qsort(items, n, sizeof(Item), compare);
    int currentWeight = 0;
    double totalValue = 0.0;
    int i;
    for (i = 0; i < n; i++) {
        if (currentWeight + items[i].weight <= capacity) {
            currentWeight += items[i].weight;
            totalValue += items[i].value;
        } else {
            int remain = capacity - currentWeight;
            totalValue += items[i].value * ((double)remain / items[i].weight);
            break;
        }
    }
    return totalValue;
}
int main() {
    int n, capacity;
    printf("Enter the number of items: ");
    scanf("%d", &n);
    Item *items = (Item *)malloc(n * sizeof(Item));
    printf("Enter the capacity of the knapsack: ");
    scanf("%d", &capacity);
    printf("Enter the value and weight of each item:\n");
    int i; 
    for (i = 0; i < n; i++) {
        printf("Item %d - Value: ", i + 1);
        scanf("%d", &items[i].value);
        printf("Item %d - Weight: ", i + 1);
        scanf("%d", &items[i].weight);
        items[i].ratio = (double)items[i].value / items[i].weight;
    }
    double maxValue = fractionalKnapsack(capacity, items, n);
    printf("The maximum value that can be accommodated in the knapsack is: %.2f\n", maxValue);
    free(items);
    return 0;
}

