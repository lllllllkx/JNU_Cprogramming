#include <stdio.h>
#include <string.h>
#define MAX_BOOKS 200

struct library 
{
    int acc_num;
    char title[60];
    char author[30];
    float price;
    int flag;
};

struct library lib[MAX_BOOKS];
int total = 0;

void showMenu() 
{
    printf("\n===== Library Management Menu =====\n");
    printf("1. Add book information\n");
    printf("2. Display book information\n");
    printf("3. List all books of given author\n");
    printf("4. List the title of specified book\n");
    printf("5. List the count of books in the library\n");
    printf("6. List the books in accession number order\n");
    printf("7. Exit\n");
    printf("====================================\n");
    printf("Enter your choice: ");
}

void addBook() 
{
    if(total >= MAX_BOOKS) 
	{
        printf("Library storage full!\n");
        return;
    }
    struct library b;
    printf("Enter accession number: ");
    scanf("%d", &b.acc_num);
    getchar();
    printf("Enter book title: ");
    gets(b.title);
    printf("Enter author name: ");
    gets(b.author);
    printf("Enter book price: ");
    scanf("%f", &b.price);
    printf("Enter issue flag(0=not issued,1=issued): ");
    scanf("%d", &b.flag);
    lib[total++] = b;
    printf("Book added successfully!\n");
}

void displayAll() 
{
    int i;
	if(total == 0) 
	{
        printf("No book records!\n");
        return;
    }
    printf("\n%-12s%-25s%-15s%-10s%-8s\n","Acc No.","Title","Author","Price","Issued");
    for(i=0;i<total;i++) 
	{
        printf("%-12d%-25s%-15s%-10.2f%-8d\n",lib[i].acc_num,lib[i].title,lib[i].author,lib[i].price,lib[i].flag);
    }
}

void searchByAuthor() 
{
    int i;
	char auth[30];
    getchar();
    printf("Enter author name to search: ");
    gets(auth);
    int found = 0;
    printf("\nBooks by %s:\n",auth);
    for(i=0;i<total;i++) 
	{
        if(strcmp(lib[i].author,auth)==0) 
		{
            printf("Acc:%d Title:%s Price:%.2f Issued:%d\n",lib[i].acc_num,lib[i].title,lib[i].price,lib[i].flag);
            found = 1;
        }
    }
    if(!found) 
		printf("No books found for this author!\n");
}

void searchByAcc() 
{
    int num,i;
    printf("Enter accession number: ");
    scanf("%d",&num);
    int found = 0;
    for(i=0;i<total;i++) 
	{
        if(lib[i].acc_num == num) 
		{
            printf("Book Title: %s\n",lib[i].title);
            found = 1;
            break;
        }
    }
    if(!found) 
		printf("No book with this accession number!\n");
}

void showCount() 
{
    printf("Total books in library: %d\n",total);
}

void sortByAcc() 
{
    int i,j;
	for(i=0;i<total-1;i++) 
	{
        for(j=0;j<total-1-i;j++) 
		{
            if(lib[j].acc_num > lib[j+1].acc_num) 
			{
                struct library temp = lib[j];
                lib[j] = lib[j+1];
                lib[j+1] = temp;
            }
        }
    }
    printf("Books sorted by accession number:\n");
    displayAll();
}

int main() 
{
    int opt;
    while(1) 
	{
        showMenu();
        scanf("%d",&opt);
        switch(opt) 
		{
            case 1: addBook(); break;
            case 2: displayAll(); break;
            case 3: searchByAuthor(); break;
            case 4: searchByAcc(); break;
            case 5: showCount(); break;
            case 6: sortByAcc(); break;
            case 7: printf("Program exit.\n"); return 0;
            default: printf("Invalid choice, try again!\n");
        }
    }
}
