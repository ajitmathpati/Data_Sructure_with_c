#include <stdlib.h>
#include <stdio.h>
int *MemoryAllocation(int size)
{
    int *p = (int *)malloc(size * sizeof(int));
    ;
    if (p == NULL)
    {
        printf("Memory Allocation failed!");
        exit(1);
    }
    return p;
}

void Take_input(int *ptr, int size)
{
    printf("Enter Elements of Array:");
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &ptr[i]);
    }
}
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
int partition(int *ptr, int lb, int ub)
{
    int pivot = ptr[lb];
    int start = lb;
    int end = ub;
    while (start < end)
    {
        while (ptr[start] <= pivot && start < end)
        {
            start++;
        }
        while (ptr[end] > pivot)
        {
            end--;
        }
        if (start < end)
        {
            swap(&ptr[start], &ptr[end]);
        }
    }
    swap(&ptr[lb], &ptr[end]);
    return end;
}
void quick_sort(int *ptr, int lb, int ub)
{
    if (lb < ub)
    {

        int index = partition(ptr, lb, ub);
        quick_sort(ptr, lb, index - 1);
        quick_sort(ptr, index + 1, ub);
    }
}
void display(int *p, int size)
{
    printf("Quick_Sort Are:");
    for (int i = 0; i < size; i++)
    {

        printf("%d ", p[i]);
    }
}
int main()
{
    int size;
    printf("ENter The Size of Array:");
    scanf("%d", &size);
    int *p = MemoryAllocation(size);
    Take_input(p, size);
    quick_sort(p, 0, size - 1);
    display(p, size);
    free(p);
    p = NULL;

    return 0;
}