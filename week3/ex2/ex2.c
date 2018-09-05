#include <stdio.h>

void swap(int* a, int* b)
{
    int c = *a;
    *a = *b;
    *b = c;
}

void bubble_sort(int* arr, int size)
{
    for(int i=0;i<size;i++)
    {
        for(int j=0;j<size-1;j++)
        {
            if(arr[j] > arr[j+1])
            {
                swap(&arr[j], &arr[j+1]);
            }
        }
    }
}

int main()
{
    int size = 5;
    int* arr = malloc(size);
    for(int i=0;i<size;i++)
    {
        arr[i] = size - i;
    }
    bubble_sort(arr, size);
    for(int i=0;i<size;i++)
    {
        printf("%d", arr[i]);
    }
    printf("\n");
    system("pause");
}
