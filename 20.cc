#include <iostream>
#include <boost/multiprecision/cpp_int.hpp>
using namespace std;
using namespace boost::multiprecision;

//Takes an int A as input and returns the sum of the digits of A! 
int main(int argc, char const *argv[])
{
	if (argc == 2){
		cpp_int fac = 1;
		for(int i = 2; i < stoi(argv[1])+1;i++){
			fac *= i;
		}
		cpp_int sum = 0;
		while(fac != 0){
			sum += fac % 10;
			fac /= 10;
		}
		cout << sum << "\n";
	}
	return 0;
}

