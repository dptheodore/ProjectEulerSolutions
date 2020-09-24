#include <iostream>
using namespace std;

//Same as how many ways to make 200 out of 1,2,5,10,20,50,100, and 200

const int COIN_CT = 8;
const int denoms [COIN_CT] = {1,2,5,10,20,50,100,200};
unsigned long long ways = 0;

int waysOf(int num,int index){
	if(num == 0 || num == 1){
		return 1;
	}
	else if (num < 0){
		return 0;
	}
	else{
		for(int i = index; i >= 0; i--){
			ways += waysOf(num-denoms[i], i-1);

			cout << denoms[i] << " " << ways << " " << i  << endl;
		}
	}
	return ways;
}


int main(){
	cout << waysOf(4,COIN_CT-1) << endl;
	return 0;
}