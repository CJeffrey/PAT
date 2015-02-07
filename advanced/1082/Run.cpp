#include <iostream>
#include <string>

using namespace std;

const string blank = " ";
const string digs[10] = {"ling","yi","er","san","si","wu","liu","qi","ba","jiu"};
const string unit[3] = {""," Wan"," Yi"};
const string unit2[4] = {""," Shi"," Bai"," Qian"};

string analyze4(const string & str){
	const unsigned int strSize = str.size();
	string ret;
	bool hasZero(false);
	for(unsigned int i = 0;i<strSize;i++){
		if (str[i] == '0'){
			hasZero = true;
			continue;
		} else {
			if (!ret.empty())
				ret.append(blank);
			if (hasZero){				
				ret.append(digs[0]).append(blank);
				hasZero = false;
			}
			ret.append(digs[str[i]-48]);
			ret.append(unit2[strSize-i-1]);
		}
	}

	return ret;
}

int main(){
	string oriData;
	cin >> oriData;

	bool hasFu(false);
	if (oriData[0] == '-'){
		hasFu = true;
		oriData = oriData.substr(1);
	}

	string output;
	const int seg = (oriData.size() - 1)/ 4;
	for(int i = 0 ;i<=seg;i++){
		int rightLimit = oriData.size() - 4*i;
		int leftLimit = rightLimit - 4;
		leftLimit = max(0,leftLimit);
		string newStr = oriData.substr(leftLimit,rightLimit - leftLimit);
		string subOutput = analyze4(newStr);
		
		if (i == 0 && seg == 0 && subOutput.empty())
			subOutput = digs[0];

		if (subOutput.empty()){
			if (output.substr(0,4) != digs[0] && !output.empty())
				subOutput = digs[0];
		} else {
			subOutput = subOutput + unit[i];
		}
		
		if (output.empty())
			output = subOutput;
		else {
			if (!subOutput.empty() && !output.empty())
				output = subOutput + blank + output;
		}
	}

	if (hasFu){
		output = "Fu " + output;
	}

	cout << output;

	return 0;
}