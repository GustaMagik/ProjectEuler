#include <unordered_set>
#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

unordered_set<int> uPrimes;
vector<int> vPrimes = {2};
void genPrime(int);
bool isCircular(int);

int main(int argc, char const *argv[])
{
	genPrime(1000000);
	int circ = 0;
	for(auto i : uPrimes){
		if(isCircular(i))
			circ++;
	}
	cout << circ << "\n";
	return 0;
}

void genPrime(int max){
	bool b;
	for (int i = 2; i < max; i++){
		b = true;
		for (int j = 0; vPrimes[j] <= sqrt(i); j++){
			if(i % vPrimes[j] == 0){
				b = false;
				break;
			}
		}
		if(b){
			vPrimes.push_back(i);
			uPrimes.emplace(i);
		}
	}
}

int intLenght(int i){
	int len = 0;
	while(i){
		i /= 10;
		len++;
	}
	return len;
}

bool isCircular(int p){
	int len = intLenght(p);
	bool b = true;
	int tmp;
	for(int i = 1; i < len; i++){
		tmp = p % 10;
		p /= 10;
		for(int j = 1; j < len; j++){
			tmp *= 10;
		}
		p += tmp;
		if(uPrimes.count(p) == 0){
			b = false;
			break;
		}
	}
	return b;
}