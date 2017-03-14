#include <iostream>
#include <math.h>

int main(){
	int p = 0;
	int r = 0; 
	int t = 0;
	int b = 0;
	int c = 0;
	for (int j = 999; j>99; j--){
		for (int i = j; i>99;i--){
			p=i*j;
			t=p;
			r=0;
			
			while (t != 0){
      			r *= 10;
      			r += t%10;
      			t /= 10;
      		}
      		
      		if (p==r){
      			if (b<r){
      				b = r;
      			}
      			c++; //for fun to see how many palindromes there were
      			
      		}
		}
	}
	std::cout << b << " " << c << "\n";
	return 0;
}