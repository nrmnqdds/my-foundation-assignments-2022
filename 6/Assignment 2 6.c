#include <stdio.h>
#include <string.h>

int Search(int);

int main(){
	
	char Destination[4][20] = {"S-Setiawangsa", "B-Bangsar", "M-Masjid Jamek", "K-Kelana Jaya"};
	char dest;
	int indexvalue, i, destindex;
	
	printf("WELCOME TO LRT SYSTEM\n\n");
	
	for(i=0; i<4; i++){
		printf("%s\n", Destination[i]);
	}
	
	do{
		printf("\nChoose the destination: ");
		scanf("%s", &dest);
		
		if(dest!='S' && dest!='B' && dest!='M' && dest!='K'){
			printf("Invalid");
		}
	}while(dest!='S' && dest!='B' && dest!='M' && dest!='K');
	
	switch(dest){
		case 'S':
			destindex=0; break;
		case 'B':
			destindex=1; break;
		case 'M':
			destindex=2; break;
		case 'K':
			destindex=3; break;
	}
	
	indexvalue = Search(destindex);
	
}

int Search(int destindex){
	
	char Destination[4][20] = {"Setiawangsa", "Bangsar", "Masjid Jamek", "Kelana Jaya"};
	int Distance[4] = {40, 4, 16, 16};
	float Fee[4] = {3.5, 1.2, 2, 1.8};
	int j, i;
	
	printf("\nThe details of your destination:\n\n");
	for(i=0; i<4; i++){
		if(destindex==i){
			j=i;
			printf("Destination\tDistance (km)\tFare(RM)\n");
			printf("%s\t\t%d\t\tRM%.2f", Destination[i], Distance[i], Fee[i]);
		}
	}
	
	return j;
}



