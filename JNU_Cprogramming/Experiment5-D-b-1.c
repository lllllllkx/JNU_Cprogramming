#include <stdio.h>
int main()
{
    int arr[25];
    int i, j, min_idx, temp;
    printf("Enter 25 numbers:\n");
    for(i = 0; i < 25; i++)
    {
        scanf("%d", &arr[i]);
    }
    for(i = 0; i < 24; i++)
    {
        min_idx = i;
        for(j = i + 1; j < 25; j++)
        {
            if(arr[j] < arr[min_idx])
            {
                min_idx = j;
            }
        }
        temp = arr[i];
        arr[i] = arr[min_idx];
        arr[min_idx] = temp;
    }
    printf("Selection Sort Result:\n");
    for(i = 0; i < 25; i++)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}
