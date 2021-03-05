
#define distRate1 0.69
#define distRate2 0.49

struct Rental{
	int id;
	double baseDay;
	double earnings;
};

int main(){
	const int noVehicles = 2;
	int option;
	int flag;
	int tempID;
	int j;
	int i = 0;
	struct Rental vRent[] = {{123, 9.95, 0},{124, 19.95, 0}};
	printf("***** Rental Vehicle Management App *****\n\n");
	while(1){
		printf("1.) Rental Status\n");
		printf("2.) Apply Charges\n");
		printf("0.) Log out\n\n");
		printf("Please enter an option to continue: ");
		scanf("%d", &option);
		if(option == 0){
			return 0;
		}
		if(option == 1){
			printf("\n-- Rental Vehicle Status --\n\n");
			printf("ID#      Earnings\n");
			printf("-------- ----------\n");
			for(j = 0; j < noVehicles; j++){
				printf("%8d%10.2lf\n", vRent[j].id, vRent[j].earnings);
		if(option == 2){
			flag = -1;
			printf("\n-- Rental Charges --\n\n");
			printf("Enter vehicle ID: ");
			scanf("%d", &tempID);
			for(i = 0; i < noVehicles && flag == -1; i++){
				if(tempID == vRent[i].id){
					flag = i;
					if(flag != -1){
						int days, kms;
						double BaseP, kmsC, total;
						printf("Enter Rental Period (in Days): ");
						scanf("%d", &days);
						BaseP = (vRent[i].baseDay * days);
						printf("Enter kilometers driven: ");
						scanf("%d", &kms);
						if(kms >= 100){
							kmsC = (100 * distRate1)+(kms - 100) * distRate2;
						}
						if(kms < 100){
							kmsC = (kms * distRate1);
						}
						total = (kmsC + BaseP);
						printf("\nBase   kmCost Total\n");
						printf("====== ====== ======\n");
						printf("%6.2lf %6.2lf %6.2lf\n\n", BaseP, kmsC, total);
					}
				}
			}
		}
	}
}
}
return 0;
} 
					
				
							
