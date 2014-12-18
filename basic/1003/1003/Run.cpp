#include <iostream>
#include <string>

using namespace std;

#define YES	"YES"
#define NO	"NO"

int countA(string s){
	int counter = 0;
	for(unsigned int i = 0;i<s.size();i++){
		string tmpS = s.substr(i,1);
		if (tmpS == "A")
			counter++;
		else
			return -1;
	}
	return counter;
}

int main(){
	int num;
	cin >> num;
	string * ss = new string[num];
	for(int i = 0;i<num;i++){
		cin >> ss[i];
	}
	string tmpS;
	for(int i = 0;i<num;i++){
		tmpS = ss[i];
		int positionP = tmpS.find('P');
		int positionT = tmpS.find('T');
		if (positionP >= positionT){
			cout << NO << endl;
			continue;
		}
		if (positionP == string::npos || positionT == string::npos){
			cout << NO << endl;
			continue;
		}
		int counter1,counter2,counter3;
		counter1 = countA(tmpS.substr(0,positionP));
		counter2 = countA(tmpS.substr(positionP+1,positionT-positionP-1));
		counter3 = countA(tmpS.substr(positionT+1,string::npos));
		if (counter1<0 || counter2 <1 || counter3<0){
			cout << NO<< endl;
			continue;
		}
		if (counter1 * counter2 == counter3){
			cout << YES<< endl;
			continue;
		} else{
			cout << NO<< endl;
			continue;
		}
	}

	return 0;
}