#include <iostream>
using namespace std;
int factorial(int n){
	return (n <= 1) ? 1 : n * factorial(n-1);
}
int getCombos(int numDigits){
	int top = numDigits-1;
	int combos = 0;

	for(int bot = top; bot > 0; bot--){
		combos += factorial(top)/(factorial(bot) * factorial(top-bot));
	}
	
	int** combosArr = new int*[combos];

	for (int i = 0; i < combos; i++){
		combosArr[i] = 
	}

}

int main(){

	//test all combinations of num being prime fam
	//move to next number in ones place
	//repeat til got an eight banger


	
	cout << getCombos(3) << endl;
	return 0;
}

