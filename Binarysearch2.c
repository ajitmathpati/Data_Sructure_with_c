// Binary Search 2 method
#include <stdio.h>
#include <stdlib.h>
int *MemoryAllocation(int size)
{
    int *ptr = NULL;
    ptr = (int *)malloc(size * sizeof(int));
    if (ptr == NULL)
    {
        printf("Error Allocating Memory");
        exit(1);
    }
    return ptr;
}
void take_Input(int *ptr, int size)
{
    printf("Enter The Element Of Array:");
    for (int i = 0; i < size; i++)
    {

        scanf("%d", &ptr[i]);
    }
}
void BinarySearch(int *p, int size)
{
    int count = 0;
    int left = 0;
    int right = size - 1;
    int search_ele;
    printf("Enter The  Search Element:");

    scanf("%d", &search_ele);
    while (left <= right)
    {
        count++;
        int mid = (left + right) / 2;
        if (p[mid] == search_ele)
        {
            printf("element is found :%d\n", mid);
            break;
        }
        else if (search_ele > p[mid])
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
    printf("total count:%d", count);
}
int main()
{
    int size;
    printf("Enter The Size of Array:");
    scanf("%d", &size);
    int *p = MemoryAllocation(size);
    take_Input(p, size);
    BinarySearch(p, size);
    free(p);
    p = NULL;

    return 0;
}