
//defines
#include <stdio.h>
#include <stdlib.h>
#define LINEAR 1
#define FORM 0
#define STOCK 1
#define CHECKOUT 0
#define MAX_ITEM_NO 500
#define MAX_QTY 999
#define SKU_MAX 999
#define SKU_MIN 100
#define DATAFILE "items.txt"

//Structure
struct Item {
	double price;
	int sku;
	int yesopt;
	int quantity;
	int minQuantity;
	char name[21];
};

//Functions declaration
void welcome(void);
void printTitle(void);
void printFooter(double grandTotal);
void flushKeyboard(void);
void pause(void);
int getInt(void);
int getIntLimited(int lowerLimit, int upperLimit);
double getDouble(void);
double getDoubleLimited(double lowerLimit, double upperLimit);
int yes(void);
int menu(void);
void GroceryInventorySystem(void);
double totalAfterTax(struct Item item);
int isLowQuantity(struct Item item);
struct Item itemEntry(int sku);
void displayItem(struct Item item, int linear);
void listItems(const struct Item item[], int noOfItems);
int locateItem(const struct Item item[], int NoOfRecs, int sku, int* index);
void search(const struct Item item[], int NoOfRecs);
void updateItem(struct Item* itemptr);
void addItem(struct Item item[], int *NoOfRecs, int sku);
void addOrUpdateItem(struct Item item[], int* NoOfRecs);
void adjustQuantity(struct Item item[], int NoOfRecs, int stock);
void saveItem(struct Item item, FILE* dataFile);
int loadItem(struct Item* item, FILE* dataFile);
int saveItems(struct Item* item, char fileName[], int NoOfRecs);
int loadItems(struct Item* item, char fileName[], int* NoOfRecsPtr);

const double TAX = 0.13;
//main program//
int main(void){
	GroceryInventorySystem();
	return 0;
}

// PROGRAM HEART // 
void GroceryInventorySystem(void){
	struct Item Items[MAX_ITEM_NO];
	int opt, records;
	int loop = 0;
	welcome();
	printf("\n");
	while(!loop){
		if(0 == loadItems(Items, DATAFILE, &records)){
			printf("Could not read from %s.\n", DATAFILE);
			break;
		}
		opt = menu();
		if(opt == 0){
			printf("Exit the program? (Y)es/(N)o): ");
			loop = yes();
		}
		if(opt == 1){
			listItems(Items, records);
			if(0 == saveItems(Items, DATAFILE, records)){
                printf("Could not update data file %s\n", DATAFILE);
            }
			pause();
		}
		if(opt == 2){
			search(Items, records);
			if(0 == saveItems(Items, DATAFILE, records)){
                printf("Could not update data file %s\n", DATAFILE);
            }
			pause();
		}
		if(opt == 3){
			adjustQuantity(Items, records, CHECKOUT);
            if(0 == saveItems(Items, DATAFILE, records)){
                printf("Could not update data file %s\n", DATAFILE);
            }
			pause();
		}
		if(opt == 4){            
			adjustQuantity(Items, records, STOCK);
            if(0 == saveItems(Items, DATAFILE, records)){
                printf("Could not update data file %s\n", DATAFILE);
            }
			pause();
		}
		if(opt == 5){
			addOrUpdateItem(Items, &records);
            if(0 == saveItems(Items, DATAFILE, records)){
                printf("Could not update data file %s\n", DATAFILE);
            }
			pause();
		}
		if(opt == 6){
			printf("Not implemented!\n");
			pause();
		}
		if(opt == 7){
			printf("Not implemented!\n");
			pause();
		}
	}
}
//==========// 

// Milestone 1//
void welcome(void){
	printf("---=== Grocery Inventory System ===---");
	printf("\n");
}
void printTitle(void){
	printf("Row |SKU| Name               | Price  |Taxed| Qty | Min |   Total    |Atn\n");
	printf("----+---+--------------------+--------+-----+-----+-----+------------|---\n");
}
void printFooter(double grandTotal){
	printf("--------------------------------------------------------+----------------\n");
	if(grandTotal > 0){
		printf("                                           Grand Total: |%12.2lf\n", grandTotal);
	}
}

