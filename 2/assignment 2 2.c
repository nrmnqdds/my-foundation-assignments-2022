#include <stdio.h>

float Calculate(int, int);
float CalculateDiscount(int, float);
void Display(int, float, float, float);

int main(){
	
	int rpm[4] = {980, 750, 550, 420};
	int package, days, bookingtype;
	float tax, price, discount;
	int i;
	
	printf("WELCOME TO SANCTUARY RESORT\n\n");
	
	printf("Enter package type (1-4): ");
	scanf("%d", &package);
	printf("Enter no. of days: ");
	scanf("%d", &days);
	printf("Enter booking type (1 or 2): ");
	scanf("%d", &bookingtype);
	
	tax = Calculate(package, days);
	
	for(i=0; i<4; i++){
		if(package==i+1){
			price=rpm[i]*days;
		}
	}

	discount = CalculateDiscount(bookingtype, price);
	
	Display(package, tax, discount, price);
	
	
	
	return 0;
}

float Calculate(int package, int days){
	
	int rpm[4] = {980, 750, 550, 420};
	int i;
	float tax, grossprice;
	
	for(i=0; i<4; i++){
		if(package==i+1){
			grossprice=rpm[i]*days;
		}
	}
	tax = grossprice*0.05;

	return tax;	
}

float CalculateDiscount(int bookingtype, float price){
	
	float discount;
	
	if(bookingtype==1){
		discount = price*0.9;
	}else{
		discount=0;
	}
	
	return discount;
}

void Display(int package, float tax, float disc, float price){
	
	char name[4][30] = {"Penthouse Suite", "3 Rooms Apartment", "2 Rooms Apartment", "Studio Suite"};
	
	printf("\nBooking Details: \n");
	printf("----------------\n");
	switch(package){
		case 1: case 2: case 3: case 4:
			printf("%s\n", name[package-1]); break;
	}
	
	
	printf("Price\tRM%.2f\n",price);
	printf("Tax\tRM%.2f\n", tax);
	printf("(Discount)\tRM%.2f\n", disc);
	printf("--------------------\n");
	printf("NET PRICE\tRM%.2f", price+tax-disc);
	
}




