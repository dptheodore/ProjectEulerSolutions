#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm>
#include <vector>
using namespace std;
int main(){
	ifstream triFile("p067_triangle.txt");
	string triLine("");
	vector<vector<int>> triangle;

	//pull triangle rows from file
	while(getline(triFile,triLine)){//read each row
		istringstream iss(triLine);
		vector<int> triRow;
		int temp;
		while(iss >> temp){ // read each number
			triRow.push_back(temp);
		}
		triangle.push_back(triRow); //add to main triangle rows
	}


	for (unsigned int row = 1; row < triangle.size(); row++){
	 	triangle[row][0] += triangle[row-1][0];
	 	triangle[row][row] += triangle[row-1][row-1]; // Only way to get to left and right most extremes is by the previous rows left and right most extremes.
	 	for (unsigned int col = 1; col < row; col++ ){
	 		triangle[row][col] += (triangle[row-1][col-1] > triangle[row-1][col]) ? triangle[row-1][col-1] : triangle[row-1][col]; //Middle Paths will always be taken by the previous larger sum
	 	}
	}

		 cout << *max_element(triangle[triangle.size()-1].begin(),triangle[triangle.size()-1].end()) << endl;
	return 0;
}