void flushKeyboard(void){ // Checks if user pressed enter //
	char option;
	while (scanf("%c", &option)) {
		if (option == '\n') {   						
			break;
		}
	}
}

void pause(void){
	printf("Press <ENTER> to continue..."); // Prints message before checking if user pressed Enter // 
	flushKeyboard();
}

int yes(void) {
    char yesopt;
    scanf("%s", &yesopt);
	flushKeyboard();
    do {
        if (yesopt == 'Y' || yesopt == 'y') {
            return 1;
        } else if (yesopt == 'N' || yesopt == 'n') {
            return 0;
        } else {
            printf("Only (Y)es or (N)o are acceptable: ");
            scanf("%s", &yesopt);
			flushKeyboard();
        }
    } while (1);

}

int menu(void){
	printf("1- List all items\n");
	printf("2- Search by SKU\n");
	printf("3- Checkout an item\n");
	printf("4- Stock an item\n");
	printf("5- Add new item or update item\n");
	printf("6- delete item\n");
	printf("7- Search by name\n");
	printf("0- Exit program\n");
	printf("> ");
	return getIntLimited(0,7);
}

int getInt(void){ // Check if user entered the character and breaks, returns the value if a number // 
	int value;
	while(1){
		char letter = 'x';
		scanf("%d%c", &value, &letter);
		if(letter != '\n'){
			printf("Invalid integer, please try again: ");   
			flushKeyboard();
		}else{
			return value;
		}
	}
}

int getIntLimited(int lowerLimit, int upperLimit){ // Check if user typed the value higher/lower and repeats. Returns the value if user entered the right number //
	int Value;
	while(1){
		Value = getInt();
		if(Value < lowerLimit || Value > upperLimit){
			printf("Invalid value, %d < value < %d: ", lowerLimit, upperLimit); 
		}else{
			return Value;
		}
	}
}

double getDouble(void){ // Same as getInt but value is double //
	char letter = 'x';
	double value;
	while(1){
		scanf("%lf%c", &value, &letter); 
		if(letter != '\n'){
			printf("Invalid number, please try again: ");   
			flushKeyboard();
		}else{
			return value;
		}
	}
}

double getDoubleLimited(double lowerLimit, double upperLimit){ // Same as getIntLimited but value is double //
	double Value;
	while(1){
		Value = getDouble();
		if(Value < lowerLimit || Value > upperLimit){
			printf("Invalid value, %lf < value < %lf: ", lowerLimit, upperLimit); 
		}else{
			return Value;
		}
	}
}

//End of Milestone 1//

// The Item input/output MILESTONE 2//

double totalAfterTax(struct Item item){ // Summarize the total with taxes by price multiplying by quantity and by constant Tax //
	double total;
	if (item.yesopt == 1) {
        total = (item.quantity * item.price) + (item.quantity * item.price * TAX);
    } else if (item.yesopt == 0) {
        total = item.quantity * item.price;
    }
	return total;
}

int isLowQuantity(struct Item item){ // Checks if quantity is low and returns the result  // 
	int result = 0;
	if (item.quantity <= item.minQuantity) {  
		result = 1;
	}
	return result;
}

struct Item itemEntry(int sku){ // Function gets the sku and lets the user enter the data after // 
	struct Item temp;
	temp.sku = sku;
	printf("        SKU: %d\n", sku);
	printf("       Name: ");
	scanf("%20[^\n]", temp.name);                   	
	printf("      Price: ");
	temp.price = getDoubleLimited(0.01, 1000.00);
	printf("   Quantity: ");
	temp.quantity = getIntLimited(0,100);
	printf("Minimum Qty: ");
	temp.minQuantity = getIntLimited(0, MAX_QTY);
	printf("   Is Taxed: ");
	temp.yesopt = yes(); 
	return temp;
}

