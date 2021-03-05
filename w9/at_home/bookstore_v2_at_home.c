
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
void checkPrice(const char filename[]);
void menu();

int main(){
	struct Book b2read;
	int opt;
	char filename[] = "144_w9_inventory.txt";
	printf("Welcome to the Book Store\n");
	printf("=========================\n");
	while(1){
		menu();
		printf("Select: ");
		scanf("%d", &opt);
		if(opt == 1){
			displayInventory(filename);
		}
		if(opt == 2){
			addBook(filename, &b2read);
		}
		if(opt == 3){
			checkPrice(filename);
		}
		if(opt == 4){
			printf("The total capital is: $%.2f.\n", calculateCapital(filename));
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
	struct Book book;
	int index = 1;
	while (readRecord(fp, &book)!=-1) {
		if (book._isbn == isbn2find) {
			fclose(fp);
			return index;
		}
		index++;
	}
	fclose(fp);
	return -1;
}

void addBook(const char filename[], struct Book *b2Add){
	FILE *fp = fopen(filename, "r");
	printf("ISBN:");
	scanf("%d", &b2Add->_isbn);
	printf("Title:");
	scanf(" %[^\n]", b2Add->_title);
	printf("Year:");
	scanf("%d", &b2Add->_year);
	printf("Price:");
	scanf("%f", &b2Add->_price);
	printf("Quantity:");
	scanf("%d", &b2Add->_qty);
	int exec = searchInventory(fp, b2Add->_isbn);
	if(exec != -1){
		printf("The book exists in the repository!\n\n");
		return;
	} else {
		fp = fopen(filename, "a+");
		printf("The book is successfully added to the inventory.\n");
		printf("\n");
		fprintf(fp, "\n%d;%f;%d;%d;%s", b2Add->_isbn, b2Add->_price, b2Add->_year, b2Add->_qty, b2Add->_title);
	}
	fclose(fp);
}
void checkPrice(const char filename[]){
	struct Book book;
	FILE *fp = fopen(filename, "r");
	int i;
	int isbn2find;
	printf("Please input the ISBN number of the book:\n\n");
	scanf("%d", &isbn2find); 
	int exec = searchInventory(fp, isbn2find);
	if (exec != -1) {
		fp = fopen(filename, "r");
		for (i = 0; i < exec; i++){
			readRecord(fp, &book);
		}
		printf("Book %d costs $%.2f\n\n", book._isbn, book._price);
	} else {
		printf("The book doesn't exists in the repository!\n");
	}
	fclose(fp);
}