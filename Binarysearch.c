// Works only on sorted arrays

// Much faster than linear search for large datasets

// Time Complexity: O(log n)
#include <stdio.h>
#include <stdlib.h>
int *MemoryAllocation(int size)
{
    int *p = NULL;
    p = (int *)malloc(size * sizeof(int));
    if (p == NULL)
    {
        printf("Error Allocating Memory");
        exit(1);
    }
    return p;
}
void take_input(int *ptr, int size)
{
    printf("Enter The Element Of Array:");
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &ptr[i]);
    }
}
int binary_Search(int *ptr, int size)
{

    int search_ele;
    printf("Enter The Element to search:");
    scanf("%d", &search_ele);
    int LOW = 0;
    int HIGH = size - 1;
    int mid = (LOW + HIGH) / 2;
    while (LOW <= HIGH)
    {
        int mid = (LOW + HIGH) / 2;
        if (ptr[mid] == search_ele)
        {
            return mid;
        }
        else if (ptr[mid] < search_ele)
        {
            LOW = mid + 1;
        }
        else
        {
            HIGH = mid - 1;
        }
    }
}
int main()
{
    int size;
    printf("Enter The Size of array:");
    scanf("%d", &size);
    int *ptr = MemoryAllocation(size);
    take_input(ptr, size);
    int result = binary_Search(ptr, size);
    if (result != -1)
    {
        printf("the Index found at :%d\n", result);
    }
    else
    {
        printf("Element not found");
    }
    free(ptr);
    ptr = NULL;

    return 0;
}