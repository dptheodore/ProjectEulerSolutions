#include <iostream>
using namespace std;
int main(){
    int HUND_CHAR     = 7;
	int THOU_CHAR     = 11;
	int AND_CHAR      = 3;
	int tensChar[10]  = {0,0,6,6,5,5,5,7,6,6};
	int wordChar[20]  = {0,3,3,5,4,4,3,5,5,4,3,6,6,8,8,7,7,9,8,8};
	int sum = 0;
	for (int i = 0; i < 20; i++){ //0-19
		sum+= wordChar[i];
	}
	for (int num = 20; num < 100; num++){ //20-99
		sum += (tensChar[(int) num/10] + wordChar[num%10]);
	}
	for (int num = 100; num < 1000; num++){//100 - 999
	    int startSum = sum;
	    int hI = (int) num/100;
	    sum += HUND_CHAR + wordChar[hI];
	    int tI = num%100;
	    sum += (tI < 20) ? wordChar[tI] : tensChar[(int) (tI/10)] + wordChar[tI%10];
	    sum+= (num%100 != 0) ? AND_CHAR : 0;
	    if (num == 342) {cout << sum - startSum << endl;}
	    
	}
    sum+= THOU_AMT;
	cout << sum << endl;
	return 0;
}