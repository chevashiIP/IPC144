
#include <stdio.h>
#define MAX_TITTLE_SIZE 20
#define MAX_BOOKS 10
struct Book{
        int _isbn;
        float _price;
        int _year;
        char _title[MAX_TITTLE_SIZE];
        int _qty;
};

//Declare Functions
void menu();
void displayInventory(struct Book book[], int *size);
void addBook(struct Book book[], int *size);
int main();

int main(void){
        struct Book book[MAX_BOOKS];
        int size = 0;
        int opt;
        printf("Welcome to the Book Store\n");
        printf("=========================\n");
        while(1){
                menu();
                printf("\n");
                printf("Select: ");
                scanf("%d", &opt);
                if(opt == 1){
                        displayInventory((struct Book*)&book, &size);
                }
                if(opt == 2){
                        addBook((struct Book*)&book, &size);
                }
                if(opt > 3){
                        printf("Invalid input, try again:\n");
                }
                if(opt == 0){
                        printf("Goodbye!\n");
                        return 0;
                }
        }
}

void menu(){
        printf("Please select from the following options:\n");
        printf("1) Display the inventory.\n");
        printf("2) Add a book to the inventory.\n");
        printf("3) Check price.\n");
        printf("0) Exit.\n");
}

void displayInventory(struct Book book[MAX_BOOKS], int *size){
        if(*size > 0){
                printf("\n\n");
                printf("Inventory\n");
                printf("===================================================\n");
                printf("ISBN      Title               Year Price  Quantity\n");
                printf("---------+-------------------+----+-------+--------\n");
                int i;
                for(i = 0; i < *size; i++){
                        printf("%-10.0d%-20s%-5d$%-8.2f%-8d", book[i]._isbn, book[i]._title, book[i]._year, book[i]._price, book[i]._qty);
                        printf("\n");
                }
		printf("===================================================\n");
		printf("\n");
        } else {
                 printf("The inventory is empty!\n");
                 printf("===================================================\n");
                 printf("\n");
        }
}

void addBook(struct Book book[], int *size){
        if(*size== MAX_BOOKS){
                printf("The inventory is full\n");
        }
        if(*size < MAX_BOOKS){
                printf("ISBN:");
                scanf("%d", &book[*size]._isbn);
                printf("Title:");
                scanf("\n%19[0-9a-zA-Z ]", book[*size]._title);
                printf("Year:");
                scanf("%d", &book[*size]._year);
                printf("Price:");
                scanf("%f", &book[*size]._price);
                printf("Quantity:");
                scanf("%d", &book[*size]._qty);
                ++*size;
                printf("The book is successfully added to the inventory.\n\n");
        }
}
