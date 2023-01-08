#include <stdio.h>

void Input();
int CalculateFee(char, int, int, int, int);
void Output(int, float);

int main(){
	
	float children, income;
	
	printf("WELCOME TO LITTLE MUCHKIN KINDERGARTEN\n\n");
	
	Input();
	
	printf("Thankyou for using this sytem.");
	
	return 0;
}

void Input(){
	int children, i, category, totalfee=0;
	char ab;
	float income;
	
	printf("How many children to enroll? ");
	scanf("%d", &children);
	
	do{
		printf("Household income (A or B): ");
		scanf(" %c", &ab);
		
		if(ab!='A' && ab!='B'){
			printf("Invalid!\n");
		}
	}while(ab!='A' && ab!='B');
	
	for(i=1; i<=children; i++){
		printf("Children #%d\n", i);
		printf("==============\n");
		
		do{
			printf("Category (1, 2 or 3): ");
			scanf("%d", &category);
			
			if(category>3 || category<0){
				printf("Invalid!\n");
			}
		}while(category>3 || category<0);
		
		totalfee = CalculateFee(ab, category, totalfee, children, i);
		
	}
	
}

int CalculateFee(char ab, int category, int totalfee, int children, int i){
	
	float Fees[2][3] = {{370, 330, 200}, {350, 300, 150}};
	float discountfee;
	
	switch(ab){
			case 'A':
				printf("The monthly fee is: RM%.2f\n\n", Fees[0][category-1]);
				totalfee+=Fees[0][category-1];
				break;
			case 'B':
				printf("The monthly fee is: RM%.2f\n\n", Fees[1][category-1]);
				totalfee+=Fees[1][category-1];
				break;
	}
	
	if(i==children){
		if(children>1){
			discountfee = totalfee*0.9;
			Output(totalfee, discountfee);
		}	
	}
		
	return totalfee;
	
}

void Output(int totalfee, float discountfee){
	
	printf("Total fee is RM%d\n", totalfee);
	printf("Discounted fee is RM%.2f\n\n", discountfee);
	
}










