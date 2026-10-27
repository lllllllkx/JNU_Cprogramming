#include <stdio.h>
int main()
{
    int arr[25];
    int i, j, temp;
    printf("Enter 25 numbers:\n");
    for(i = 0; i < 25; i++)
    {
        scanf("%d", &arr[i]);
    }
    for(i = 0; i < 24; i++)
    {
        for(j = 0; j < 24 - i; j++)
        {
            if(arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    printf("Bubble Sort Result:\n");
    for(i = 0; i < 25; i++)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}
