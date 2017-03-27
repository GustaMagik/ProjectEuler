#include <iostream>
#include <fstream>
#include <vector>

int main(){
	long long int best = 1;
	long long int now=1;
	int counter = 0;
	long long int * ptr;
	std::ifstream stream("8.txt");
	std::vector<long long int>list;
	if (stream) {
		char c;
		while(stream.get(c)){if(c!='\n'){list.push_back(c-'0');}}
	}
	ptr = list.data();
	
	for (int i = 0;i<987;i++){
		if(*(ptr+i)==0){counter = 0;now=1;}
		else if(counter<12){now*= *(ptr+i);counter++;}
		else if((*(ptr+i)*now) > best){best = *(ptr+i)*now; now*= *(ptr+i); now/= *(ptr+i-counter);}
		else {now/=(*(ptr+i-counter));now*= (*(ptr+i));}
		std::cout << i << " " << now << " " << best << "\n";
	}

	std::cout << best << "\n";
	return 0;
}