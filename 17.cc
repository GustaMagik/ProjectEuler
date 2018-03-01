#include <iostream>
using namespace std;

int main(int argc, char *argv[]){
	int letterCount = 0;
	int zeroToNine [10] =   {0,3,3,5,4,4,3,5,5,4};
	int tenToNineteen[10] = {3,6,6,8,8,7,7,9,8,8};
	int decimalPrefix[10] = {0,0,6,6,5,5,5,7,6,6};
	int digits [4];
	int tmp;
	for (int i = 1; i < 1001;i++){
		//load digits[] with i in digit form
		tmp = i; 
		for (int j = 0; j < 4; j++){
			digits[j] = tmp % 10;
			tmp /= 10; 
		}
		//Thousand + prefix
		if (digits[3] != 0){
			letterCount += zeroToNine[digits[3]];
			letterCount += 8; //thousand = 8
		}
		//Hundred + prefix + and
		if(digits[2] != 0){
			letterCount += zeroToNine[digits[2]];
			letterCount += 7; //hundred = 7
			if(digits[1] != 0 || digits[0] != 0){
				letterCount += 3; //and = 3
			}
		}
		//Decimals + singels
		if(digits[1] > 1){
			letterCount += decimalPrefix[digits[1]];
			letterCount += zeroToNine[digits[0]];
		}else if(digits[1] == 0){
			letterCount += zeroToNine[digits[0]];
		}else{
			letterCount += tenToNineteen[digits[0]];
		}
	}
	cout << letterCount << "\n";
	return 0;
}