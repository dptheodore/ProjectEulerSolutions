#include <iostream>
using namespace std;

//Same as how many ways to make 200 out of 1,2,5,10,20,50,100, and 200

const int COIN_CT = 8;
const int denoms [COIN_CT] = {1,2,5,10,20,50,100,200};


int waysOf(int num,int index){
	int ways[201] = {0};
	ways[0] = 1;

	for (int i = 0; i <= index; i++){
		for (int j = denoms[i]; j <= num; j++){
			ways[j] += ways[j-denoms[i]];
		}
	}

	return ways[200];
}


int main(){
	cout << waysOf(200,COIN_CT-1) << endl;
	return 0;
}