#include <stdio.h>
int Menu();
void Check(int);

int main(){
	
	int choice;
	char yn;
	
	do{
		printf("\nWelcome to Kolej Komuniti Paya Besar\n");
		printf("++++++++++++++++++++++++++++++++++\n");
		choice = Menu();
		Check(choice);
		
		printf("\nDo you want to continue?: ");
		scanf("%s", &yn);
		
	}while(yn=='Y' || yn=='y');
	
	return 0;
}

int Menu(){
	
	char Course_Name[4][20] = {"Interior Design", "Culinary", "Games Art", "Fashion"};
	int i, course;
	
	printf("\nYou may choose from the following Course:\n");
	
	for(i=0; i<4; i++){
		printf("%d. %s\n", i+1, Course_Name[i]);
	}
	
	do{
		printf("\nChoose course to enroll: ");
		scanf("%d", &course);
		
		if(course>4 || course<1){
			printf("Please try again.");
		}
	}while(course>4 || course<1);
	
	return course;
}

void Check(int choice){
	
	float fee[4] = {330, 125, 520, 350};
	int Maximum[4] = {30, 30, 30, 60};
	int Minimum[4] = {12, 10, 30, 59};
	int i, newclasssize;
	
	
	for(i=0; i<4; i++){
		if(choice==i+1){
			if(Maximum[i]==Minimum[i]){
				printf("Course chosen is already FULL\n");
			}else{
				printf("Fee amount is RM%.2f\n", fee[i]);
				newclasssize = Minimum[i]+1;
				printf("Class size is now %d\n", newclasssize);
			}
		}
	}
	
	
}


