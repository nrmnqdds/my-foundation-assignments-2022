#include <stdio.h>

float ChooseCookies();
int GetPackage();
float GetQuantity();
float ProcessOrder(int, int, float);

int main(){
	
	float sales, totalsales=0;
	char response;
	
	do{
		sales=ChooseCookies();
		totalsales+=sales;
		
		printf("\n\nDo you want to order another cookies: ");
		scanf("%s", &response);
		
	}while(response=='y');
	
	printf("Total amount to pay is RM%.2f", totalsales);
		
	return 0;
}

float ChooseCookies(){
	
	char cookies_name[6][10]={"Walnut", "Almond", "Chocolate", "Coffee", "Oat", "Lemon"};
	int i, j, package, quantity, choice, pcs;
	float price;
	
	do{
		printf("\nYou may choose from the following flavours: \n\tFlavour\n");
		for(i=0; i<6; i++){
			printf("%d. %s\n", i+1, cookies_name[i]);
		}
		
		printf("\nEnter your choice: ");
		scanf("%d", &choice);
		
		if(choice!=1 && choice!=2 && choice!=3 && choice!=4 && choice!=5 && choice!=6){
			printf("Sorry, wrong choice! Try again\n");
		}
		
	}while(choice!=1 && choice!=2 && choice!=3 && choice!=4 && choice!=5 && choice!=6);
	
	switch(choice){
		case 1:
			printf("You have chosen Walnut cookies.\n\n");
			break;
		case 2:
			printf("You have chosen Almond cookies.\n\n");
			break;
		case 3:
			printf("You have chosen Chocolate cookies.\n\n");
			break;
		case 4:
			printf("You have chosen Coffee cookies.\n\n");
			break;
		case 5:
			printf("You have chosen Oat cookies.\n\n");
			break;
		case 6:
			printf("You have chosen Lemon cookies.\n\n");
			break;
	}
	
	package = GetPackage();
	
	switch(package){
		case 1:
			pcs=12; break;
		case 2:
			pcs=24; break;
		case 3:
			pcs=100; break;
	}
	
	quantity = GetQuantity();
	
	printf("\n");
	price = ProcessOrder(choice, pcs, quantity);		

	return price;
}

int GetPackage(){
	
	char cookies_name[6][10]={"Walnut", "Almond", "Chocolate", "Coffee", "Oat", "Lemon"};
	int package_types[3]={12, 24, 100};
	int choice, i, package;
	

	printf("Available packages: ");
	for(i=0; i<3; i++){
		printf("%d pcs  ", package_types[i]);
	}
	
	printf("\nChoose which package (1 or 2 or 3): ");
	scanf("%d", &package);
	
	return package;
}

float GetQuantity(){
	
	float quantity;
	
	printf("\nEnter quantity: ");
	scanf("%f", &quantity);

	return quantity;
}

float ProcessOrder(int c, int choice, float quantity){
	
	float cookie_price[6][3]={{3.5, 5, 25}, {3.5, 5, 24.5}, {1.5, 4, 14}, {2.9, 5, 15}, {2.7, 4, 12.8}, {2, 3, 11}};
	char cookies_name[6][10]={"Walnut", "Almond", "Chocolate", "Coffee", "Oat", "Lemon"};
	float price;
	int i;
	
	printf("Confirmation of order:\n");
	
	for(i=0; i<6; i++){
		if(quantity==i){
			printf("%.0f pack(s) of %d pcs package of %s cookies\n", quantity, choice, cookies_name[i]);			
		}
	}
	
	if(c==1){
		if(quantity==1){
			price=quantity*3.5;
		}else if(quantity==2){
			price=quantity*5;
		}else{
			price=quantity*25;
		}
	}else if(c==2){
		if(quantity==1){
			price=quantity*3.5;
		}else if(quantity==2){
			price=quantity*5;
		}else{
			price=quantity*24;
		}
	}else if(c==3){
		if(quantity==1){
			price=quantity*1.5;
		}else if(quantity==2){
			price=quantity*4;
		}else{
			price=quantity*14;
		}
	}else if(c==4){
		if(quantity==1){
			price=quantity*2.9;
		}else if(quantity==2){
			price=quantity*5;
		}else{
			price=quantity*15;
		}
	}else if(c==5){
		if(quantity==1){
			price=quantity*2.7;
		}else if(quantity==2){
			price=quantity*4;
		}else{
			price=quantity*12.8;
		}
	}else if(c==6){
		if(quantity==1){
			price=quantity*2;
		}else if(quantity==2){
			price=quantity*3;
		}else{
			price=quantity*11;
		}
	}
	
	printf("Amount to pay is: RM%.2f", price);
	
	return price;
}







