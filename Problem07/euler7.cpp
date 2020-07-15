#include <stdio.h>
#include <math.h>
bool isPrime(int num){
	for (int i=2; i<=sqrt(abs(num)); i++){
  	if(num%i == 0) {return false;}
  }
  return true;
}

int main(){
    int pCount = 6;
    int num = 14;
    for (num = 14; num > 0; num++){
	    if(isPrime(num) == true){
  	        pCount++;
            if (pCount == 10001) { break;}
        }
    }
    
    printf("%i", num);
    return 0;
}