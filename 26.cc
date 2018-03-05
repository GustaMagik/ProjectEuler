#include <iostream>
#include <unordered_map>
#include <unordered_set>
using namespace std;
unordered_map<int,int> markov;
unordered_set<int> checked;
int recFracChain (int div);
int rfcHelper (int div, int num);

//Find the longest reccuring cycle 
//in fractions greater than 1/input
int main(int argc, char const *argv[])
{
	if(argc == 2){
		int input = stoi(argv[1]);
		int longest = 0;
		int index, val;
		//Finds the nubmber that gives the longest chain
		for (int i = 1; i < input;i++){
			val = recFracChain(i);
			if (val > longest){
				index = i;
				longest = val;
			}
		}
		cout << index << "\n";

	}
	return 0;
}

//Finds the lenght of the recurring chain 
//of numbers (if any) when 1/div
int recFracChain (int div){
	int num = 1;
	while(num){
		num = rfcHelper(div,num);
	}
	int chain = 0;
	int next = 1;
	int goal = 0;
	while(next){
		if(checked.count(next) == 0){
			checked.emplace(next);
			next = markov.at(next);
		}else{
			goal = next;
			chain++;
			next = markov.at(next);
			while(next != goal){
				chain++;
				next = markov.at(next);
			}
			break;
		}
	}
	checked.clear();
	markov.clear();
	return chain;
}

int rfcHelper (int div, int num){
	int state = num;
	if(markov.count(num) != 0)
		return 0;
	if(num / div != 0){
		num = num % div;
	}	
	num *= 10;
	markov.emplace(state,num);
	return num;
}