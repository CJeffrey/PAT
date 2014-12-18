#include <iostream>

using namespace std;

int main(){
	int x;
	cin >> x;
	
	int counter=0;

	while(x != 1){
		if (x %2 == 0){
			x = x/2;
		} else {
			x = (x * 3 + 1) /2;
		}
		counter++;
	}
	cout << counter;

	return 0;
}