#include <iostream>
using namespace std;


// ab/bc = a/c or ab/cb = a/c or ba/bc = a/c
// denom > num
bool isProperFrac(int num, int den){
	return num < den ? 1 : 0;
}


int gcd(int a, int b) {
   if (b == 0)
   return a;
   return gcd(b, a % b);
}

int simplifyDenom(int num, int denom){
	return denom / gcd(num,denom);
}


int cancelFractions() {

	int numProd = 1;
	int denProd = 1;
	int count = 0;


	for(int a = 1; a <= 9; a++){
		for(int b = 1; b <= 9; b++){
			for(int c = 1; c <= 9 ; c++){
				for(int vers = 0; vers < 3 && count < 4; vers++){
					int num = 0;
					int den = 0;

					if (vers == 0){
						num = a*10 + b;
						den = b*10 + c;
					}

					if (vers == 1){
						num = a*10 + b;
						den = c*10 + b;
					}

					if (vers == 2){
						num = b*10 + a;
						den = b*10 + c;
					}

					float frac1 = (float)num/(float)den;
					float frac2 = (float)a/(float)c;

					if (isProperFrac(num,den) == 1 && frac1 == frac2 ){
						numProd *= num;
						cout << num << " " << den << " " << endl;
						denProd *= den;
						count++;
					}

				}

			}
		}
	}

	return simplifyDenom(numProd,denProd);
}




int main() {

	int denomSum = 0;

	denomSum = cancelFractions();
	cout << denomSum << endl;
	return 0;
}