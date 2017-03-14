#include <iostream>
#include <math.h>

int main(){
	double a,b;
	a = 2;
	b = 600851475143;
	while (b != a){
		
		if (fmod(b,a)==0){
			b=b/a;
			a--;
			
		}
		a++;
	}
	std::cout << a << "\n";
	return 0;
}