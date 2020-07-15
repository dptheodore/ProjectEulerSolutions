#include <stdio.h>
bool first20Divis (int num) {
	for (int i = 20; i >=3; i--){
  	if (num % i != 0) {
    	return false;
    }
  }
  return true;
}

int main() {
    for (int i = 2520; i > 0; i ++){
	    if(first20Divis(i) == true){
  	        printf("%i",i); break;
        }
    }
    return 0;
}