#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>
#include <cctype>
using namespace std;
vector<string> names;
int alphaValue(string name);

int main(int argc, char const *argv[])
{
	if (argc == 2){
		fstream fin;
		fin.open(argv[1],ifstream::in);
		string elem;
		while(getline(fin,elem,',')){
			elem.erase(remove(elem.begin(),elem.end(),'"'),elem.end());
			names.push_back(elem);
		}


		//Read in names to "names"
		sort(names.begin(),names.end());
		
		//Calc sum of "name-values"
		int sum = 0;
		for(int i = 0; i < names.size(); i++){
			sum += (i+1)*alphaValue(names[i]);
		}
		cout << sum << "\n";

	}
	return 0;
}

int alphaValue (string name){
	int value = 0;
	char tmp;
	for(auto &i : name){
		tmp = tolower(i);
		value += tmp - 96;
	}
	return value;
}