void displayItem(struct Item item, int linear) {
	if (FORM == linear) {
		if (isLowQuantity(item)) {             // This displays if quantity is low // 
			printf("        SKU: %d\n", item.sku);
			printf("       Name: %s\n", item.name);
			printf("      Price: %.2lf\n", item.price);
			printf("   Quantity: %d\n", item.quantity);
			printf("Minimum Qty: %d\n", item.minQuantity);
			printf("   Is Taxed: %s\n", item.yesopt ? "Yes" : "No");
			printf("WARNING: Quantity low, please order ASAP!!!\n");
		} else {								// just displaying the data //
			printf("        SKU: %d\n", item.sku);
			printf("       Name: %s\n", item.name);
			printf("      Price: %.2lf\n", item.price);
			printf("   Quantity: %d\n", item.quantity);
			printf("Minimum Qty: %d\n", item.minQuantity);
			printf("   Is Taxed: %s\n", item.yesopt ? "Yes" : "No");
		}
	} else if (LINEAR == linear) {
		if (isLowQuantity(item)) {
			printf("|%3d|%-20s|%8.2lf|  %3s| %3d | %3d |%12.2lf|***\n",
					item.sku, item.name, item.price,
					item.yesopt ? "Yes" : "No", item.quantity,
					item.minQuantity, totalAfterTax(item));
		} else {
			printf("|%3d|%-20s|%8.2lf|  %3s| %3d | %3d |%12.2lf|\n", item.sku,
					item.name, item.price, item.yesopt ? "Yes" : "No",
					item.quantity, item.minQuantity, totalAfterTax(item));
		}
	}
}

void listItems(const struct Item item[], int noOfItems){ // display the list of times in linear type with grandtotal by summarizing with total with taxes //
	int i;
	double grandTotal = 0;
	printTitle();
	for(i = 0; i < noOfItems; i++){	
		printf("%-4d", i + 1);
		displayItem(item[i], LINEAR);
		grandTotal = grandTotal + totalAfterTax(item[i]);
	}
	printFooter(grandTotal);
}

int locateItem(const struct Item item[], int NoOfRecs, int sku, int* index){ // looks through an array information with sku to search in array, if found returns the q if not, nothing happens //
	int i;
	int q = 0;
	for(i = 0; i < NoOfRecs; i++){												
			if(sku == item[i].sku){
					*index = i ;
					q = 1;
			}
	}
	return q;
}

 // Item storage and retrieval in array MILESTON 3 //
 
 void search(const struct Item item[], int NoOfRecs){ // searches for item by sku number, if founded, displays in FORM format, if not, displays an error // 
	int sku;
	int index;
	int search = 0;
	printf("Please enter the SKU: ");
	sku = getIntLimited(SKU_MIN, SKU_MAX);
	search = locateItem(item, NoOfRecs, sku, &index);
	if(search){
		displayItem(item[index], FORM);          					
	}else{
		printf("Item not found!\n");
	}
}

void updateItem(struct Item* itemptr){ //  if called, calls itemEntry to change data and asks if user wants to overwrite old data// 
	struct Item item;
	int aswr;
	printf("Enter new data:\n");
	item = itemEntry(itemptr->sku);
	printf("Overwrite old data? (Y)es/(N)o: ");              
	aswr = yes();
	if(aswr){
		*itemptr = item;
		printf("--== Updated! ==--\n");
	}else{
		printf("--== Aborted! ==--\n");
	}
}

void addItem(struct Item item[], int *NoOfRecs, int sku){ //checks if array is full, if not - allows user to add items, if it's full - displays error. // 
	struct Item storage;
	int left;
	int addItem;
	left = (*NoOfRecs < MAX_ITEM_NO) ? 1 : 0;														
	if (left){
		storage = itemEntry(sku);
		printf("Add Item? (Y)es/(N)o: ");							
		addItem = yes();
		if (addItem){
			*NoOfRecs += 1;
			item[*NoOfRecs - 1] = storage;
			printf("--== Added! ==--\n");
		} else {
			printf("--== Aborted! ==--\n");
		}
	} else {
		printf("Can not add new item; Storage Full!\n");
	}
}

