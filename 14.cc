//Hashmap <long int,long int> , init with key=1 steps = 0
//for long int i = 0 to 10⁶-1, i in hash? if not calc step
// chech if new state is in hash, if so add steps add to hash.

#include <unordered_map>
#include <iostream>
#include <string>
using namespace std;

typedef unordered_map<long int,long int> collatz_map;

void collatzStep(long int, collatz_map&);

int main(int argc, char *argv[]){
	collatz_map collatz = {{1,1}};
	long int maxSteps = 1;
	long int longStart = 1;
	for(long int i = 2; i < 1000000;i++){
		//calc collatz chain lenght starting at i
		if(collatz.count(i)==0){
			collatzStep(i, collatz);
		}
		//check if this is the longest one yet
		if(collatz.at(i) > maxSteps){
			maxSteps = collatz.at(i);
			longStart = i;			
		}
	}
	cout << longStart << "\n";
	return 0;
}

void collatzStep(long int in, collatz_map& m){
	//calc the step
	long int step;
	if(in % 2 == 0){
		step = in/2;
	}else{
		step = in*3+1;
	}
	//calc the chain lenght of in
	long int chain = 1;
	if(m.count(step)==0){
		collatzStep(step, m);
	}
	chain += m.find(step)->second;
	m.emplace(in, chain);
}