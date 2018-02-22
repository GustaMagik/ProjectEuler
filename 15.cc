/* Latice paths
See stars and bars theroem 2
*/

#include <iostream>
#include <math.h>
using namespace std;


int main()
{	
	double perm = 1;
	for (int i = 40; i > 20; i--){
		perm *= i;
		perm /= i-20;
	}
	cout << to_string(nearbyint(perm)) << "\n";
	return 0;
}

