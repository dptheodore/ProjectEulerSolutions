#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>
using namespace std;
int repeatNums (int divisor){
	vector<int> digits;
	int digIndex = 0;
	int pwr = ceil(log10(divisor));
	int dividend = pow(10, pwr);//Need a Power of 10 > the divisor
	while (dividend > 0){//Long Division Process
		int digit = dividend / divisor;
		vector<int>::iterator it = find(digits.begin(),digits.end(), digit);
		if (it == digits.end()){//If digit hasnt been used, add to the dock.
			digits.push_back(digit);
		}
		else{
			return digIndex;
		}

		dividend -= divisor*digit;
		while (dividend < divisor && dividend != 0) {dividend*=10;}
	}
	return digIndex;
}

int main() {
	int longestRepeat = 6;

	for (int d = 11; d< 1000; d++ ){
		int repeatCt = repeatNums(d);
		longestRepeat = (repeatCt > longestRepeat) ? repeatCt : longestRepeat;
	}

	cout << longestRepeat << endl;

	return 0;
}