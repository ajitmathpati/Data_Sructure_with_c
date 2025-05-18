#include <stdio.h>
#include <stdlib.h>

int *memoryallocation(int size)
{
    int *ptr = (int *)malloc(size * sizeof(int));
    if (ptr == NULL)
    {
        printf("Memory allocation failed !");
        exit(1);
    }
    return ptr;
}
void Take_Input(int size, int *p)
{
    printf("Enter THe Array Element:");
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &p[i]);
    }
}
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
int partition(int *p, int lb, int ub)
{
    int pivot = p[lb];
    int start = lb;
    int end = ub;

    while (start < end)
    {
        while (p[start] <= pivot && start < ub)
        {
            start++;
        }
        while (p[end] > pivot)
        {
            end--;
        }
        if (start < end)
        {
            swap(&p[start], &p[end]);
        }
    }

    swap(&p[lb], &p[end]); // Place pivot at correct position
    return end;
}

void quickSort(int *p, int lb, int ub)
{
    if (lb < ub)
    {
        int loc = partition(p, lb, ub);
        quickSort(p, lb, loc - 1);
        quickSort(p, loc + 1, ub);
    }
}
void printArray(int *p, int size)
{
    printf("Sorted array: ");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", p[i]);
    }
    printf("\n");
}
int main()
{
    int size;
    printf("ENter The Size of Array :");
    scanf("%d", &size);
    int *p = memoryallocation(size);
    Take_Input(size, p);

    quickSort(p, 0, size - 1);
    printArray(p, size);

    free(p);
    p = NULL;

    return 0;
}