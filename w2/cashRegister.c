
#include <stdio.h>
int main(void){
	int loonies, quarters, dimes, nickels, pennies = 0;
	printf("Please enter the amount to be paid: $");
	double GST = 0.0;
	double amount = 0.0;
	double balOwing = 0.0;
	scanf("%lf",&amount);
	GST = amount*0.13+0.005;
	printf("GST: %.2lf\n", GST);
	amount = amount+(GST);
	printf("Balance owing: $%.2lf\n", amount);
	loonies = amount/1;
	balOwing = amount-(loonies*1);
	printf("Loonies required: %d, balance owing $%.2f\n", loonies, 
balOwing);
	quarters = balOwing/0.25;
	balOwing = balOwing-(quarters*0.25);
	printf("Quarters required: %d, balance owing $%.2f\n", quarters, 
balOwing);
	dimes = balOwing/0.1;
	balOwing = balOwing-(dimes*0.1);
	printf("Dimes required: %d, balance owing $%.2f\n", dimes, 
balOwing);
	nickels = balOwing/0.05;
	balOwing = balOwing-(nickels*0.05);
	printf("Nickels required: %d, balance owing $%.2f\n", nickels, 
balOwing);
	pennies = (((int)(balOwing*100+0.5))/100.0)/0.01;
	balOwing = balOwing-(pennies*0.01);
	printf("Pennies required: %d, balance owing $%.2lf\n", pennies, 
(float)balOwing/100);
	return 0;
}
