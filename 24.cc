#include <iostream>
#include <vector>
using namespace std;

vector<int> perm = {0,1,2,3,4,5,6,7,8,9};
vector<int>::iterator itr;
int factorial (int in);
void swap (int ind);

//finds the x'th permutation of 0-9
int main(int argc, char const *argv[])
{
	if(argc == 2){
		int index;
		int arr = stoi(argv[1]);
		if(factorial(10)<arr){
			cout << "ordering out of bound\n";
			return 0;
		}
		while(arr){
			//find exhustable index
			for(int i = 10; i > 0; i--){
				if(factorial(i)<arr){
					index = i;
					break;
				}
			}
			arr -= factorial(index);
			swap(index);
		}
		for(auto i : perm){
				cout << i;
		}
		cout << "\n";
	}	
	return 0;
}

int factorial (int in){
	int fac = 1;
	for(int i = 2; i < in+1; i++){
		fac *= i;
	}
	return fac;
}
//Swaps lowest elem greater than the one after
//ind (indexing right to left)
void swap (int ind){
	int tmp = perm[9-ind];
	for(int i = 9-ind; i < 10;i++){
		if(perm[i]>tmp){
			perm[9-ind] = perm[i];
			perm[i] = tmp;
			return;
		}
	}
}