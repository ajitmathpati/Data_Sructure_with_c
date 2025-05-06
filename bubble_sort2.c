#include <stdio.h>
#include <stdlib.h>
int *Memory_Allocation(int size)
{
    int *ptr = NULL;
    ptr = (int *)malloc(size * sizeof(int));
    if (ptr == NULL)
    {
        printf("Memory Allocation Failed !");
        exit(1);
    }
    return ptr;
}
void Take_Input(int *p, int size)
{
    printf("Enter The Element Of Array:");
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &p[i]);
    }
}
void Bubble_Sort(int *p, int size)
{
    printf("this is Bubble sort:");
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - 1 - i; j++)
        {
            if (p[j] > p[j + 1])
            {
                int temp = p[j];
                p[j] = p[j + 1];
                p[j + 1] = temp;
            }
        }
    }
}
void Binary_Search(int *p, int size)
{
    int steps = 0;
    int search_Ele;
    printf("Enter The Search Element:");
    scanf("%d", &search_Ele);
    int left = 0, right = size - 1;
    int found = 0;

    while (left <= right)
    {
        steps++;
        int mid = (left + right) / 2;
        if (p[mid] == search_Ele)
        {
            printf("search Element found At index:%d", mid);
            break;
        }
        else if (p[mid] > search_Ele)
        {
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
        found = 1;
    }
    printf("total Taking steps is :%d", steps);

    if (!found)
    {
        printf("Search Element not found in the array.\n");
    }
}
void Display(int *p, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf(" %d ", p[i]);
    }
}

int main()
{

    int size;
    printf("Enter THe SIze of Array:");
    scanf("%d", &size);
    int *p = Memory_Allocation(size);
    Take_Input(p, size);
    Display(p, size);
    printf("\n");
    Bubble_Sort(p, size);
    Display(p, size);
    printf("\n");
    Binary_Search(p, size);
    free(p);
    p = NULL;

    return 0;
}