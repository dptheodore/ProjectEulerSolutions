#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;

const unsigned int U_BOUND = 295245; //This is 9^5 * 5


bool fiveRootSum (int n){
	int num = n;
	int sum = 0;
	while(num > 0){
		int digit = (num%10);
		sum += pow(digit,5);
		num/=10;
	}

	return (sum == n) ? true : false;

}

int main(){

	int fiveDigSum = 0;
	for(unsigned int i = 2; i <= U_BOUND; i++){
		if (fiveRootSum(i) == 1){
			fiveDigSum+=i;
		}
	}
	cout << fiveDigSum << endl;

	return 0;
}