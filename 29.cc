#include <iostream>
#include <math.h>
#include <unordered_set>
using namespace std;
unordered_set<double> res;
//Finds the number of distinct outcomes for
// a pow b : a,b∈[2,input]
int main(int argc, char const *argv[])
{
	if(argc == 2){
		int input = stoi(argv[1])+1;
		for(int i = 2; i < input;i++){
			for (int j = 2; j < input;j++){
				res.emplace(pow(i,j));
			}
		}
		cout << res.size() << "\n";
	}
	return 0;
}