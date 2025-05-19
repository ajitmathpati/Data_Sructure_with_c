#include <stdio.h>
#include <stdlib.h>
int *Memory_Allocation(int size)
{
    int *ptr = (int *)malloc(size * sizeof(int));
    if (ptr == NULL)
    {
        printf("Memory Allocation nahi hua he");
        exit(1);
    }
    return ptr;
}
void Take_input(int *p, int size)
{
    printf("ENter The Element of Array:");
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
int PARTION_OF_QUICK_SORT(int *p, int lb, int ub)
{
    int PIVOT = p[lb];
    int Start = lb;
    int End = ub;
    while (Start < End)
    {
        while (p[Start] <= PIVOT && Start < End)
        {
            Start++;

            while (p[End] > PIVOT)
            {
                End--;
            }
            if (Start < End)
            {
                swap(&p[Start], &p[End]);
            }
        }
    }
    swap(&p[lb], &p[End]);
    return End;
}

void Quick_sort(int *p, int lb, int ub)
{
    if (lb < ub)
    {
        int index = PARTION_OF_QUICK_SORT(p, lb, ub);
        Quick_sort(p, lb, index - 1);
        Quick_sort(p, index + 1, ub);
    }
}
void Show_Output(int *p, int size)
{
    printf("Quick Sort are:");
    for (int i = 0; i < size; i++)
    {
        printf("%d", p[i]);
    }
}

int main()
{
    int size;
    printf("ENTER  THE SIZE OF ARRAY:");
    scanf("%d", &size);

    int *p = Memory_Allocation(size);
    Take_input(p, size);
    Quick_sort(p, 0, size - 1);
    Show_Output(p, size);
    free(p);
    p = NULL;

    return 0;
}