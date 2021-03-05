
#include <stdio.h>
#define SIZE 2
int main(void){
	int opt;
	double empinf[SIZE][3];
	int numI = 0;
	int j;
	printf("---=== EMPLOYEE DATA ===---\n");
	while(1){
		printf("\n");	
		printf("1. Display Employee Information\n");
		printf("2. Add Employee\n");
		printf("0. Exit\n");
		printf("\n");
		printf("Please select from the above options: ");
		scanf("%d", &opt);
		if(opt == 0){
			printf("\n");
			printf("Exiting Employee Data Program. Good Bye!!!\n");
			return 0;
		}
		if(opt == 2){
			if(numI < SIZE){
			printf("\n"); 
			printf("Adding Employee\n");
			printf("===============\n");
			printf("Enter Employee ID: ");
			scanf("%lf", &empinf[numI][0]);
			printf("Enter Employee Age: ");
			scanf("%lf", &empinf[numI][1]);
			printf("Enter Employee Salary: ");
			scanf("%lf", &empinf[numI][2]);
			numI++;
			} else {
				printf("\n");
				printf("Adding Employee\n");
				printf("===============\n");
				printf("ERROR!!! Maximum Number of Employees Reached\n");
				}
		}
		if(opt == 1){
			printf("\n");
			printf("EMP ID  EMP AGE EMP SALARY\n");
			printf("======  ======= ==========\n");
			for(j = 0; j < numI; j++){
			printf("   %.0lf       %.0lf   %.2lf\n", empinf[j][0],empinf[j][1],empinf[j][2]);
			}
		}	
	}
return 0;
} 				
				
				
				
	
