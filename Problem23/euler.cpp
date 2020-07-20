#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

bool isAbundant(int num){
	int sum = 1;
	for (int i = 2; i <= sqrt(abs(num)); i++){
		if (num%i == 0) {sum += (i == (num/i)) ? i : (i + num/i) ;}
	}
	return sum > num ? true : false;
}
	
bool isAbPair(int naNum, vector<int> abNums){
	for (vector<int>::iterator at = abNums.begin(); at != abNums.end() && *at < naNum; ++at){
		int num = naNum - *at;
		if ( binary_search(at, abNums.end(), num)){return true;}
	}
	return false;
}


int main(){
	vector<int> abNums;
	vector<int> naNums;
	int naSum = 0;

	for (int num = 1; num<=28123; num++){ //sort nums into abundant and non Ab
		if (isAbundant(num) == true){
			abNums.push_back(num);
//
			cout << num << " " ;
		}
		else{
			naNums.push_back(num);
		}
	} 




	for (vector<int>::iterator nt = naNums.begin(); nt != naNums.end(); ++nt){
		naSum += (isAbPair(*nt, abNums) == true) ? 0 : *nt;
	}

	cout << naSum << endl;

	return 0;
}