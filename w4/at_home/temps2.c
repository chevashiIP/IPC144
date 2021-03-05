
#include <stdio.h>
int main(void){
	int numDays;
	int numB;
	printf("---=== IPC Temperature Analyzer V2.0 ===---\n");
	printf("Please enter the number of days, between 3 and 10, inclusive: ");
	while(1){
		scanf("%d", &numDays);
		if(numDays >= 3 && numDays <= 10){
		break;
		 } else {
			printf("\n");	
			printf("Invalid entry, please enter a number between 3 and 10, inclusive: ");
			}
		}
		int days[numDays][2];
		int i;
		printf("\n");			
		for(i = 0; i < numDays; i++){
			printf("Day %d - High: ", i+1);
			scanf("%d", &days[i][0]);
			printf("Day %d - Low: ", i+1);
			scanf("%d", &days[i][1]);
		}
		int j;
		printf("\n");
		printf("Day  Hi  Low\n");
		for(j = 0; j < numDays; j++){
			printf("%d    %d    %d\n",j+1,days[j][0],days[j][1]);
		}
	printf("\n");
	while(1){
		printf("Enter a number between 1 and %d to see the average temperature for the entered number of days, enter a negative number to exit: ", numDays);
		scanf("%d", &numB);
		while(numB <= 0){
			printf("\n");
			printf("Goodbye!\n");
			return 0;  
				}
		while(numDays < numB){
			printf("\n");
			printf("Invalid entry, please enter a number between 1 and %d, inclusive: ", numDays);
			scanf("%d", &numB);
				}
		float avgSum = 0;
		for(i = 0; i < numB; i++){
		float avgOfDay = (days[i][0] + days [i][1])/2.0;
		avgSum += avgOfDay;
		}
		float overallAvg= avgSum/numB;
		printf("\n");
		printf("The average temperature up to day %d is: %.2lf\n", numB, overallAvg);
		printf("\n");
		}	
	return 0;
}
			
	
