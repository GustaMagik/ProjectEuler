#include <vector>
#include <iostream>
using namespace std;

vector<int> fac;
int factorial (int n);
bool isDigiFac (int a);

int main(int argc, char const *argv[])
{
	for(int i = 0; i < 10; i++){
		fac.push_back(factorial(i));
	}
	
	int sum = 0, i = 10, it = 0;
	while(it < 100000){
		if(isDigiFac(i)){
			sum += i;
			it = 0;
		}
		i++; it++;
	}
	cout << sum << "\n";
	return 0;
}

int factorial (int n){
	if (n < 2)
		return 1;
	return n *factorial(n-1);
}

bool isDigiFac(int a){
	int sum = a;
	while(a){
		sum -= fac[a % 10];
		a /= 10;
	}
	if(sum == 0)
		return true;
	return false;
}