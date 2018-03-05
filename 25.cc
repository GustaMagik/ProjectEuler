#include <iostream>
using namespace std;

//finds the index for the fib with input digits (approx)
int main(int argc, char const *argv[])
{
	if (argc == 2){
		int reach = stoi(argv[1]);
		double base = 144;
		double fib = 1.61803398875;
		int index = 12;
		int digits = 3;
		while (digits < reach){
			index++;
			base *= fib;
			if(base > 1000){
				base /= 10;
				digits++;
			}
		}
		cout << index << "\n";
	}
	return 0;
}