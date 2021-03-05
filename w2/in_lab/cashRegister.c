
#include <stdio.h>
int main(void){
	int loonies = 0; 
	int quarters = 0;
	printf("Please enter the amount to be paid: $");
	double amount = 0.0;
	double balOwing = 0.0;
	scanf("%lf",&amount);
	loonies = amount/1;
	balOwing = amount-(loonies*1);
	printf("Loonies required: %d, balance owing %lf", loonies, balOwing);
	quarters = balOwing/0.25;
	balOwing = balOwing-(quarters*0.25);
	printf("Quarters required: %d, balance owing %lf", quarters, 
balOwing);
	return 0;
}
