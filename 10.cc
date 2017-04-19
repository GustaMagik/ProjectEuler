#include <iostream>
#include <list>
#include <cmath>
int main(){
	int ans = 0;
	long long int sum = 2;
	bool prime = false;
	std::list<int> primes;
	primes.push_back(2);
	for (int c = 3; c < 2000000; c += 2){
		
		prime = true;
		for (std::list<int>::iterator it=primes.begin(); it != primes.end(); it++){
			
			if (c % *it == 0) {
				prime=false;
				break;
			}
			if (sqrt(c) < *it) { break; }
		}
		if(prime){
			primes.push_back(c);
			//sum += c;
		}
	}
	std::cout << sum  << "\n";
	return 0;
}