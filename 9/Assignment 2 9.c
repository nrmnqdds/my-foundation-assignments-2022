#include <stdio.h>

void UpdateStock(int);
void UpdatedList(float, int, int);

int main(){
	
	int Code[5] = {101, 102, 103, 104, 105};
	float Price[5] = {1.5, 2.5, 2.2, 3, 1.9};
	int Quantity[5] = {10, 5, 8, 12, 17};
	char drinkname[5][20] = {"Mineral water", "Coca-cola", "Seven-UP", "Nescafe     ", "SoyDrink"};
	int i, drinkcode;
	char yn;
	
	printf("***Vending Machine Inventory System***\n\n");
	
	printf("Code\tDrink\t\tPrice\tQty\n");
	printf("---\t----   \t\t------\t---\n");
	for(i=0; i<5; i++){
		printf("%d\t%s\t%.2f\t%d\n", Code[i], drinkname[i], Price[i], Quantity[i]);
	}
	
	do{
		printf("\nEnter drinks code you want to update: ");
		scanf("%d", &drinkcode);
	
		UpdateStock(drinkcode);
		
		printf("\nDo you want to update another drink?");
		scanf("%s", &yn);
	}while(yn=='Y');
	
	printf("Thank you for using this system.");
	
	return 0;	
}

void UpdateStock(int drinkcode){
	
	int Code[5] = {101, 102, 103, 104, 105};
	float Price[5] = {1.5, 2.5, 2.2, 3, 1.9};
	int Quantity[5] = {10, 5, 8, 12, 17};
	char choose;
	float newprice;
	int i, j, k, newq;
	
	for(i=0; i<=5; i++){
		if(drinkcode==Code[i]){
			printf("\nChoose to update P-Price or Q-Quantity: ");
			scanf(" %c", &choose);
			
			switch(choose){
				case 'P':
					for(j=0; j<5; j++){
						if(i==j){
							printf("Enter new price: ");
							scanf("%f", &newprice);
							Price[j] = newprice;
							printf("\nPrice updated ...\n\n");
							for(k=0; k<5; k++){
							UpdatedList(Price[k], Quantity[k], k);
							}
						}		
					}
					break;
				case 'Q':
						for(j=0; j<5; j++){
							if(i==j){
								printf("Enter new quantity: ");
								scanf("%d", &newq);
								Quantity[j] = newq;
								printf("\nQuantity updated ...\n\n");
								for(k=0; k<5; k++){
								UpdatedList(Price[k], Quantity[k], k);
								}
							}
						}
					break;
				}

		}else{
			if(i==5){
				if(drinkcode!=Code[i]){
					printf("\nDrink code not found ...\n\n");
					for(k=0; k<5; k++){
						UpdatedList(Price[k], Quantity[k], k);
					}
				}
			}
		}
	}
	
	
}

void UpdatedList(float price, int quantity, int j){
	
	int Code[5] = {101, 102, 103, 104, 105};
	char drinkname[5][20] = {"Mineral water", "Coca-cola", "Seven-UP", "Nescafe     ", "SoyDrink"};
	int i, k=1;
	
	if(j==0){
		printf("***Latest inventory list***\n\n");
		printf("***Vending Machine Inventory System***\n\n");
	
		printf("Code\tDrink\t\tPrice\tQty\n");
		printf("---\t----   \t\t------\t---\n");
	}
	
	printf("%d\t%s\t%.2f\t%d\n", Code[j], drinkname[j], price, quantity);
	
	j=10;
	
}
