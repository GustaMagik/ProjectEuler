#include <iostream>

int main(){
	int a,b,s,t;
	a = 1;
	b = 1;
	t=0;
	s=0;
	while (b < 4000000){
		if (b%2==0){
			s += b;
		}
		t = b;
		b += a;
		a = t;
	}
	std::cout << s << "\n";
	return 0;
}
