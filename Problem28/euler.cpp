#include <iostream>
#include <math.h>
using namespace std;
//top right corner is always a perfect square, so back-calculate the diags on each row from the perfect square
//to back calc just multiply 2 by (rowCt-1)
int main(){
	int diagSum = 1;
	int perfSq = 1;
	for (int row = 2; row <= 501; row++){
		perfSq+=2;
		int offset = 2*(row-1);
		int topRight = pow(perfSq,2);
		int topLeft = topRight - offset;
		int btmLeft = topRight - offset*2;
		int btmRight = topRight - offset*3;
		diagSum+=topRight + topLeft + btmLeft + btmRight;
		if (row == 5){ cout << topRight << " " << topLeft << " " << btmLeft << " " << btmRight << endl;}
	}

	cout << diagSum << endl;

	return 0;
}