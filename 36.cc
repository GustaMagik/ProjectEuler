#include <iostream>
#include <boost/multiprecision/cpp_int.hpp>
#include <math.h>
using namespace std;
using namespace boost::multiprecision;

bool isPalindrome (cpp_int);
cpp_int toBin (cpp_int);

int main(int argc, char const *argv[])
{
	int sum = 0;
	for(int i = 1; i < 1000000; i++){
		if(isPalindrome(i) && isPalindrome(toBin(i)))
			sum += i;
	}
	cout << sum << "\n";
	return 0;
}

bool isPalindrome(cpp_int i){
	cpp_int rev = 0, org = i;
	while(i){
		rev *= 10;
		rev += i % 10;
		i /= 10;
	}
	return org == rev;
}

cpp_int toBin (cpp_int i){
	cpp_int bin = 0, tmp = 1;
	while(i){
		if(i % 2){
			bin = bin + tmp; 
		}
		i /= 2;
		tmp *= 10;
	}
	return bin;
}
