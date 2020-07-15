#include <stdio.h>
int main()
{
    int a = 1;
    int b = 2;
    int sum = 2;
    for (int c = a + b; c <= 4000000; c = a + b){
        a = c;
        b = b + c;
        if (a%2 == 0){
            sum+=a;
        }
        if (b%2 == 0){
            sum+=b;
        }
    }
    printf("%i",sum);
    return 0;
}