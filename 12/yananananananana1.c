#include <stdio.h>
#include <string.h>
#include <ctype.h>

float AssesmentCalculate();
float AdmissionCalculate(char program[20], char student[10], int year, int children);
float SchoolCalculate(char program[20], char malaysian[5], int year, int n);
int Date(char quarter[30]);
void Display(float registrationfees, float assesssmentfee, float admissionfee, float schoolfee, float totalpayablefees, char lastdate[30]);

float registrationfees=0, assessmentfee=0, admissionfee, schoolfee, totalpayablefees;
char lastdate[30];

int main(){
	
	char date[10], quarter[30], quarterr[30], name[30], malaysian[5], program[20], student[10];
	int children, i, n, year;
	
	printf("Date: ");
	scanf("%s", &date);
	
	printf("Fees: ");
	scanf("%s", &quarter);
	for (i=0; quarter[i]!='\0'; i++) {
        quarter[i] = tolower(quarter[i]);
    }
	scanf("%s", &quarterr);
	
	printf("Name: ");
	scanf("%s", &name);
	
	printf("Malaysian? ");
	scanf("%s", &malaysian);
	for (i=0; malaysian[i]!='\0'; i++) {
        malaysian[i] = tolower(malaysian[i]);
    }
    
	printf("Program(Primary, Secondary, International): ");
	scanf("%s", &program);
    for (i=0; program[i]!='\0'; i++) {
        program[i] = tolower(program[i]);
    }
    printf("Year: ");
	scanf("%d", &year);
	
	printf("New/Current student: ");
	scanf("%s", &student);
    for (i=0; student[i]!='\0'; i++) {
        student[i] = tolower(student[i]);
    }
    
	printf("Number of children in Berjaya Private School: ");
	scanf("%d", &children);
	
	n=Date(quarter);
	schoolfee=SchoolCalculate(program, malaysian, year, n);
	admissionfee=AdmissionCalculate(program, student, year, children);
	
	totalpayablefees=registrationfees+assessmentfee+admissionfee+schoolfee;
	
	Display(registrationfees, assessmentfee, admissionfee, schoolfee, totalpayablefees, lastdate);
	
	return 0;
}

float SchoolCalculate(char program[20], char malaysian[5], int year, int n){
	
	if(strcmp(program, "primary")==0){
		switch(year){
			case 1: case 2: case 3:
				schoolfee=1350*n; break;
			case 4: case 5: case 6:
				schoolfee=1550*n; break;
		}
	}else if(strcmp(program, "secondary")==0){
		switch(year){
			case 1: case 2:
				schoolfee=1575*n; break;
			case 3:
				schoolfee=1650*n; break;
			case 4: case 5:
				schoolfee=1925*n; break;
		}
	}else if(strcmp(program, "international")==0){
		switch(year){
			case 7:
				if(strcmp(malaysian, "yes")==0){
					schoolfee=2200*n;
				}else{
					schoolfee=2600*n;
				} break;
			case 8: case 9:
				if(strcmp(malaysian, "yes")==0){
					schoolfee=2400*n;
				}else{
					schoolfee=2800*n;
				} break;
			case 10: case 11:
				if(strcmp(malaysian, "yes")==0){
					schoolfee=2600*n;
				}else{
					schoolfee=3000*n;
				} break;
			case 12:
				if(strcmp(malaysian, "yes")==0){
					schoolfee=3400*n;
				}else{
					schoolfee=4100*n;
				} break;
			default:
				if(strcmp(malaysian, "yes")==0){
					schoolfee=3600*n;
				}else{
					schoolfee=4300*n;
				} break;
		}
	}
	
	return schoolfee;
}

float AdmissionCalculate(char program[20], char student[10], int year, int children){
	
	if(strcmp(program, "primary")==0 || strcmp(program, "secondary")==0){
		registrationfees=500;
		if(strcmp(student, "new")==0){
			assessmentfee=150;
			switch(children){
				case 1:
					admissionfee=2000; break;
				case 2:
					admissionfee=1000; break;
				case 3:
					admissionfee=500; break;
				default:
					admissionfee=0;
			}
		}
	}else if(strcmp(program, "international")==0){
		registrationfees=650;
		if(strcmp(student, "new")==0){
			assessmentfee=150;
			
			switch(year){
				case 7: case 8: case 9:
					switch(children){
						case 1:
							admissionfee=4000; break;
						case 2:
							admissionfee=2000; break;
						case 3:
							admissionfee=1000; break;
						default:
							admissionfee=0;
					} break;
				case 10: case 11:
					admissionfee=2000; break;
				case 12: case 13:
					admissionfee=0; break;
			}
		}
	}
	
	return admissionfee;
}

int Date(char quarter[30]){
	
	int n;
	
	if(strcmp(quarter, "first")==0){
		n=1;
		strcpy(lastdate, "31st March");
	}else if(strcmp(quarter, "second")==0){
		n=2;
		strcpy(lastdate, "30th June");
	}else if(strcmp(quarter, "third")==0){
		n=3;
		strcpy(lastdate, "30th September");
	}else if(strcmp(quarter, "fourth")==0){
		n=4;
		strcpy(lastdate, "28th January");
	}
	
	return n;
}

void Display(float registrationfees, float assesssmentfee, float admissionfee, float schoolfee, float totalpayablefees, char lastdate[30]){
	
	printf("Payable Fees\n");
	printf("\tRegistration fees:\tRM%.2f\n", registrationfees);
	printf("\tAssessment fee:\t\tRM%.2f\n", assessmentfee);
	printf("\tAdmission fee:\t\tRM%.2f\n", admissionfee);
	printf("\tSchool fee:\t\tRM%.2f\n", schoolfee);
	printf("\tTotal Payable Fees during registration: RM%.2f\n", totalpayablefees);
	printf("\tNext payment fee: RM%.0f latest by %s", schoolfee, lastdate);
	
}
