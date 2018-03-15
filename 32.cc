#include <iostream>
#include <unordered_set>
#include <math.h>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

unordered_set<int> combinations;

void combiSetup();
bool isPandigital(int p);

/*Obeservations only 4 digit numbers can
have the propery that they toghether with 
their multiplicator and multipicand can be 
pandigital 1 to 9.*/
int main(int argc, char const *argv[])
{
	combiSetup();
	//Calc sum of pantigitals
	int sum = 0;
	for(auto i : combinations){
		if (isPandigital(i))
			sum += i;
	}
	cout << sum << "\n";
	return 0;
}

//The three functions bellow builds all the permutations 
unordered_set<int> rest(unordered_set<int> s, int i){
	s.erase(i);
	return s;
}

void permute(unordered_set<int> s, int num){
	
	if(s.size() == 0){
		combinations.emplace(num);
		return;
	}
	num *= 10;
	for (auto i : s){
		permute(rest(s, i), num+i);
	}
}

void combiSetup(){
	for(int a = 1; a < 7;a++){
		for(int b = a+1; b < 8; b++){
			for (int c = b+1; c < 9; c++){
				for (int d = c+1; d < 10; d++){
					permute({a,b,c,d}, 0);
				}
			}
		}
	}
}

bool isPandigital(int p){
	int tmp;
	string s;
	for(int i = 2; i < sqrt(p); i++){
		if(p % i == 0){//Divisible
			tmp = p / i;
			s = to_string(tmp) + to_string(i) + to_string(p);
			if(s.size() == 9){//9 digits?
				sort(s.begin(),s.end());
				if(s.compare("123456789") == 0)//is pandigital?
					return true;
			}
		}
	}
	return false;
}