void addOrUpdateItem(struct Item item[], int* NoOfRecs){ // Same as addItem, but if item array found, it allows user to update the data //
	int sku;
	int index;
	int search;
	printf("Please enter the SKU: ");
	sku = getIntLimited(SKU_MIN, SKU_MAX);
	search = locateItem(item, *NoOfRecs, sku, &index);
	if (search){
		int check;
		displayItem(item[index], FORM);
		printf("Item already exists, Update? (Y)es/(N)o: ");				
		check = yes();
		if (check){
			updateItem(&item[index]);
		} else {
			printf("--== Aborted! ==--\n");
		}
	} else {
		addItem(item, NoOfRecs, sku);
	}
}

void adjustQuantity(struct Item item[], int NoOfRecs, int stock) { //This function adjusts quantity if called // this function was done with the help of my friend Xtendspb //
    int check, sku, index, opt;
    char tostock[] = "to stock", tocheck[] = "to checkout";
    printf("Please enter the SKU: ");
    scanf("%d", &sku);
    check = locateItem(item, NoOfRecs, sku, &index); // Asks for user to enter Sku and searches it by calling locateItem function //
    if (check == 0) {
        printf("SKU not found in storage!\n");
		flushKeyboard();
    } else {
        displayItem(item[index], FORM); 
        if (stock == STOCK) {
            printf("Please enter the quantity %s; Maximum of %d or 0 to abort: ", tostock, MAX_QTY - item[index].quantity);
            opt = getIntLimited(0, MAX_QTY); // receives the option and checks if user entered the right number 
            if (opt == 0) {
                printf("--== Aborted! ==--\n");
            } else {
                item[index].quantity += opt;
                printf("--== Stocked! ==--\n");
				if (item[index].quantity <= item[index].minQuantity) {
                    printf("Quantity is low, please reorder ASAP!!!\n");
                }
            }
        } else {
            printf("Please enter the quantity %s; Maximum of %d or 0 to abort: ", tocheck, item[index].quantity);
			opt = getIntLimited(0, item[index].quantity); // receives the option and checks if user entered the right number 
            if (opt == 0) {
                printf("--== Aborted! ==--\n");
            } else {
                item[index].quantity -= opt;
                printf("--== Checked out! ==--\n");
                if (item[index].quantity <= item[index].minQuantity) {
                    printf("Quantity is low, please reorder ASAP!!!\n");
                }
            }
        }
    }
}
//END OF MILESTONE 3//

//Load item into item array, MILESTONE 4//
void saveItem(struct Item item, FILE* dataFile){ // prints the data in dataFile //
	fprintf(dataFile, "%d,%d,%d,%0.2lf,%d,%s\n", item.sku, item.quantity, item.minQuantity, item.price, item.yesopt, item.name); 
}

int loadItem(struct Item* item, FILE* dataFile){ // this functions reads and check if text is right and stores them in structure//
	char sku[6];
	char tmp_tax[6];
	char price[6];
	char choose[4];
	char tmp_mq[4];
	int no;
	no = fscanf(dataFile, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]", sku, choose, tmp_mq, price, tmp_tax, item->name); 
	item->sku = atoi(sku);
	item->yesopt = atoi(tmp_tax);
	item->price = atof(price);
	item->quantity = atoi(choose);
	item->minQuantity = atoi(tmp_mq);
	if (no == 6) {
		return 1;
	}
	return 0;
}

int saveItems(struct Item* item, char fileName[], int NoOfRecs){ // same as saveItem but works with an array //
	int i = 0;
	FILE* tp = fopen(fileName, "w");
	if (tp) {
		for (i = 0; i < NoOfRecs; i++) {			
			saveItem(item[i], tp);
		}
		return 1;
	}
	fclose(tp);
	return 0;
}

int loadItems(struct Item* item, char fileName[], int* NoOfRecsPtr) {
	FILE* tp = fopen(fileName, "r");
	if (tp) {
		while (loadItem(&item[*NoOfRecsPtr], tp) != 0) {
			(*NoOfRecsPtr)++;
		}
		return 1;
	}
	fclose(tp);
	return 0;
}
// End of load item in array Milestone 4 // 

