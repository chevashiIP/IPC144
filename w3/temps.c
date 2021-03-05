
#include <stdio.h>
#define NUMS 3
int main(void){
	int i;
	double averageTemp = 0 , sumTemp = 0;
	printf("---=== IPC Temperature Analyzer ===---\n");
	for(i = 1; i <= NUMS; i++) {
		double high, low;
		while(1) {
			printf("Enter the high value for day %d: ", i);
			scanf("%lf", &high);
			printf("\n");
			printf("Enter the low value for day %d: ", i);
			scanf("%lf", &low);
			printf("\n");
			if (high < 40.0 && low > -40.0 && high > low) {
			 sumTemp += (high + low)/2;
			 break;
			} else {
				printf("Incorrect values, temperatures must be in the range -40 to 40, high must be greater than low.\n");
				printf("\n");
			}
		}
	}
	averageTemp = sumTemp / NUMS;
	printf("The average (mean) temperature was: %.2lf\n", averageTemp);
	return 0;
}
	
