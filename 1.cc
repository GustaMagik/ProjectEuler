#include <iostream>
int main(){
	int a, b, c, sum;
	a=999/3;
	b=999/5;
	c=999/15;
	sum = ((((a+1)*3*a)/2)+(((b+1)*5*a)/2)-(((c+1)*15*c)/2));
	std::cout << sum;
	return 0;
}