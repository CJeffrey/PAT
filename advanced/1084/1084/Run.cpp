#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(){
	string s1,s2;
	cin >> s1 >> s2;

	vector<char> brokenKeys;

	int ptr2 = 0;
	for(unsigned int ptr1 = 0;ptr1<s1.size();ptr1++){
		char c1 = s1[ptr1];
		char c2 = s2[ptr2];
		if (c1 == c2){
			ptr2++;
		} else {
			if (c1 >= 97 && c1 <= 122){
				c1 -= 32;
			}
			bool hasFound = false;
			for(vector<char>::const_iterator cit = brokenKeys.begin();cit<brokenKeys.end();cit++){
				if (*cit == c1){
					hasFound = true;
					break;
				}
			}
			if (!hasFound){
				brokenKeys.push_back(c1);
			}
		}
	}

	for(vector<char>::const_iterator cit = brokenKeys.begin();cit<brokenKeys.end();cit++){
		printf("%c",*cit);
	}

	return 0;
}