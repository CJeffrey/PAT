#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(){
	string oriS;
	getline(cin,oriS);
	string revS = oriS;
	reverse(revS.begin(),revS.end());

	//cout << oriS << endl << revS << endl;

	const int size = oriS.size();
	int maxSym=0;
	for(int length = 1;length<=size;length++){
		for(int i = 0;i+length<=size;i++){
			if (oriS.substr(i,length) == revS.substr(size-i-length,length)){
				maxSym = length;
				break;
			}
		}
	}

	printf("%d",maxSym);
	return 0;
}