#include <iostream>
#include <math.h>
using namespace std;
int divisorSum (int num){
	int divSum = 1;
	for (int div = 2; div <= sqrt(abs(num)); div++){
		if(num % div == 0 ){divSum+=(div + num/div);}
	}
	return divSum;
}

int main(){
	int sum = 0;
	int divSum[10002] = {0};

	for (int i = 1; i <=10000; i++){
		divSum[i] = divisorSum(i);
	}

	for (int i = 2; i <= 10000; i++){
		int j = divSum[i];
		if (divSum[i] <= 10000 && i != j && i == divSum[j] && j == divSum[divSum[j]]){
			sum += divSum[i];
		}
	}

	cout << sum << endl;
	return 0;
}