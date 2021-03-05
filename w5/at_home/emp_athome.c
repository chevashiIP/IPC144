
#include <stdio.h>
#define SIZE 4

//Creating structure for Employee
struct Employee {
        int Id;
        int Age;
        double Salary;
};

int main(){
        int opt;
        struct Employee emps[SIZE];
        int numEmps = 0;
        int j;
        int searchId;

        printf("---=== EMPLOYEE DATA ===---\n");
        while(1){
                printf("\n");
                printf("1. Display Employee Information\n");
                printf("2. Add Employee\n");
                printf("3. Update Employee Salary\n");
                printf("4. Remove Employee\n");
                printf("0. Exit\n");
                printf("\n");
                printf("Please select from the above options: ");
                scanf("%d", &opt);

                //Exit
                if(opt == 0){
                        printf("\n");
                        printf("Exiting Employee Data Program. Good Bye!!!\n");
                        return 0;
                }

                //Display Employee info
                if(opt == 1){
                        printf("\n");
                        printf("EMP ID  EMP AGE EMP SALARY\n");
                        printf("======  ======= ==========\n");
                        for(j = 0; j < numEmps; j++){
                                printf("%6d%9d%11.2lf\n", emps[j].Id,emps[j].Age,emps[j].Salary);
                        }
                }

                //Adding Employee
                if(opt == 2){
                        if(numEmps < SIZE){
                                printf("\n");
                                printf("Adding Employee\n");
                                printf("===============\n");
                                printf("Enter Employee ID: ");
                                scanf("%d", &emps[numEmps].Id);
                                printf("Enter Employee Age: ");
                                scanf("%d", &emps[numEmps].Age);
                                printf("Enter Employee Salary: ");
                                scanf("%lf", &emps[numEmps].Salary);
                                numEmps++;
                        } else {
                                printf("\n");
                                printf("Adding Employee\n");
                                printf("===============\n");
                                printf("ERROR!!! Maximum Number of Employees Reached\n");
                        }
                }

                //Updating Employee Salary
                if(opt == 3){
			printf("\n");
                        printf("Update Employee Salary\n");
                        printf("======================\n");
                        printf("Enter Employee ID: ");
                        scanf("%d", &searchId);
                        for(j = 0; j < numEmps; j++){
				if(searchId == emps[j].Id){
                                        printf("The current salary is %.2lf\n", emps[j].Salary);
                                        printf("Enter Employee New Salary: ");
                                        scanf("%lf", &emps[j].Salary);
                                        break;
                                }
                        }
                }

                //Removing Employee
                if(opt == 4){
			printf("\n");
			printf("Remove Employee\n");
			printf("===============\n");
			printf("Enter Employee ID: ");
                        scanf("%d", &searchId);
			printf("Employee %d will be removed\n", searchId);
                        for(j = 0; j < numEmps; j++){
				if(searchId == emps[j].Id){
                                        int k;
                                        for(k = j; k < numEmps; k++){
                                                emps[k].Id = emps[k+1].Id;
                                                emps[k].Age = emps[k+1].Age;
                                                emps[k].Salary = emps[k+1].Salary;
                                        }
                                        numEmps--;
                                }
                        }
		}
                if(opt > 4){
			printf("\n");
                        printf("ERROR: Incorrect Option: Try Again\n");
                }
        }
return 0;
}
