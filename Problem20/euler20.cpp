#include <iostream>
using namespace std;
int main(){
	
	int num1[300] = {0};
	num1[297] = 1; // makes 100
    
	for (int num = 99; num >=2; num--){
		for (int c = 299; c >=0; c--){ // multiply out
			num1[c] *= num;
		}
		
		for (int c = 299; c >=0; c--){ // carry over
			if (num1[c] > 9){
			   for (int j = c; j >=0 && num1[j] > 9; j--){
			        int carry = num1[j];
			        num1[j] = carry%10;
			        carry /= 10;
			        for(int k = 1; carry > 0; k++){
			            int digit = carry%10;
			            carry/=10;
			            num1[j-k] += digit;
			        }
			   }
			}
		}
	}
	int sum = 0;
	for (int c = 299; c >= 0; c--){ // sum digits
		sum += num1[c];
	}
	cout << sum << endl;
	return 0;
}
