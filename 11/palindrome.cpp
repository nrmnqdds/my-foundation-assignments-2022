#include <iostream>
#include <string>

using namespace std;

int main(){
	
	string userword;
	int i, yes=0, no=0;
	
	cout << "Enter a word: ";
	cin >> userword;
	
	for(i=0; i<userword.length(); i++){
		if(userword[i]==userword[userword.length()-i-1]){
			yes++;
		}else{
			no++;
		}
	}
	
	if(no>0){
		cout << "Not palindrome";
	}else{
		cout << "Palindrome!";
	}
	
	return 0;
}
