#include <iostream>
#include <list>
#include <math.h>
int main(){
	int t= 1;
	int i = 2;
	int div=0;
	int most=0;
	while (div < 501){
		div=2;
		t+=i;
		for(int j=2;j<sqrt(t);j++){
			if(t%j==0){div+=2;}
		}
		i++;
	}
	std::cout << t << "\n";

	return 0;
}