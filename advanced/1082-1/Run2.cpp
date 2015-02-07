#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <string>
#include "Run.h"
using namespace std;

string main2(int num)
{
	string ret;

	string a[] = {"ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu"};
	string b[] = {"", "Shi", "Bai", "Qian", "Wan", "Shi", "Bai", "Qian", "Yi"};
	vector<string> res;
	vector<int> digit;
	int e;
	if (num == 0){
		ret += "ling";
		return ret;
	} 
	else if (num < 0){
		ret += "Fu ";
		num = -num;
	}
	while (num != 0){
		digit.push_back(num%10);
		num /= 10;
	}
	for (e=0; e<digit.size() && digit[e]==0; ++ e) {}
	if (e == 8){
		ret += a[digit[e]];
		ret += " Yi";
		return ret;
	}
	for (int i = e; i < digit.size(); ++ i){
		if (i!=0 && (digit[i]!=0 || i==4 || i==8)){
			res.push_back( b[i] );
		}
		res.push_back(a[ digit[i] ]);
	}
	for (int i = res.size()-1; i >= 0; -- i){
		if (i != res.size()-1){
			ret += " ";
		}
		int cnt = 0;
		while (i>=0 && res[i]=="ling"){
			-- i;
			++ cnt;
		}
		if (cnt!=0 && res[i]!="Wan"){
			ret += "ling ";
		}
		ret += res[i];
	}
	return ret;
}