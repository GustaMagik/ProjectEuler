#include <iostream>
#include <list>
int main(){
	int ans = 0;
	int c = 3;
	long long int sum =0;
	bool not_prime = false;
	std::list<int> primes;
	primes.push_back(2);
	while (c < 2000000){
		
		not_prime = false;
		for (std::list<int>::iterator it=primes.begin(); it != primes.end(); it++){
			if (!(c%*it)){
				not_prime=true;
				break;
			}
		}
		if(!not_prime){
			primes.push_back(c);
			std::cout << c << "\n";
		}
		c+=2;
	}
	for (std::list<int>::iterator it=primes.begin(); it != primes.end(); it++){
    	std::cout << *it << "\n";
    	sum += *it;
	}
	std::cout << sum  << "\n";
	return 0;
}