#include <stdio.h>
#include <math.h>
bool isPrime(int num){
	for (int i=2; i<=sqrt(abs(num)); i++){
  	if(num %i == 0) {return false;}
  }
  return true;
}

int main(){
    long long int num = 600851475143;
    long long int pf = 1;
    for (int i = 1; i < num; i++){
        if(num % i == 0){
  	        if(isPrime(num/i) == true){pf = num/i; break;}
  	    }
    }
    printf("%lld", pf);
    return 0;
}