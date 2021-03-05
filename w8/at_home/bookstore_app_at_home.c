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
void displayInventory(struct Book *book, int *size);
void addBook(struct Book *book, int *size);
void checkPrice(struct Book *book, int *size);
int searchInventory(struct Book *book, int isbn, int *size);

int main(void){
        struct Book book[MAX_BOOKS], *bookPtr = book;
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
                        displayInventory(bookPtr, &size);
                }
                if(opt == 2){
                        addBook(bookPtr, &size);
                }
                if(opt == 3){
                        checkPrice(bookPtr, &size);
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

void displayInventory(struct Book *book, int *size){
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
        } else {
                 printf("The inventory is empty!\n");
        }
        printf("===================================================\n\n");

}

void addBook(struct Book *book, int *size){
        int isbn, id;
	int newQty = 0;
        printf("ISBN:");
        scanf("%d", &isbn);
        id = searchInventory(book, isbn, size);
        if(id >= 0){ //Book Found, Editing
                printf("Quantity:");
                scanf("%d", &newQty);
		book[id]._qty = book[id]._qty + newQty;
                printf("The book exists in the repository, quantity is updated.\n\n");
        }else{ //Book Not Found, Creating
                if(*size <= MAX_BOOKS){
                        book[*size]._isbn = isbn;
                        printf("Quantity:");
                        scanf("%d", &book[*size]._qty);
                        printf("Title:");
                        scanf("\n%19[0-9a-zA-Z ]", book[*size]._title);
                        printf("Year:");
                        scanf("%d", &book[*size]._year);
                        printf("Price:");
                        scanf("%f", &book[*size]._price);
                        ++*size;
                        printf("The book is successfully added to the inventory.\n\n");
                }else{
                        printf("The inventory is full\n");
                }
        }
}

void checkPrice(struct Book *book, int *size){
        int isbn, id;
        printf("Please input the ISBN number of the book:\n\n");
        scanf("%d", &isbn);
        id = searchInventory(book,isbn,size);
        if(id >= 0){
                printf("Book %d costs $%.2f\n\n",book[id]._isbn,book[id]._price);
        }else{
                printf("Book does not exist in the bookstore! Please try again.\n\n");
        }
}

int searchInventory (struct Book *book, int isbn, int *size){
        int i;
        for(i = 0; i < *size; i++){
                //Book Found By ISBN?
                if(isbn == book[i]._isbn){
                        return i;
                }
        }
        //Book Not Found, returning -1
        return -1;
}

