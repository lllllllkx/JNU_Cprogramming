#include <stdio.h>
int main()
{
    int arr[25];
    int i, key, count = 0;
    printf("Enter 25 numbers:\n");
    for(i = 0; i < 25; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("Enter number to search: ");
    scanf("%d", &key);
    for(i = 0; i < 25; i++)
    {
        if(arr[i] == key)
        {
            count++;
        }
    }
    if(count > 0)
    {
        printf("%d appears %d times\n", key, count);
    }
    else
    {
        printf("%d is not present in array\n", key);
    }
    return 0;
}
