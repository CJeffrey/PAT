#include <iostream>
#include <string>

using namespace std;

int n;

struct StandardForm{
	string data;
	int myK;

	bool operator==(const StandardForm & sf)const{
		return data == sf.data && myK == sf.myK;
	}

	void print()const{
		printf("0.%s*10^%d",data.c_str(),myK);
	}
};

int getDot(const string &str){
	const unsigned int strSize = str.size();
	unsigned int i = 0;
	for(;i<strSize;i++){
		if (str[i] == '.')
			break;
	}
	return i;
}

int getFirstNonZero(const string &str){
	const unsigned int strSize = str.size();
	unsigned int i = 0;
	for(;i<strSize;i++){
		if (str[i] != '.' && str[i] != '0')
			break;
	}
	return i;
}

StandardForm newStr(const string &str){
	const unsigned int strSize = str.size();
	int dotPos = getDot(str);
	int nonZeroPos = getFirstNonZero(str);

	StandardForm sf;
	if (nonZeroPos > dotPos){
		sf.myK = -(nonZeroPos - 1 - dotPos);
	} else {
		sf.myK = dotPos - nonZeroPos;
	}

	int outNum(0);
	for(unsigned int i = 0;i<strSize && outNum <n;i++){
		if (str[i] == '.')
			continue;

		if (str[i] != '0' || outNum != 0){
			sf.data.append(1,str[i]);
			outNum++;
		}
	}

	if (outNum == 0){
		sf.myK = 0;
	}

	for(;outNum<n;outNum++)
			sf.data.append(1,'0');

	return sf;
}

int main(){
	string s1,s2;
	cin >> n >> s1 >> s2;

	StandardForm sf1 = newStr(s1);
	StandardForm sf2 = newStr(s2);

	if (sf1 == sf2){
		printf("YES ");
		sf1.print();
	} else {
		printf("NO ");
		sf1.print();
		printf(" ");
		sf2.print();
	}

	return 0;
}