#include <iostream>

int main(){
	int a[] = {2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
	int b = 1;
	for (int i=0; i < 19;i++){
		for (int j=i+1; j < 19;j++){
			if (a[j]%a[i]==0){
				a[j]=a[j]/a[i];
				}
		}
	}

	for (int k = 0; k < 19;k++){
		b *=a[k];
		std::cout << a[k] << "\n";
	}
	std::cout << b << "\n";
	return 0;
}