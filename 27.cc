#include <iostream>
#include <math.h>
#include <vector>
#include <unordered_set>
using namespace std;
unordered_set<int> primeShadow;
vector<int> primes = {2};
int maxPrime = 2;
int b, a, maxA, maxB, seq, maxSeq = 0;

void morePrimes(int stop);
int seqLen(int a, int b);

/*Program that finds the values of a & b in the formula
n^2 + an + b such that consecutive values of n (starting = 0)
produces prime numbers. Specifically, the longest sequence 
such that |a| < 1000 |b|<= 1000.
OBSERVATIONS:
n=0 is just b => b is prime
n=1 is 1 + a + b => search a in range [-b,999]*/
int main(int argc, char const *argv[])
{
	//Precompute primes up until 1000
	morePrimes(1000);
	int maxInd = primeShadow.size();
	// Set b = prime
	for(int i = 0; i < maxInd; i++){
		b = primes[i+1];
		//Try a's
		for (int a = -b; a < 1000; a++){
			seq = seqLen(a,b);
			if (maxSeq < seq){
				maxA = a;
				maxB = b;
				maxSeq = seq; 
			}
		}
	}
	cout << maxA*maxB << "\n";
	return 0;
}

//Calc length of prime sequence with a and b as params
int seqLen(int a , int b){
	int val, n = 0, len = 0;
	bool p = true;
	while(p){
		val = n*n + a*n + b;
		if(maxPrime < val)
			morePrimes(val);
		if(primeShadow.count(val) == 0)
			p = false;
		len++;
		n++;
	}
	return len;
}

//Calculates primes in range start to stop, requires an array
//prefilled with primes up until start.
void morePrimes(int stop){
	for (int i = maxPrime; i <= stop;i++){
		bool b = true;
		for (int j = 0; primes[j] <= sqrt(i);j++){
			if(i % primes[j] == 0){
				b = false;
				break;
			}
		}
		if(b){
			primes.push_back(i);
			primeShadow.emplace(i);
		}
	}
	maxPrime = stop; // Save the maximum searched number
}