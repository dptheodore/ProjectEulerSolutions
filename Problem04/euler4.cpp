#include <stdio.h>
#include <string>
bool isPalindrome(int num){
  std::string s = std::to_string(num);
  for (int i = 0; i< s.length(); i++){
    if (s[i] != s[s.length()-1-i]) {return false;}
  }
  return true;
}
int main() {
    int n1 = 999; int n2=999; int topDrome = 0;
    for (int n1 = 100; n1 <=999; n1++){
	    for (int n2 = 100; n2 <=999; n2++){
  	        if (isPalindrome(n1*n2) == true && topDrome < n1*n2) {topDrome = n1*n2;}
        }
    }
    printf("%i", topDrome);
    return 0;
}