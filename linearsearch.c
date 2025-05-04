// Linear Search
#include <stdio.h>

#include <stdlib.h>
int LinearSearch(int *ptr, int size, int search_Element)
{
    for (int i = 0; i < size; i++)
    {
        if (ptr[i] == search_Element)
        {
            return i;
        }
    }
    return -1;
}

int main()
{

    int size;
    printf("Enter The Size Of Array:");
    scanf("%d", &size);

    int *ptr = (int *)malloc(size * sizeof(int));
    if (ptr == NULL)
    {
        printf("Memory Allocation is failed !");
        exit(1);
    }

    // Fill array with random numbers
    printf("Filling the array with random numbers: \n");

    for (int i = 0; i < size; i++)
    {
        ptr[i] = rand() % 1000;
    }

    // Display the array contents
    for (int i = 0; i < size; i++)
    {
        printf("index %d,Value %d\n", i, ptr[i]);
    }

    // search the element
    int search_element;
    printf("search the Element :");
    scanf("%d", &search_element);

    // perform Linear Search
    int result = LinearSearch(ptr, size, search_element);
    if (result != -1)
    {
        printf("Element Found At Index %d\n", result);
    }
    else
    {
        printf("Element not found");
    }
    free(ptr);
    ptr = NULL;
    return 0;
}