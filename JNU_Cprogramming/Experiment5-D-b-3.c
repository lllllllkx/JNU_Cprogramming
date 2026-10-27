#include <stdio.h>
int main()
{
    int arr[25];
    int i, j, key;
    printf("Enter 25 numbers:\n");
    for(i = 0; i < 25; i++)
    {
        scanf("%d", &arr[i]);
    }
    for(i = 1; i < 25; i++)
    {
        key = arr[i];
        j = i - 1;
        while(j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
    printf("Insertion Sort Result:\n");
    for(i = 0; i < 25; i++)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}
