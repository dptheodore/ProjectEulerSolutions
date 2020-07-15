#include <stdio.h>
int main(){
    int sumSq = 0;
    int sqSum = 0;
    
    for (int i= 1; i<=100; i++){
        sumSq+=i;
        sqSum+=i*i;
    }
    
    sumSq *= sumSq;

    printf("%i",(sumSq-sqSum));
    return 0;
}