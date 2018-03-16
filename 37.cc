#include <iostream>
#include <math.h>
#include <unordered_set>
#include <vector>
using namespace std;

vector<int> vPrim = {2};
unordered_set<int> uPrim;

void genPrime(int);
bool isTrunk(int);

int main(int argc, char const *argv[])
{
	genPrime(1000000); //Guesswork :(
	int trunk = 11, i = 5, sum = 0;
	while(trunk){
		if(isTrunk(vPrim[i])){
			trunk--;
			sum += vPrim[i];
		}
		i++;
	}
	cout << sum << "\n";
	
	return 0;
}

void genPrime(int n){
	bool b;
	for (int i = 2; i < n; i++){
		b = true;
		for (int j = 0; vPrim[j] <= sqrt(i); j++){
			if(i % vPrim[j] == 0){
				b = false;
				break;
			}
		}
		if(b){
			vPrim.push_back(i);
			uPrim.emplace(i);
		}
	}
}

bool isRightTrunk(int n){
	if(!n)
		return 1;
	
	int m = 0, c = n, d = 1;
	while(c > 10){
		m += (c % 10)*d;
		d *= 10;
		c /= 10;
	}	
	return uPrim.count(n) && isRightTrunk(m);
}

bool isLeftTrunk(int n){
	if(!n)
		return 1;
	return uPrim.count(n) && isLeftTrunk(n/10);
}

bool isTrunk(int n){
	return isRightTrunk(n) && isLeftTrunk(n);
}