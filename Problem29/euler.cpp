#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;
const unsigned long long int LIST_SIZE = 99*99;
const int POW_BOUND = 6; //since 2^7 is 128, no a can be an exponential composition of anything more than a perfect 6th
const int B_BOUND = 100;
unsigned long long int list[LIST_SIZE] = {0};
int listIndex = 0;
int totalSolns = LIST_SIZE;

int getDuplicateCount(int prevPower){
	return ceil(B_BOUND/prevPower)  ;
}

int checkDuplicates(int base){
	int duplicates = 0;
	for (int k = base-1; k >= 2; k--){
		for (double power = 2; power <= POW_BOUND; power++){
			if ( pow(k,power) == base){ //means it is a duplicate, so return the base and power that match this number
				duplicates+=(getDuplicateCount(power)) - 1;
				cout << k << " " << base << " " << duplicates << endl;
			}
		}
	}
	return duplicates;
}

int main(){
	for (int a = 2; a <= 100; a++){
		totalSolns -= checkDuplicates(a);
	}

	cout << totalSolns << endl;
	return 0;
}