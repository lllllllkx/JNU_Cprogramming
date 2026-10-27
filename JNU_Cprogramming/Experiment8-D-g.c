#include <stdio.h>

struct Date 
{
    int day;
    int month;
    int year;
};

int main() 
{
    struct Date d1, d2;
    printf("Enter first date (day month year): ");
    scanf("%d %d %d", &d1.day, &d1.month, &d1.year);
    printf("Enter second date (day month year): ");
    scanf("%d %d %d", &d2.day, &d2.month, &d2.year);
    if(d1.day == d2.day && d1.month == d2.month && d1.year == d2.year) 
	{
        printf("Equal\n");
    } else 
	{
        printf("Unequal\n");
    }
    return 0;
}
