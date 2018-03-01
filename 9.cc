#include <iostream>

int main(){
	int res[] = {0,0,0};
	for (int a = 3;a<998;a++){
		for (int b = 2;b<a;b++){
			for (int c = 1; c<b;c++){
				if (((a*a)==(b*b+c*c)) && ((a+b+c)==1000)){
					std::cout << a*b*c << "\n";
					return 0;
				}
			}
		}
	}
	return 0;
}