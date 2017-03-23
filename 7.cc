#include <iostream>

int main(){
	int ans = 0;
	int c = 0;
	int prime[10001];
	prime[0]=2;
	prime[1]=3;
	for(int i = 9000; i < 10001;i++){
		prime[i] = 0;
	}

	for(int i = 2; i < 10001; i++){
		c=prime[i-1];
		while(!prime[i]){
			c+=2;
			for (int j = 0; j < i; j++){
				if (j==i-1){
					prime[i]=c;
				}
				if (c%prime[j]==0){
					j=i;
				}
			}
		}
	}

	std::cout << prime[10000] << "\n";
	return 0;
}