#include <stdio.h>

int main(){
	
	int fiction=5, adventure=10, historical=8, thriller=2, economics=6;
	int i, genre, n, id, option, fb, ab, hb, tb, eb;
	float fp=10.5, ap=5.5, hp=9.3, tp=10, ep=7.2, total=0, fpb, apb, hpb, tpb, epb;
	char yn, name[20], option2;
	
	fpb=fb=ab=hb=tb=eb=apb=hpb=tpb=epb=0;
	
	printf("\n\n\t\tWELCOME TO e-LIBRARY\n\n");
	printf("\t\tEnter your name: ");
	scanf("%s", &name);
	printf("\t\tEnter your id: ");
	scanf("%d", &id);
	
	printf("Hello %s!", &name);
	
	printf("\n\n\t\tMAIN MENU\n\n");
	
	printf("1. List Of Books\n2. Borrow Books\n\n=> ");
	scanf("%d", &option);
	
	switch(option){
		case 1:
				printf("\n\t\t\t*****VIEW BOOKS DETAILS*****\n");
			    printf("\n\t\t Book Name : The Sun Also Rises, To Kill A Mockingbird, Jurassic Park");
			    printf("\n\t\t Genre : Fiction ");
		        printf("\n\t\t No. of Copies : 5 each books\n");
		        
		        printf("\n\t\t Book Name : Hatchet, Stuart Little, Julie of the Wolves");
			    printf("\n\t\t Genre : Adventure ");
		        printf("\n\t\t No. of Copies : 10 each books\n");
		        
		        printf("\n\t\t Book Name : Doctor Zhirago, Beloved, The Idiot");
			    printf("\n\t\t Genre : Historical ");
		        printf("\n\t\t No. of Copies : 8 each books\n");
		        
		        printf("\n\t\t Book Name : Gone Girl, The Wife Between Us, Verity");
			    printf("\n\t\t Genre : Thriller ");
		        printf("\n\t\t No. of Copies : 2 each books\n");	
		        
		        printf("\n\t\t Book Name : The Wealth of Nations, The Intelligent Investor, Zero to One");
			    printf("\n\t\t Genre : Economics ");
		        printf("\n\t\t No. of Copies : 6 each books\n\n");
				
				printf("Proceed to borrow book?(y/n)\n=> ");
				scanf("%s", &option2);
				
				if(option2=='y' || option2=='Y'){
					option=2;
				}else{
					printf("**THANK YOU**");
					break;
				}
				
		case 2:
			do{
			printf("\n\n**GENRE LIST**\n");
			for(i=1; i<=5; i++){
				printf("\n%d. ", i);
				if(i==1){
					printf("Fiction\t:%d books available\tRM%.2f", fiction, fp);
				}else if(i==2){
					printf("Adventure\t:%d books available\tRM%.2f", adventure, ap);
				}else if(i==3){
					printf("Historical\t:%d books available\tRM%.2f", historical, hp);
				}else if(i==4){
					printf("Thriller\t:%d books available\tRM%.2f", thriller, tp);
				}else if(i==5){
					printf("Economics\t:%d books available\tRM%.2f", economics, ep);
				}
			}
			
				printf("\n\nEnter genre number you want to borrow\n=> ");
				scanf("%d", &genre);
				
				printf("How many?\n=> ");
				scanf("%d", &n);
				
				if(genre==1){
					fiction-=n;
					fb+=n;
					fpb+=(fp*n);
					total+=fpb;
				}else if(genre==2){
					adventure-=n;
					ab+=n;
					apb+=(ap*n);
					total+=apb;
				}else if(genre==3){
					historical-=n;
					hb+=n;
					hpb+=(hp*n);
					total+=hpb;
				}else if(genre==4){
					thriller-=n;
					tb+=n;
					tpb+=(tp*n);
					total=+tpb;
				}else{
					economics-=n;
					eb+=n;
					epb+=(ep*n);
					total+=epb;
				}
				
				printf("\n\n**SHOPPING CART**\n");
				for(i=1; i<=5; i++){
					printf("\n%d. ", i);
					if(i==1){
						printf("Fiction\t:%d\tRM%.2f", fb, fpb);
					}else if(i==2){
						printf("Adventure\t:%d\tRM%.2f", ab, apb);
					}else if(i==3){
						printf("Historical\t:%d\tRM%.2f", hb, hpb);
					}else if(i==4){
						printf("Thriller\t:%d\tRM%.2f", tb, tpb);
					}else if(i==5){
						printf("Economics\t:%d\tRM%.2f", eb, epb);
					}
				}
				
				printf("\n\nContinue shopping?(y/n)\n=> ");
				scanf("%s", &yn);
			}while(yn=='y');
			
			printf("\n\n**SHOPPING CART**\n");
				for(i=1; i<=5; i++){
					printf("\n%d. ", i);
					if(i==1){
						printf("Fiction\t:%d\tRM%.2f", fb, fpb);
					}else if(i==2){
						printf("Adventure\t:%d\tRM%.2f", ab, apb);
					}else if(i==3){
						printf("Historical\t:%d\tRM%.2f", hb, hpb);
					}else if(i==4){
						printf("Thriller\t:%d\tRM%.2f", tb, tpb);
					}else if(i==5){
						printf("Economics\t:%d\tRM%.2f", eb, epb);
					}
				}
				
			printf("\n\nTax = 5%%\n");
			printf("Total = RM%.2f", total);
			
			break;
	}
	
	return 0;
}
