#include <iostream>
#include <algorithm>
using namespace std;
int main(){
	int fA[1000] = {0};
	int fB[1000] = {0};
		fA[999]  = 1; //F1 = 1
		fB[999]  = 1; //F2 = 1
	int fC[1000] = {0};
	int fibIndex;

	for (fibIndex = 2; fC[0] == 0; fibIndex++){
		for (int i = 999; i >=0; i--){ // add 2 Fibbies
			fC[i] = fA[i] + fB[i];
		}
		for (int c = 999; c >=0; c--){ // carry over
			if (fC[c] > 9){
			   for (int j = c; j >=0 && fC[j] > 9; j--){
			        fC[j-1] += 1;
			        fC[j] -= 10;
			   }
			}
		}
		copy(begin(fB), end(fB), begin(fA));
		copy(begin(fC), end(fC), begin(fB));
	}

	cout << fibIndex << endl;

	return 0;
}