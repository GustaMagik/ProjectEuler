#include <iostream>
#include <math.h>
#include <vector>
using namespace std;
vector<int> fifths;

//Finds all numbers which an be be written as a sum
//of their digits to the power of input
int main(int argc, char const *argv[])
{
	if(argc == 2){
		int input = stoi(argv[1]);
		//find ceiling to search and max no digits
		int len = 1, lenCpy = 0;
		int ceil, ceilCpy;
		while(len != lenCpy){
			lenCpy = len;
			ceilCpy = ceil = len*pow(9,input);
			len = 0;
			while(ceilCpy){
				ceilCpy /= 10;
				len++;
			}
		}
		//Find all numbers
		int tmp, sum, ret = 0;
		for(int i = 2; i < ceil+1;i++){
			tmp = i;
			sum = 0;
			while(tmp){
				sum += pow((tmp % 10), input);
				tmp /= 10;
			}
			if(sum == i)
				ret += i;
		}
		cout << ret << "\n";


	}
	return 0;
}
