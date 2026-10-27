#include <stdio.h>
int main()
{
    int arr[25];
    int i, temp;
    printf("Enter 25 numbers:\n");
    for(i = 0; i < 25; i++)
    {
        scanf("%d", &arr[i]);
    }
    for(i = 0; i < 24; i += 2)
    {
        temp = arr[i];
        arr[i] = arr[i + 1];
        arr[i + 1] = temp;
    }
    printf("Array after swapping odd and even positions:\n");
    for(i = 0; i < 25; i++)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}
