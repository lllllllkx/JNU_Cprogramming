#include <stdio.h>
#include <conio.h>

int getDayNumber(int day, int mon, int year);
int getMonthNumber(int mon, int year);
int getYearNumber(int year);
int isLeapYear(int year);
void printCalendar(int mon, int year, int day);

const char *monthNames[] = {
    "", "January", "February", "March", "April", "May", "June",
    "July", "August", "September", "October", "November", "December"
};

int getkey() 
{
    return _getch();
}

int main() 
{
    int year, month;

    printf("Enter month and year£º");
    scanf("%d %d", &month, &year);
	while(1) 
	{
        system("cls");
        int weekStart = getDayNumber(1, month, year);
        printCalendar(month, year, weekStart);
        printf("\nUse arrow keys to navigate, ESC to exit\n");

        int key = getkey();
        if(key == 27) 
		{
            break;
        }
        if(key == 224) 
		{
            key = getkey();
            switch(key) 
			{
                case 72:
                    year++;
                    break;
                case 80:
                    year--;
                    break;
                case 77:
                    month++;
                    if(month > 12) 
					{
                        month = 1;
                        year++;
                    }
                    break;
                case 75:
                    month--;
                    if(month < 1) 
					{
                        month = 12;
                        year--;
                    }
                    break;
            }
        }
    }
    return 0;
}

int getDayNumber(int day, int mon, int year) 
{
    long total = 0;
    int y;
    for(y = 1900; y < year; y++)
    {
        if(isLeapYear(y) == 1)
        {
            total = total + 366;
        }
        else
        {
            total = total + 365;
        }
    }
    int m;
    for(m = 1; m < mon; m++)
    {
        total = total + getMonthNumber(m, year);
    }
    total = total + (day - 1);
    return total % 7;
}

int getMonthNumber(int mon, int year) 
{
    if (mon == 2) 
    {
        if(isLeapYear(year) == 1)
        {
            return 29;
        }
        else
        {
            return 28;
        }
    }
    else if (mon == 4 || mon == 6 || mon == 9 || mon == 11) 
    {
        return 30;
    }
    else 
    {
        return 31;
    }
}

int getYearNumber(int year)
{
    long days = 0;
    int y;
    for(y = 1900; y < year; y++)
    {
        if(isLeapYear(y) == 1)
        {
            days = days + 366;
        }
        else
        {
            days = days + 365;
        }
    }
    return days;
}

int isLeapYear(int year) 
{
    return (year % 400 == 0) || ((year % 4 == 0) && (year % 100 != 0));
}

void printCalendar(int mon, int year, int day) 
{
    printf("\n           %s %d\n", monthNames[mon], year);
    printf("Mon\tTue\tWed\tThu\tFri\tSat\tSun\n");
	int i;
    for (i = 0; i < day; i++) 
    {
        printf("\t");
    }

    int days = getMonthNumber(mon, year);
    int currentWeek = day;

    for (i = 1; i <= days; i++) 
    {
        printf("%d\t", i);
        currentWeek++;
        if (currentWeek > 6) 
        {
            printf("\n");
            currentWeek = 0;
        }
    }
    if (currentWeek != 0) 
    {
        printf("\n");
    }
}
