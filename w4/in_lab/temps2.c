
#include <stdio.h>
int main(void){
	int numDays;
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
	return 0;
}
			
	
