#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>

using namespace std;

void Calculate(float b, int n);
int factorial(int a);
int nCr(int p, int q);

int main(){
	
	int m, n, i=0;
	float b;
	
	ifstream binom;
	binom.open("BINOM.txt");
	
	binom >> m;
	
	cout << " b " << setw(7) << " n " << setw(5) << " (a+b)^n using pow() " << setw(10) << " (a+b)^n using binomial theorem " << setw(10) << " number of terms used " << endl;
	cout << "-------------------------------------------------------------------------------------" << endl;
	
	for(i=1; i<=m; i++){
		binom >> b >> n;
		Calculate(b, n);
	}
	
	binom.close();
	
	return 0;
}

int factorial(int a){
    if(a<=1){
        return 1;
    }else{
        return a*factorial(a-1);
    }
}

int nCr(int p, int q){
    return factorial(p)/(factorial(p-q)*factorial(q));
}

void Calculate(float b, int n){
	
	const int a=1;
	int theorem=n+1, i;
	float anspow, ansbinom=0;
	
	ansbinom=pow(ansbinom, n);
	for(i=1; i<=n; i++){
		ansbinom+=(nCr(n, i))*(pow(a, (n-i)))*(pow(b, i));
	}
	ansbinom+=1;
	anspow = pow((a+b), n);
	
	cout << right << fixed << setprecision(2) << b << setw(5) << n << right << setw(15) << fixed << setprecision(6) << anspow << right << setw(30) << ansbinom << setw(20) << theorem << endl;
	
}




