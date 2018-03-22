#include <iostream>
#include <math.h>
#include <unordered_set>
#include <vector>
#include <algorithm>
using namespace std;

int commonNumber(int,int);
double cancelDiv (int,int,int);
void genPrime(int);
int GCD(int,int);
vector<int> vPrimes = {2};

int main(int argc, char const *argv[])
{
	genPrime(100);
	int t,n=1,d=1;
	for(int i = 10; i < 100; i++){
		for(int j = i+1; j < 100; j++){
			if(commonNumber(i,j) && cancelDiv(i,j,commonNumber(i,j)) == (double)i/(double)j){
				n *= i; 
				d *= j;
			}
		}
	}
	t = GCD(n,d);
	while(t){
		n /= t;
		d /= t;
		t = GCD(n,d);
	}
	cout << d << "\n";
	return 0;
}

void genPrime(int max){
	bool b;
	for (int i = 3; i < max; i++){
		b = true;
		for (int j = 0; vPrimes[j] <= sqrt(i); j++){
			if(i % vPrimes[j] == 0){
				b = false;
				break;
			}
		}
		if(b){
			vPrimes.push_back(i);
		}
	}
}

int commonNumber(int a, int b){
	vector<int> va;
	vector<int> vb;
	while(a && b){
		va.push_back(a%10);
		a /= 10;
		vb.push_back(b%10);
		b /= 10;
	}
	for(auto i : va){
		if(find(vb.begin(),vb.end(),i) != vb.end())
			return i;
	}
	return 0;
}

double cancelDiv(int n, int d, int c){
	vector<int> vn;
	vector<int> vd;
	double res;
	while(n && d){
		vn.push_back(n%10);
		n /= 10;
		vd.push_back(d%10);
		d /= 10;	
	}
	if(vn[0] == c){
		n = vn[1];
	}else{n = vn[0];}
	if(vd[0] == c){
		d = vd[1];
	}else{d = vd[0];}
	return (double)n/(double)d;
}

int GCD(int n, int d){
	for(int i = vPrimes.size()-1; i >= 0; i--){
		if(n%vPrimes[i] == 0 && d%vPrimes[i] == 0)
			return vPrimes[i];
	}
	return 0;
}