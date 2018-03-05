#include <iostream>
using namespace std;

//calc sum of the diagonals i the 
//spiral input by input square
/* input = 3
7 8 9
6 1 2
5 4 3
output = 25*/
int main(int argc, char const *argv[])
{
	if(argc == 2){
		int input = stoi(argv[1]);
		if(input%2 == 0){
			cout << "only odd numbers allowed\n";
			return 0;
		}
		int sum = 1;
		int add = 1;
		for(int i = 2; i < input+1; i+=2){
			for (int j = 1; j < 5; j++){
				add += i;
				sum += add;
			}
		}
		cout << sum << "\n";
	}
	return 0;
}