/*Find first 10 digits of sum of 100 50-digit numbers
The 10 first digits will originate from at most the
12 fist digits of the 100 50-digit numbers. Hence 
one can discard all numbers after the first 12.
Those numbers summated will at most become a 14-digit
number, which can be reprensented by 47-bits. This fits
in a double.
*/
#include <string>
#include <list>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
using namespace std;

int main(int argc, char *argv[]){	
	if(argc == 2){
		fstream fin;
		fin.open(argv[1], ifstream::in);
		string elem;
		vector<double> vec;
		string::size_type sz;
		//Read numbers line by line into array. 
		//Only keep first 12 numbers
		while(!fin.eof()){
			getline(fin,elem);
			elem = elem.substr(0,12);
			cout << elem << "\n";
			vec.push_back(stod(elem, &sz));
		}
		//sum all numbers
		double sum = 0;
		for (int i = 0; i < 100; i++){
			sum += vec[i];
		}
		elem = to_string(sum);
		cout << elem << "\n";
		elem = elem.substr(0,10);
		cout << elem << "\n";
	}
}