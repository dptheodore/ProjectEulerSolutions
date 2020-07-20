#include <iostream>
#include <math.h>
#include <vector>
using namespace std;

bool isAbundant(int num){
	int sum = 1;
	for (int i = 2; i <= sqrt(abs(num)); i++){
		if (num%i == 0) {sum += (i == (num/i)) ? i : (i + num/i) ;}
	}
	return sum > num ? true : false;
}
int main(){
	vector<int> abNums;
	vector<int> naNums;
	int naSum = 0;

	for (int num = 1; num<=28123; num++){ //sort nums into abundant and non Ab
		if (isAbundant(num) == true){
			abNums.push_back(num);
		}
		else{
			naNums.push_back(num);
		}
	} 

	int abunSums[28123+1] = {0};
	for (vector<int>::iterator at = abNums.begin(); at!= abNums.end(); ++at){//Generate an abun sum lookup table
		for (vector<int>::iterator at2 = at; at2 != abNums.end(); ++at2){
			if (*at + *at2 <= 28123) {abunSums[*at + *at2] = 1;}
		}
	}

	for (int num = 1; num <=28123; num++){ //compare each number to the lookup table of abundant sums
		if(abunSums[num] == 0) {naSum+=num;}
	}

	cout << naSum << endl;

	return 0;
}