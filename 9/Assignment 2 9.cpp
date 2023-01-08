#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

void UpdateStock(int input);
void UpdatedList();

int Code[5] = {101, 102, 103, 104, 105};
double Price[5] = {1.50, 2.50, 2.20, 3.00, 1.90};
int Quantity[5] = {10, 5, 8, 12, 17};
string Drink[5] = {"Mineral Water", "Coca-cola", "Seven-UP", "Nescafe", "SoyDrink"};
int i;

int main(){
	
	int drinkcode;
	char ans;
	
	cout << "***Vending Machine Inventory System***" << endl << endl;
	cout << setw(10) << left << "Code" << setw(30) << left << "Drink" << setw(10) << "Price" << setw(10) << "Qty" << endl;
	cout << setw(10) << "----" << setw(30) << left << "-----" << setw(10) << "-----" << setw(10) << "---" << endl;	
	
	for(i=0; i<5; i++){
		cout << setw(10) << Code[i] << setw(30) << left << Drink[i] << setprecision(3) << setw(10) << Price[i] << setw(10) << Quantity[i] << endl;
	}
	
	do{
		cout << endl << "Enter drink code you want to update: ";
		cin >> drinkcode;
		
		UpdateStock(drinkcode);
		UpdatedList();
		
		cout << endl << "Do you want to update another drink? ";
		cin >> ans;
	}while(ans=='Y' || ans=='y');
	
	return 0;
}

void UpdateStock(int input){
	
	char update;
	float newprice;
	int newq;
	
	for(i=0; i<=5; i++){
		if(input==Code[i]){
			cout << "Choose to update P-price or Q-quantity: ";
			cin >> update;
			
			switch(update){
				case 'P':
					cout << "Enter new price: ";
					cin >> newprice;
					Price[i] = newprice;
					cout << endl << "Price updated ..." << endl; break;
				case 'Q':
					cout << "Enter new quantity: ";
					cin >> newq;
					Quantity[i] = newq;
					cout << endl << "Quantity updated ..." << endl; break;
				}
				break;
			}else{
				if(i==5){
					cout << endl << "Drink code not found ... " << endl;
				}
			}
		}
		
	}
		
void UpdatedList(){
	
	cout << endl << "***Vending Machine Inventory System***" << endl << endl;
	cout << setw(10) << left << "Code" << setw(30) << left << "Drink" << setw(10) << "Price" << setw(10) << "Qty" << endl;
	cout << setw(10) << "----" << setw(30) << left << "-----" << setw(10) << "-----" << setw(10) << "---" << endl;	
	
	for(i=0; i<5; i++){
		cout << setw(10) << Code[i] << setw(30) << left << Drink[i] << setprecision(3) << setw(10) << Price[i] << setw(10) << Quantity[i] << endl;
	}
	
}







