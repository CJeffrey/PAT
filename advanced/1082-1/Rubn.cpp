#include "Run.h"
#include <sstream>
#include <iostream>
int main(){
	for(int i = 0 ;i<=999999999;i++){

		stringstream ss;
		string oriData;
		ss << i;
		ss >> oriData;
		string s1 = main1(oriData);
		string s2 = main2(i);

		if (s1 != s2){
			cout << i << endl;
		}
	}

	return 0;
}