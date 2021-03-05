int main(void){
	int loonies, quarters, dimes, nickels, pennies;
	double GST, amount, balOwing;
	printf("Please enter the amount to be paid: $");
	scanf("%lf",&amount);
	GST = amount*0.13+0.005;
	amount +=GST;
	printf("Kek: %d/n", devideBy(0.75,0.1));
	printf("GST: %.2f\n", GST);
	printf("Balance owing: $%f\n", amount);
	loonies = amount/1;
	amount = amount-(loonies*1);
	printf("Loonies required: %d, balance owing $%.2f\n", loonies, 
amount);
	quarters = amount/0.25;
	amount = amount-(quarters*0.25);
	printf("Quarters required: %d, balance owing $%.2f\n", quarters, 
amount);
	dimes = amount/0.1;
	amount = amount-(dimes*0.1);
	printf("Dimes required: %d, balance owing $%.2f\n", dimes, 
amount);
	nickels = amount/0.05;
	amount = amount-(nickels*0.05);
	printf("Nickels required: %d, balance owing$%.2f\n", nickels, 
amount);
	pennies = (((int)(amount*100+0.5))/100/0.01;
	amount = amount-(pennies*0.01);
	printf("Pennies required: %d, balance owing $%.2f\n", pennies, 
amount);
	return 0;
}
