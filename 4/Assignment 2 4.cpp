#include <stdio.h>
#include <string.h>

int ChooseAttire();
int GetSize();
int GetQuantity();
float ProcessOrder(int, int, int);
void UpdateTotal(int, float, int);

int main()
{
	int quantity, saiz, attire;
	float total[7]={0};
	float price, totalprice=0;
	int i;
	char yn;
	
	do{
		printf("\t*** Welcome to Sporty Garments ***\n\n");
		
		attire = ChooseAttire();
		saiz = GetSize();	
		quantity = GetQuantity();	
		price = ProcessOrder(attire, saiz, quantity);
		
		totalprice+=price;
		
		for(i=0; i<7; i++){
			if(attire==i+1){
				total[i] = totalprice;
			}
		}
		
		printf("\n\nAnother order? (Y or y to order again): ");
		scanf("%s", &yn);
		printf("\n\n");
		
		
	}while(yn=='Y' || yn =='y');
	
	if(yn=='n' || yn=='N'){
		for(i=0; i<7; i++){
			UpdateTotal(attire, total[i], i);
		}
	}
		
	
	return 0;
}

int ChooseAttire(){
	
	char sporting_attire[7][30] = {"Polo Shirts", "Football Jersey","Swimming Suits", "Tennis Shirt","Windbreakers","Baseball Jersey","Fencing Jacket"};
	int choice,i;
	
	do{
		printf("You may choose from the following types of attire:\n\n");
		printf("\tType\n\t==========\n");
		
		for(i=0; i<7; i++){
			printf("\t%d - %s\n", i+1, sporting_attire[i]);
		}
		
		printf("Enter your attire choice: ");
		scanf("%d", &choice);
		
		if(choice>7 || choice<1){
			printf("Sorry wrong choice! Try again...\n\n");
		}
	}while(choice>7 || choice<1);
	
	printf("\nYou have chosen %s\n\n", sporting_attire[choice-1]);
	
	return choice;
}

int GetSize(){
	
	char size[4][5] = {"S" ,"M" ,"L" ,"XL"};
	int z, choice;
	
	printf("Available sizes: ");
	
	for(z=0; z<4 ;z++){
		printf("%d) size %s ", z+1,size[z]);
	}
	
	printf("\n\nChoose which size: ");
	scanf("%d", &choice);
	
	return choice;
}

int GetQuantity(){
	
	int choice;
	
	printf("Enter quantity: ");
	scanf("%d", &choice);
	
	return choice;
}

float ProcessOrder(int attire, int size, int quantity){
	
	float price[7][4]={{35, 35, 35, 40}, {73.5, 73.5, 74.5, 75}, {101.5, 105.5, 108.5,109.50 },{72.90, 72.90, 72.90, 72.90}, {84.00, 85.70, 87.70, 89.70}, {62.00, 62.00, 62.00, 64.00},{94.00, 95.00, 97.00, 99.00} };
	char saiz[4][20] = {"S", "M", "L", "XL"};
	char sporting_attire[7][30] = {"Polo Shirts", "Football Jersey","Swimming Suits", "TEnnis Shirt","Windbreakers","Baseball Jersey","Fencing Jacket"};
	float prices;
	int i;
	
	
	printf("\nConfirmation of order:\n");
	printf("======================\n");
	printf("%d piece(s) of %s of size %s.\n",quantity, sporting_attire[attire-1], saiz[size-1]);
	
	for(i=1; i<=7; i++){
		if(attire==i){
			switch(size){
				case 1: case 2: case 3: case 4:
					prices = quantity*price[i-1][size-1]; break;
			}
		}
	}
	
	printf("Amount to pay is RM%.2f", prices);
	
	return prices;
}

void UpdateTotal(int attire, float totalprice, int i){
	
	char sporting_attire[7][30] = {"Polo Shirts     ", "Football Jersey","Swimming Suits", "Tennis Shirt","Windbreakers","Baseball Jersey","Fencing Jacket"};
	char target[2][5] = {"YES", "NO"};
	
	if(i==0){
		printf("Summary of sales for today...\n");
		printf("\tType\t\tTotal\tReach Target\n");
		printf("+++++++++++++++++++++++++++++++++++++++++++++\n");	
	}
	
	printf("%d - %s\tRM%.0f\t\t", i+1, sporting_attire[i], totalprice);
	if(totalprice>=500){
		printf("YES\n");
	}else{
		printf("NO\n");
	}

}



