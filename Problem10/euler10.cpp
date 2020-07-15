#include <iostream>
#include <math.h>
using namespace std;
bool isPrime(int num){
    for(int i =2; i<=sqrt(abs(num)); i++){
    if(num%i == 0) {return false;}
  }
  return true;
}

int main() {
    long long int sum = 0;
    for (long long int i = 2; i<2000000; i++){
        if(isPrime(i)) {sum+=i;}
    }
    cout << sum << endl;
    return 0;
}