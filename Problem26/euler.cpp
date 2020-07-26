#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>
using namespace std;
int repeatLength (int divisor){
	vector<int> remainders;
	int dividend = 1;
	int position = 0;

	while (dividend > 0){
		dividend*=10;
		position++;
		int remainder = dividend % divisor;

		vector<int>::iterator it = find(remainders.begin(),remainders.end(), remainder);

		if (it == remainders.end()){//If remainder hasnt been used, add to the vec
			remainders.push_back(remainder);
		}
		else{ //If this remainder has already been added in, then we have completed a full cycle of the repeating decimals
			return (position - 1 - (distance(remainders.begin(),it)) );
		}

		dividend = remainder;
	}
	return 0; //If dividend = 0, then we have a non repeating number and thus shouldnt factor into longest sequence
}

int main() {
	int topSeqLength = 6;
	int topD = 11;
	for (int d = 1000; d > 11; d-- ){
		if (topSeqLength >= d) { topD = d + 1; break;} //largest Repeat Sequence for any d is d-1, so we can break if d hits our topSeqLength sequence
		int repeatCt = repeatLength(d);
		topSeqLength = (repeatCt > topSeqLength) ? repeatCt : topSeqLength;
	}
	cout << topD << endl;
	return 0;
}