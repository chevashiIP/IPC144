//define
#include <stdio.h>
#define MAX_BOOKS 10
#define MAX_TITLE_SIZE 20+1
//struct
struct Book {
	int _isbn;
	float _price;
	int _year;
	int _qty;
	char _title[MAX_TITLE_SIZE];
};
//Functions
int readRecord(FILE *fp, struct Book *b2read);
void displayInventory(const char filename[]);
float calculateCapital(const char filename[]);
int searchInventory(FILE *fp, const int isbn2find);
void addBook(const char filename[], struct Book *b2Add);
void checkPrice(const char filename[], const int isbn2find);
void menu();

int main(){
	int opt;
	printf("Welcome to the Book Store\n");
	printf("=========================\n");
	while(1){
		menu();
		printf("Select: ");
		scanf("%d", &opt);
		if(opt == 1){
			displayInventory("144_w9_inventory.txt");
		}
		if(opt == 2){
		}
		if(opt == 3){
		}
		if(opt == 4){
			printf("The total capital is: $%.2f.\n", calculateCapital("144_w9_inventory.txt"));
		}
		if(opt == 0){
			printf("Goodbye!\n");
			break;
		}
		if(opt > 5 || opt < 0){
			printf("Invalid input, try again:\n");
		}
	}
	return 0;
}

void menu(){
	printf("Please select from the following options:\n");
	printf("1) Display the inventory.\n");
	printf("2) Add a book to the inventory.\n");
	printf("3) Check price.\n");
	printf("4) Calculate total capital of the store.\n");
	printf("0) Exit.\n\n");
}

int readRecord(FILE *fp, struct Book *b2read){
	int rv = 0;
	rv = fscanf(fp, "%d;%f;%d;%d;%[^\n]\n", &b2read->_isbn, &b2read->_price, &b2read->_year, &b2read->_qty, b2read->_title);
	return rv;
}

void displayInventory(const char filename[]){
	struct Book book;
	FILE *fp = fopen(filename, "r");
	printf("\n\nInventory\n");
	printf("===================================================\n");
	printf("ISBN      Title               Year Price  Quantity\n");
	printf("---------+-------------------+----+-------+--------\n");
	while(readRecord(fp, &book) == 5){
		printf("%-10.0d%-20s%-5d$%-8.2f%-8d\n", book._isbn, book._title, book._year, book._price, book._qty);
	}
	printf("===================================================\n\n");
	fclose(fp);
}

float calculateCapital(const char filename[]){
	float total_capital = 0;
	struct Book b2read;
	FILE *fp = NULL;
	fp = fopen(filename, "r");
	while (readRecord(fp, &b2read) == 5){
		total_capital += (b2read._price*b2read._qty);
	}
	return total_capital;
}

int searchInventory(FILE *fp, const int isbn2find){
	int i = 0;
	int exec;
	struct Book b2read;
	rewind(fp);
	while ((exec < 0) && readRecord(fp, &b2read) == 5){
		if (b2read._isbn == isbn2find){
			exec = 1;
		}
		i++;
	}
	return (exec < 0) ? exec : i;
}

void addBook(const char filename[], struct Book *b2Add){
	FILE *fp = NULL;
	int exec;
	fp = fopen(filename, "a+");
	exec = searchInventory(fp, b2Add->_isbn);
	if (exec >= 0) {
		printf("The book exists in the repository!\n\n");
	} else {
		fprintf(fp, "%d;%.2lf;%d;%d;%s\n", b2Add->_isbn, b2Add->_price, b2Add->_year, b2Add->_qty, b2Add->_title);
		printf("The book is successfully added to the inventory.\n\n");
	}
	fclose(fp);
}

void checkPrice(const char filename[], const int isbn2find){
	int exec = -1;
	struct Book b2read;
	FILE *fp = NULL;
	fp = fopen(filename, "r");
	while ((exec < 0) && readRecord(fp, &b2read) == 5){
		if (b2read._isbn == isbn2find){
			exec = 1;
		}
	}
}