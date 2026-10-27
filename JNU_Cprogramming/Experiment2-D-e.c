#include <stdio.h>

void prime_factors(int x) 
{
    int factor = 2;
    while (x > 1)
    {
        while (x % factor == 0) 
        {
            printf("%d ", factor);
            x /= factor;
        }
        factor++;
    }
    printf("\n");
}

int main() 
{
    int num;
    printf("Enter an integer number£º\n");
    scanf("%d", &num);
    printf("Prime of %d is£º",num);
    print_prime_factors(num);
    return 0;
}
