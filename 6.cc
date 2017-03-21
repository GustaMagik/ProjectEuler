#include <iostream>

int main(){
	int a = 10100/2;
	int sum = 0;
	for(int i = 1; i < 101; i++){
		sum += (i*i);
	}
	sum = (a*a)-sum;

	std::cout << sum << "\n";
	return 0;
}