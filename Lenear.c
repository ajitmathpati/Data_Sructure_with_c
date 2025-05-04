// lenear seaarch in model way

#include <stdio.h>
#include <stdlib.h>
int *MemoryAllocation(int size)
{
    int *ptr = NULL;
    ptr = (int *)malloc(size * sizeof(int));
    if (ptr == NULL)
    {
        printf("Memoey Allocation is Faild !");
        exit(1);
    }
    printf("The %d  Memoey is Allocated", size);
    return ptr;
}
void takeInput(int *ptr, int size)
{
    printf("\n");
    printf("Enter The Element Of Array:");
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &ptr[i]);
    }
}
int lenearsearch(int *ptr, int size)
{
    int searc_ele;
    printf("Enter The Search Element:");
    scanf("%d", &searc_ele);
    for (int i = 0; i < size; i++)
    {
        if (ptr[i] == searc_ele)
        {
            return i;
        }
    }
    return -1;
}

int main()
{
    int size;
    printf("Enter The size of Array:");
    scanf("%d", &size);
    int *p = MemoryAllocation(size);
    takeInput(p, size);
    int result = lenearsearch(p, size);
    if (result != -1)
    {
        printf("Element Found At Index :%d\n", result);
    }
    else
    {
        printf("Element Not Found");
    }
    free(p);
    p = NULL;
    return 0;
}