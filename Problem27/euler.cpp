#include <iostream>
#include <algorithm>
using namespace std;
//b has to be prime for n = 0 to satisfy being prime
//a might not need to be prime, since it isn't for one of the examples
//since b is always odd (only even prime is b=2 and it will not produce a long consecutive prime list***), we need n(n+a) to be even
//due to integer multiplication parity, this means that n and (n+a) cannot both be odd
//When n is even, a's parity is irrelevant
//When n is odd, we need "a" to also be odd, meaning "a" will always need to be odd

//***b=2 doesnt produce a long consecutive prime list, because that would require n(n+a) to always be odd
//this would require both n and n+a to always be odd due to multiplication parity properties
//for consecutive values of n this will be impossible, it will fail once n=2 for every value of a***



int primes1000[] = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61 
,67,71,73,79,83,89,97,101,103,107,109,113,127,131,137,139,149,151 
,157,163,167,173,179,181,191,193,197,199,211,223,227,229,233,239
,241,251,257,263,269,271,277,281,283,293,307 
,311,313,317,331,337,347,349,353,359 
,367,373,379,383,389,397,401,409,419 
,421,431,433,439,443,449,457,461,463 
,467,479,487,491,499,503,509,521,523 
,541,547,557,563,569,571,577,587,593 
,599,601,607,613,617,619,631,641,643 
,647,653,659,661,673,677,683,691,701 
,709,719,727,733,739,743,751,757,761 
,769,773,787,797,809,811,821,823,827 
,829,839,853,857,859,863,877,881,883 
,887,907,911,919,929,937,941,947,953 
,967,971,977,983,991,997};

bool isPrime(int num){
    for(int i =2; i<=sqrt(abs(num)); i++){
    if(num%i == 0) {return false;}
  }
  return true;
}

int main(){ 
	int topA = 1;
	int topB = 41;
	int topN = 39;
	for (int a = -999; a <1000; a+=2){
		for (unsigned int i = 0; i < sizeof(primes1000)/sizeof(primes1000[0]); i++){
			int b = primes1000[i];
			for (int parity = 0; parity < 2; parity++){
				int sign = (parity == 0) ? 1 : -1;
				int n = 0;
				while(isPrime(n*n + n*a + b*sign)){
					n++;
				}
				if (n > topN){
					topA = a;
					topB = b * sign;
					topN = n;
				}
			}
		}
	}

	cout << topA * topB << endl;

	return 0;
}