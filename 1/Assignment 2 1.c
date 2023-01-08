#include <stdio.h>
#include <string.h>

float GetMoney();
void ShowMenu(char[], float);
void Purchase(float);

int main(){

	char drinks[5][20] = {"Mineral water", "Coca-cola", "Seven-UP", "Nescafe", "SoyDrink"};
	float prices[5] = {1, 2.5, 2.2, 3, 1.9};
	float totalcoins;
	int i;
	
	for(i=0; i<5; i++){
		printf("(%d)", i+1);
		ShowMenu(drinks[i], prices[i]);
	}
	
	printf("\n");
	
	totalcoins = GetMoney();

	Purchase(totalcoins);

return 0;
}

void ShowMenu(char drinks[20], float price){
	printf("%s = RM%.2f\n", drinks, price);
}

float GetMoney(){
	float coins, totalcoins=0, rm;
	
	do{
		printf("Enter money (cents): (-1 to stop input) : ");
		scanf("%f", &coins);
		
		if(coins==-1){
			break;
		}else if(coins!=10 && coins!=20 && coins!=50){
			do{
				printf("Invalid input!\nPlease enter again: ");
				scanf("%f", &coins);
			}while(coins!=10 && coins!=20 && coins!=50);
		}
		
		totalcoins+=coins;
		printf("\tTotal amount inserted until now: RM%.2f\n", totalcoins/100);
		
	}while(coins!=-1);
	
	rm=totalcoins/100;
	printf("\nAvailable drinks: \n");
	
	return totalcoins;
}

void Purchase(float totalcoins){
	
	char drinks[5][20] = {"Mineral water", "Coca-cola", "Seven-UP", "Nescafe", "SoyDrink"};
	char buy[20];
	float prices[5] = {1, 2.5, 2.2, 3, 1.9};
	float canbuy[5]={0};
	int i, x=0;
	float rm;
	
	for(i=0; i<5; i++){
		if(totalcoins>=prices[i]*100){
			printf("%s \tRM%.2f\n", drinks[i], prices[i]);
		}
	}
	
	rm=totalcoins/100;
	
	printf("\nWhich one do you like to buy?: ");
	getchar();
	gets(buy);

	for(i=0; i<5; i++){
		if(strcmp(buy, drinks[i])==0){
			if(rm>=prices[i]){
				printf("Balance = RM%.2f", rm-prices[i]);
			}else{
				printf("Insufficient balance.");
			}
		}
	}
	
}


