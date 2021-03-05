
#include <stdio.h>
#define SIZE 3
int main(void){
	int option;
	long long phoneNum[SIZE];
	int j; 
	int phList = 0;
	printf("---=== Phone Numbers ===---\n");
	while(1){
		printf("\n");
		printf("1. Display Phone List\n");
		printf("2. Add a Number\n");
		printf("0. Exit\n");
		printf("\n");
		printf("Please select from the above options: ");
		scanf("%d", &option);
		if(option == 0){
			printf("Exiting Phone Number App. Good Bye!!!\n");
			return 0;
		}
		if(option == 1){
			printf("\n");
			printf("Phone Numbers\n");
			printf("==============\n");
			for(j = 0; j < phList; j++){ 
				printf("%ll", phoneNum[phList]);
			}  
			
		}
		if(option == 2){
			if(phList < SIZE){
				printf("\n");
				printf("Add a Number\n");
				printf("============\n");
				scanf("%d", &phoneNum[phList]);
				
				phList++;
				} else {
					printf("Add a Number\n");
					printf("============\n");
					printf("ERROR!!! Phone Number List is Full\n");
					}
		}
	}
return 0;
}
