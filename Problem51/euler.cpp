#include <iostream>
#include <vector>
using namespace std;
vector<int> combination;

int factorial(int n){
	return (n <= 1) ? 1 : n * factorial(n-1);
}


void checkCombo(const vector<int>& v,int numDigits) {
  static int count = 0;
  cout << "combination no " << (++count) << ": [ ";
  for (unsigned int i = 0; i < v.size(); ++i) { 
  	cout << v[i] << " "; 
  }
  cout << endl;
}

void iterateCombos(int offset, int k, int digArr[],int size) {
  if (k == 0) {
    checkCombo(combination,size);
    return;
  }
  for (int i = offset; i <= size - k; ++i) {
    combination.push_back(digArr[i]);
    iterateCombos(i+1, k-1,digArr,size);
    combination.pop_back();
  }
}

void getCombos(int numDigits){
	int top = numDigits-1;
	int combos = 0;
	vector<int> combinations;

	for(int bot = top; bot > 0; bot--){
		combos += factorial(top)/(factorial(bot) * factorial(top-bot));
	}
	
	int digArr[top] = {0};
	for (int i = 0; i < top; i++){
		digArr[i] = i+1;
	}

	for(int k = 1; k <= top; k++){
		iterateCombos(0,k,digArr,top);
	}

	
}



int main(){

	//test all combinations of num being prime fam
	//move to next number in ones place
	//repeat til got an eight banger
	getCombos(3);
	
	return 0;
}

