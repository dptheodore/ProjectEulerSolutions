#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
const vector<string> explode(const string& s, const char& c)
{
	string buff{""};
	vector<string> v;
	
	for(auto n:s)
	{
		if(n != c) buff+=n; else
		if(n == c && buff != "") { v.push_back(buff); buff = ""; }
	}
	if(buff != "") v.push_back(buff);
	
	return v;
}


int letterVal (char letter){
	return (int) letter - 64;
}

int alphaValue(string name){

	int alphaValue = 0;
	for (string::iterator it = name.begin(); it!=name.end(); ++it){
		alphaValue+=letterVal(*it);
	}

	return alphaValue;
}

int main(){
	ifstream nameFile;
	string nameStr("");
	int nameScore = 0;

	//pull string from file
	nameFile.open("p022_names.txt");
	if (!nameFile){
		cout << "Can't open name file";
		exit(1);
	}
	else {nameFile >> nameStr;}

	//sanitize string and sort
	nameStr.erase(remove(nameStr.begin(), nameStr.end(), '\"'), nameStr.end() );
	vector<string> namesVec{explode(nameStr,',')};
	sort(namesVec.begin(),namesVec.end()); 

	//sum the namescores
	int nameIndex = 1;
	for (vector<string>::iterator it = namesVec.begin(); it!=namesVec.end(); it++){
		string name = *it;
		nameScore += nameIndex * alphaValue(name);
	}


	cout << nameScore << endl;
	return 0;
}