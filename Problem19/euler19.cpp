#include <iostream>
using namespace std;
int main(){
   int dayStart = 2; //Jan 1 1901 is a Tuesday
   int dpm[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
   int sunCt = 0;
   for (int yr = 1901; yr <= 2000; yr++){
       dpm[1] = (yr%4 == 0) ? 29 : 28;//acct for leapYr
       for (int m = 0; m < 12; m++){
           if (dayStart%7 == 0){sunCt++;}
           dayStart+= dpm[m];
       }
   }
    cout << sunCt << endl;
    return 0;
}
