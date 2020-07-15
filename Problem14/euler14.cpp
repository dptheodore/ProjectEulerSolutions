#include <stdio.h>
using namespace std;
int chain(unsigned long long int num){
	int length = 0;
	while (num > 1){
		num = (num % 2 == 0) ? num/2 : 3*num + 1;
		length++;
	}
	return length;
}


int main(){
	unsigned long long int topChainNum = 13;
	int topLength = 10;
	for (int currNum = 14; currNum <= 1000000; currNum++){
		int currLength = chain(currNum);
		if (currLength > topLength){
			topChainNum = currNum;
			topLength 	= currLength;
		}
	}
	printf("%lld , %d\n", topChainNum, topLength);
	return 0;
}