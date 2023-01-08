/* Name : MUHAMMAD NURIMAN QUDDUS BIN FAIZUL
Student ID : 212924
Lab Group : 408
Purpose : Hands-on Test #2
*/

#include <stdio.h>

void Selection();
void DisplayData();
void Search();
void Exit();

int main(){
	
	printf("\tRH - relative humidity in : 15.0 to 100\n\n");
	
	printf("1. View analysis\n");
	printf("2. Search\n");
	printf("3. Exit Program\n");
	
	Selection();
	
	return 0;
}

void Selection(){
	
	int i, option;
	
	do{
		printf("\nSelect option:- ");
		scanf("%d", &option);
		
		if(option==1){
			DisplayData();
		}else if(option==2){
			Search();
		}

	}while(option!=3);

	Exit();
}

void DisplayData(){
	
	int IDNo[5] = {201, 202, 203, 204, 205};
	int day[5][5] = {{51, 74, 99, 97, 80}, {63, 86, 27, 29, 51}, {40, 51, 38, 72, 50}, {27, 17, 21, 19, 21}, {47, 35, 44, 40, 41}};
	int x, y;
	
	printf("No.\tID No.\tWeek No.\tD1\tD2\tD3\tD4\tAverage\n");
	
	for(x=0; x<5; x++){
		printf("%d\t%d\tWeek %d\t\t", x+1, IDNo[x], x+1);
		for(y=0; y<5; y++){
			printf("%d\t", day[x][y]);
		}
	printf("\n");
	}
	
}

void Search(){
	
	int IDNo[5] = {201, 202, 203, 204, 205};
	int day[5][5] = {{51, 74, 99, 97, 80}, {63, 86, 27, 29, 51}, {40, 51, 38, 72, 50}, {27, 17, 21, 19, 21}, {47, 35, 44, 40, 41}};
	int id, i, j;
	
	printf("Enter id No.:- ");
	scanf("%d", &id);
			
	for(i=0; i<5; i++){
		if(id==IDNo[i]){
			printf("\n--- Humidity Levels for Week %d ---\n\n", i+1);
			
			for(j=0; j<4; j++){
				printf("Sample %d: %d\t", j+1, day[i][j]);
				
				if(day[i][j]>=0 && day[i][j]<=44){
					printf("Low Humidity\n");
				}else if(day[i][j]>=45 && day[i][j]<=55){
					printf("Recommended Humidity\n");
				}else if(day[i][j]>=56 && day[i][j]<=100){
					printf("High Humidity\n");
				}
				
			}
		}
	}
	
}

void Exit(){
	printf("\nExit program. Thank you");
}





