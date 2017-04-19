#include <iostream>
#include <stdlib.h>
#include <fstream>
int main(){
	
	int * ptr;
	ptr = (int*) malloc(401 * sizeof(int));
	char ch;
	int tmp=0;
	int i=0;
	std::ifstream fs;
	fs.open("11.txt", std::ifstream::in);
	ch = fs.get();
	do {
		if (ch >= '0' && ch <='9'){
			tmp *= 10;
			tmp += ch-'0';
		}
		else {
			std::cout << tmp << ' ';
			ptr[i]=tmp;
			i++;
			tmp=0;
		}
		ch = fs.get();
	} while (fs.good());
	ptr[i]=tmp;
	int roof = i;
	i=0;
	while (i!= roof+1){
		if (i%20 < 17){
			if (ptr[i]*ptr[i+1]*ptr[i+2]*ptr[i+3]>tmp){
				tmp=ptr[i]*ptr[i+1]*ptr[i+2]*ptr[i+3];
			}
			if (i<400-60){
				if (ptr[i]*ptr[i+21]*ptr[i+42]*ptr[i+63]>tmp){
					tmp=ptr[i]*ptr[i+21]*ptr[i+42]*ptr[i+63];
				}
			}
			if (i<400-60){
				if(ptr[i]*ptr[i+20]*ptr[i+40]*ptr[i+60]>tmp){
					tmp=ptr[i]*ptr[i+20]*ptr[i+40]*ptr[i+60];
				}
				if(i%20>2){
					if(ptr[i]*ptr[i+19]*ptr[i+38]*ptr[i+57]>tmp){
						tmp=ptr[i]*ptr[i+19]*ptr[i+38]*ptr[i+57];
					}
				}
			}
		}
		i++;
	}

	fs.close();
	std::cout << tmp << "\n";
	return 0;
}