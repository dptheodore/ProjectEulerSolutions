#include <stdio.h>

int main() {
    int threeCounter = 333;
    int fiveCounter = 199;
    int fifteenCounter = 1000/15;
    int threeSum = 0;
    int totalSum = 0;
    int fiveSum = 0;
    for (int i = 1; i <= threeCounter; i++){
        threeSum = threeSum + 3*i;
    }
    for (int i = 1; i <= fiveCounter; i++){
        fiveSum = fiveSum + 5*i;
    }
    totalSum = threeSum + fiveSum;

    for (int i = 1; i <= fifteenCounter; i++){
        totalSum = totalSum - 15*i;
    }
    printf("%d", totalSum);
return 0;
}