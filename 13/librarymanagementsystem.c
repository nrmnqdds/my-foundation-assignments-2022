#include <stdio.h>
#include <ctype.h>
#include <string.h>

void CheckAvailability();
void BorrowBook();
float Calculate(int, float);
void Checkout(float);

const float tax = 1.05;
char GenreList[5][20] = {"Horror", "Asian", "Muslim", "Gay   ", "Lesbian"};
int GenreNum[5] = {10, 7, 9, 5, 12};
float GenrePrice[5] = {10.5, 7, 3.5, 6.5, 9};
float BuyPrice[5];
int BuyAmount[5];
int action, i;

int main(){
		
	do{
		printf("\n\n\t\t***WELCOME TO e-LIBRARY***\n\n");
		
		printf("Enter action number:\n\n");
		printf("1. Check Availability\n2. Borrow Book\n");
		
		printf("=> ");
		scanf("%d", &action);
		system("cls");
		
		switch(action){
			case 1:
				CheckAvailability(); break;
			case 2:
				BorrowBook(); break;
		}
	
	}while(action!=2);
	
	return 0;
}

void CheckAvailability(){
	
	printf("\n\n\t\t***Check Availability***\n\n");
	
	printf("\tGENRE LIST:\n\n");
	for(i=0; i<5; i++){
		printf("%s\t: %d books available\n", GenreList[i], GenreNum[i]);
	}
	
	printf("\nEnter action number: \n");
	printf("1. Borrow Book\n2. Back to main page\n=> ");
	scanf("%d", &action);
	system("cls");
	
	switch(action){
		case 1:
			BorrowBook(); break;
		case 2:
			main(); break;
	}
	
}

void BorrowBook(){
	
	int genre, n;
	float price, sum=0;
	char yn;
	
	printf("\n\n\t\t***BORROW BOOK***\n");
	
	do{
		printf("\n\n");
		for(i=0; i<5; i++){
			printf("%d. %s\tPrice: RM%.2f\t%d books available\n", i+1, GenreList[i],GenrePrice[i], GenreNum[i]);
		}
		
		printf("\nYour Cart:\n");
		printf("GENRE\tAMOUNT\tPRICE\n");
		for(i=0; i<5; i++){
			printf("%s\t%d\t%.2f\n", GenreList[i], BuyAmount[i], BuyPrice[i]);
		}
		
		printf("\nWhich genre you want to borrow?\n=> ");
		scanf("%d", &genre);
		
		for(i=0; i<5; i++){
			if(genre-1==i){
				printf("How many %s book you want to borrow?\n", GenreList[i]);
				printf("=> ");
				scanf("%d", &n);
				
				BuyAmount[i]+=n;
				GenreNum[i]-=n;
				price = Calculate(n, GenrePrice[i]);
				BuyPrice[i]+=price;
				sum+=price;
			}
		}
		
		system("cls");
		printf("\nUPDATED LIST\n");
		for(i=0; i<5; i++){
			printf("%d. %s\tPrice: RM%.2f\t%d books available\n", i+1, GenreList[i],GenrePrice[i], GenreNum[i]);
		}
		
		printf("\nYour Cart:\n");
		printf("GENRE\tAMOUNT\tPRICE\n");
		for(i=0; i<5; i++){
			printf("%s\t%d\t%.2f\n", GenreList[i], BuyAmount[i], BuyPrice[i]);
		}
		
		printf("\nContinue Shopping?\n(y/n)=> ");
		scanf("%s", &yn);
		system("cls");
	}while(yn=='y' || yn=='Y');
	
	printf("\nYour Cart:\n");
	printf("GENRE\tAMOUNT\tPRICE\n");
	for(i=0; i<5; i++){
		printf("%s\t%d\t%.2f\n", GenreList[i], BuyAmount[i], BuyPrice[i]);
	}
	
	printf("\nEnter action number: \n");
	printf("1. Checkout\n2. Check Availability\n3. Back to main page\n=> ");
	scanf("%d", &action);
	
	switch(action){
		case 1:
			Checkout(sum); break;
		case 2:
			CheckAvailability(); break;
		case 3:
			main(); break;
	}
	
	
}

float Calculate(int n, float j){
	
	float price;
	
	price = (j*n);
	
	return price;
}

void Checkout(float sum){
	
	system("cls");
	printf("\n\n\t\t***CHECKOUT***\n\n");
	printf("GENRE\tAMOUNT\tPRICE\n");
		for(i=0; i<5; i++){
			printf("%s\t%d\t%.2f\n", GenreList[i], BuyAmount[i], BuyPrice[i]);
		}
		
	printf("-------------------------------\n");
	printf("Tax: 5%%\nTotal Price: RM%.2f", (sum*tax)+sum);
	system("pause");
	system("cls");
	
}

