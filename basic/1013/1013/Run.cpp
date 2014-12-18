#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

bool isPrime(int value,const vector<int> &primes){
	float waterLine = sqrt(float(value));
	for(vector<int>::const_iterator iit=primes.begin();iit<primes.end();iit++){
		if (*iit > waterLine)
			break;
		if (value%(*iit) == 0){
			return false;
		}
	}
	return true;
}

int main(){
	int m,n;
	cin >> m >> n;
	int counter=2;
	vector<int> primes;
	while(primes.size()<n){
		if (isPrime(counter,primes)){
			primes.push_back(counter++);
		}else {
			counter++;
		}
	}

	int lineCounter=0;
	int i =m-1;
	for(;;){
		cout << primes[i];
		if (++i >= n)
			break;
		if (lineCounter<9){
			cout << " ";
			lineCounter++;
		}
		else {
			cout << '\n';
			lineCounter=0;
		}
		
	}


	return 0;
}