#include <iostream>
using namespace std;
bool isPyTrip(int a, int b, int c){
	if (a*a + b*b == c*c) {return true;}
  return false;
}
int main() {
    int a = 3;
    int b = 4;
    int c = 5;
    int product = 0;
    for (a = 4; a<1000; a++){
	    int diff = 1000 - a;
        for (b = 5; b < diff; b++){
  	        c = diff-b;
            if (isPyTrip(a,b,c) == true) {product=a*b*c; break;}
        }
    }
    cout << product << endl;
    return 0;
}