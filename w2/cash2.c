nclude <stdio.h>
#include <math.h>

int main (void)

{
	    double cost;
	        int loonies, quarters, dimes, nickels, pennies;
		    float loonreq;
		        float balance;


			    printf ("Please enter the amount to be paid: ");
			        scanf ("%lf", &cost);

				    printf ("Change Due: $ %.2f\n", cost);

				        loonies = cost;
					    printf ("Loonies required: %d, ", loonies);

					        loonreq = cost - loonies;
						    printf ("balance owing: $ %.2f\n", loonreq);

						        quarters = (int)(((int)(100*loonreq))/25);
							    printf("num quarters: %d \n",quarters);
							        balance = loonreq - (quarters*.25);
								    printf("balance owing: %.2f$ \n", balance);
								        dimes = (int)(((int)(100*balance))/10);
									    balance = balance - (dimes*.1);
									        printf("num dimes: %d \n", dimes);
										    printf("balance owing: %.2f$ \n", balance);

										        nickels = (int)(((int)(100*balance))/5);
											    printf("num nickels: %d \n", nickels);
											        balance = balance - (nickels*.05);
												    pennies = (int)(balance*100);
												        printf("balance owing: %.2f$ \n", balance);
													    printf("num pennies: %d \n", pennies);


													        return 0;
}
