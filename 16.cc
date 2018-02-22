//Power sum
#include <boost/multiprecision/cpp_int.hpp>
#include <iostream>
using namespace std;
using namespace boost::multiprecision;

int main(int argc, char const *argv[])
{
	//Construct 2^1000
	cpp_int num = 2;
	num = pow(num,1000);
	//Sum all digits 
	cpp_int sum = 0;
	while (num != 0){
		sum += num % 10;
		num /= 10;
	}
	cout << sum << "\n";
	return 0;
}