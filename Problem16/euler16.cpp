#include <iostream>
using namespace std;
int main(){
	
	int num1[334] = {0};
	num1[333] = 2;
    
	for (int pow = 2; pow <= 1000; pow++){
		for (int c = 333; c >=0; c--){ // multiply out
			num1[c] *= 2;
		}
		
		for (int c = 333; c >=0; c--){ // carry over
			if (num1[c] > 9){
			   for (int j = c; j >=0 && num1[j] > 9; j--){
			        num1[j-1] += 1;
			        num1[j] -= 10;
			   }
			}
		}
	}

	int sum = 0;
	for (int c = 333; c >= 0; c--){ // sum digits
		sum += num1[c];
	}
	cout << sum << endl;
	return 0;
}