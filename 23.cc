#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

int divisorSum (int i);
bool isAbundant (int in);

vector <int> abundant;
bool allNums[28124];

int main(int argc, char const *argv[])
{
	if(argc == 2){
		int input = stoi(argv[1]);
		//Calc Abundant numbers
		for (int i = 1; i < input;i++){
			isAbundant(i);
		}
		int sum = 0;
		//find all numbers that can be formed by 2 abundant
		for (int i = 0; i < abundant.size();i++){
			for (int j = i; j < abundant.size(); j++){
					if(abundant[i]+ abundant[j] < input+1){
						allNums[abundant[i]+abundant[j]] = true;
					}else{
						break;
					}
			}
		}
		for (int i = 1; i < input+1;i++){
			if(!allNums[i])
				sum += i;
		}
		cout << sum << "\n";
	}
	return 0;
}

bool isAbundant(int in){
	if(divisorSum(in) > in){
		abundant.push_back(in);
		return true;
	}
	//Not abundant number
	return false;
}

//Find sum of all divisors less than i
int divisorSum (int i){
	//Find sum of divisors
	int sum = 1;
	int sq = sqrt(i);
	if(i == sq*sq){
		sum -= sq;
	}
	for(int d = 2; d <= sq;d++){
		if(i % d == 0)
			sum += d + i/d;		
	}
	return sum;
}