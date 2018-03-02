#include <iostream>
#include <math.h>
#include <unordered_set>
using namespace std;

unordered_set<int> amicables;

bool isAmicable (int in);
int divisorSum (int i);

//Finds the sum of all amicable numbers below argv[1]
//Amicable := 220 has some divisors (less than 220)
//that sum up to 248, 284 has divisors which sum up to 220
int main(int argc, char const *argv[])
{
	if(argc == 2){
		int sum = 0;
		//Build all amicable numbers
		for (int i = 1; i < stoi(argv[1]);i++){
			isAmicable(i);
		}
		//sum up the found numbers
		for (auto i : amicables){
			sum += i;
		}
		cout << sum << "\n";
	}
	return 0;
}

bool isAmicable (int in){
	if(amicables.count(in) != 0)
		return true;
	
	//Check if amicable
	int twin = divisorSum(in);
	if(in != twin && divisorSum(twin) == in){
		amicables.emplace(twin);
		amicables.emplace(in);
		return true;
	}
	//Not amicable
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