#include <iostream>
#include <string>
#include <sstream>
using namespace std;

string index[10] = {"ling","yi","er","san","si","wu","liu","qi","ba","jiu"};

int main(){
	char c;
	int i;
	int counter = 0;
	while((c = getchar()) != '\n'){
		i = c-48;
		counter += i;
	}

	string s;
	stringstream ss;
	ss<<counter;
	ss>>s;

	for(unsigned int i = 0;i<s.size();i++){
		string tmpS=s.substr(i,1);
		int tmpI = atoi(tmpS.c_str());
		cout << index[tmpI];
		if (i+1 < s.size())
			cout << " ";
	}
}