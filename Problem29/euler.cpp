#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;


const unsigned long long int LIST_SIZE = 99*99;
const int POW_BOUND = 6; //since 2^7 is 128, no a can be an exponential composition of anything more than a perfect 6th
const int B_BOUND = 100;
unsigned long long int list[LIST_SIZE] = {0};
int listIndex = 0;


int isDuplicate(int base){
	for (int k = base-1; k > 2; k--){
		for (double power = 2; power <= POW_BOUND; power++){
			if ( pow(base,1.0/power) == k){ //means it is a duplicate, so return the base and power that match this number
				return power;
			}
		}
	}
	return 0;
}

int getDuplicateCount(int prevPower){
	return B_BOUND/prevPower ;
}

int main(){
	for (int a = 2; a <= 100; a++){
		int power = isDuplicate(a);
		if (power == 0){
			listIndex+=99;
		}
		else{
			listIndex += (99 - getDuplicateCount(power) );
		}
	}

	cout << listIndex << endl;
		return 0;
}