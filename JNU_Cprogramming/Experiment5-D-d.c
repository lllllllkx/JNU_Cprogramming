#include <stdio.h>
int main()
{
    int arr[25];
    int i;
    int pos = 0, neg = 0, even = 0, odd = 0;
    printf("Enter 25 numbers:\n");
    for(i = 0; i < 25; i++)
    {
        scanf("%d", &arr[i]);
    }
    for(i = 0; i < 25; i++)
    {
        if(arr[i] > 0)
        {
            pos++;
        }
        else if(arr[i] < 0)
        {
            neg++;
        }
        if(arr[i] % 2 == 0)
        {
            even++;
        }
        else
        {
            odd++;
        }
    }
    printf("Positive count: %d\n", pos);
    printf("Negative count: %d\n", neg);
    printf("Even count: %d\n", even);
    printf("Odd count: %d\n", odd);
    return 0;
}
