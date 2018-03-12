#include <iostream>
#include <vector>
using namespace std;
vector<int> coins = {1,2,5,10,20,50,100,200};


//Finds the number of ways to put together input(pennies)
//with the coin types 1p,2p,5p,10p,20p,50p,1£,2£
int main(int argc, char const *argv[])
{
	if(argc == 2){
		int input = stoi(argv[1]);
		vector<int> perms;
		perms.push_back(1);
		for (int i = 0; i < input;i++){
			perms.push_back(0);
		}
		//For each coin type, calculate how many ways
		//you can make each number of coins up to input
		for (int i = 0; i < coins.size();i++){
			for (int j = coins[i]; j < input+1; j++){
				perms[j] += perms[j - coins[i]];
				/*Ex: if j=8 and coins[i]=5, we look up 
				  how many ways we know we can do 3 in and adds
				  that to how many ways we can do 8.*/
			}
		}
		cout << perms[input] << "\n";
	}
	return 0;
}