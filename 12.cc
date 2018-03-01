#include <iostream>
#include <list>
#include <math.h>

// Finds the first triangular number with 500 divisors
int main(){
	int currNum = 1;
	int inc = 2;
	int divisors = 0;
	while (divisors < 501){
		divisors=2;
		currNum += inc++;
		for(int j = 2; j < sqrt(currNum); j++){
			if(currNum % j == 0)
				divisors += 2;
		}
	}
	std::cout << currNum << "\n";
	return 0;
}