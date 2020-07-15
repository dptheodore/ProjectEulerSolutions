#include <stdio.h>
#include <math.h>
int numDivs (int triNum){
	int numOfDivs = 3;

	for (int div = 3; div <= sqrt(abs(triNum)); div++){
		if(triNum % div == 0 ){numOfDivs+=2;}
	}
	return numOfDivs;
}

int main(){
	int triNum = 55;
	int nn = 11;
	int ans = 0;

	for (nn; nn > 0; nn++){
		triNum+=nn;
		if(triNum % 2 == 0 && numDivs(triNum) > 500){
			printf("%d", triNum); break;
		}
	}
	return 0;
}