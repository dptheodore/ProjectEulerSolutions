#include <iostream>
#include <vector>
using namespace std;

int factorial (int n){
	return (n <= 1) ? 1 : n*factorial(n-1);
}

int main(){
	int targetNum = 1e6 - 1;

	vector<int> permDigs{0,1,2,3,4,5,6,7,8,9};
	vector<int> permArr;

	for(int i = 9; i >= 0; i--){
		int digIndex = targetNum / factorial(i);
		targetNum %= factorial(i);
		permArr.push_back(permDigs.at(digIndex));
		permDigs.erase(permDigs.begin()+digIndex);
	}

	for (vector<int>::iterator nt = permArr.begin(); nt != permArr.end(); ++nt){
		cout << *nt ;
	}
	cout << endl;

	return 0;
}