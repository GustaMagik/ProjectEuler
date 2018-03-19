#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

bool isPandigital(int);
int concatInt(int, int);
int intLen(int);

int main(int argc, char const *argv[])
{
	int maxPan = 0;
	int ten = 1000000000, nine = 100000000, five = 10000;
	int conC, mlt;
	for(int i = 1; i < five; i++){
		conC = 0;
		mlt = 1;
		while(intLen(conC) < 9){
			if(9-intLen(conC) < intLen(i*mlt)){
				conC = ten;
				break;
			}
			conC = concatInt(conC, i*mlt);
			mlt++;
		}
		if(conC > maxPan && isPandigital(conC))
			maxPan = conC;
	}
	cout << maxPan << "\n";
	return 0;
}

//Generic pandigital checker
bool isPandigital(int n){
	string s = to_string(n);
	string p = "123456789";
	if(s.size() < 10){
		sort(s.begin(),s.end());
		if(s.compare(p.substr(0,s.size())) == 0)
			return true;
	}
	return false;
}

//Concat 2 ints, if wrap around return is 0
int concatInt(int a, int b){
	int t = b;
	b = 0;
	while(t){
		b *= 10;
		b += t%10;
		t /= 10;
	}
	while(b%10){
		a *= 10;
		a += b%10;
		b /= 10;
		if(a < 0){
			a = 0;
			break;
		}
	}
	return a;
}

int intLen(int n){
	if(n == 0)
		return 0;
	return 1 + intLen(n/10);
}