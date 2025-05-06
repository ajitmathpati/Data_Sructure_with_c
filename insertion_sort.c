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
void insertion_sort(int *p, int size)
{
    printf("this is insertion sort:");
    for (int i = 1; i < size; i++)
    {
        int temp = p[i];
        int j = i - 1;
        while (j >= 0 && p[j] > temp)
        {
            p[j + 1] = p[j];
            j--;
        }
        p[j] = temp;
    }
}
void Binary_Search(int *p, int size)
{
    int found = 0;
    int search_Ele;
    printf("Enter The Search Element:");
    scanf("%d", &search_Ele);
    int left = 0, right = size - 1;

    while (left <= right)
    {

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
    if (!found)
    {
        printf("Element not found.\n");
    }
}
void Display(int *p, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf(" %d ", p[i]);
    }
    printf("\n");
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
    insertion_sort(p, size);
    Display(p, size);
    printf("\n");
    Binary_Search(p, size);
    free(p);
    p = NULL;

    return 0;
}