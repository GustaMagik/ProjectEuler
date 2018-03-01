#include <iostream>
using namespace std;
//current mod 7 gives week day, 6 == sunday
int months[] = {31,28,31,30,31,30,31,31,30,31,30,31};
int current = 365; //1 jan 1901 
int sundays = 0;

int main(int argc, char *argv[])
{
	for(int i = 0; i < 100;i++){
		for(int j = 0; j < 12;j++){
			if(current % 7 == 6)
				sundays++;
			current += months[j];
			//If feb AND leap year AND 
			//[(not cetury) OR divisible by 400]
			if(j == 1 && i+1901 % 4 == 0 && (i+1901 % 100 != 0 || i+1901 % 400))
				current += 1;
		}
	}
	cout << sundays << "\n";
	return 0;
}