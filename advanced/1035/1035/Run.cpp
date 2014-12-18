#include <iostream>
#include <string>
#include <vector>
using namespace std;


class Account{
public:
	string user;
	string password;
};

bool changeChar(string & s){
	bool ret = false;
	for(int i =0;i<s.size();i++){
		switch(s[i]){
			case '1':
				s[i]='@';
				ret=true;
				break;
			case '0':
				s[i]='%';
				ret=true;
				break;
			case 'l':
				s[i]='L';
				ret=true;
				break;
			case 'O':
				s[i]='o';
				ret=true;
				break;
		}
	}
	return ret;
}

int main(){
	int n;
	scanf("%d",&n);

	vector<Account> allAccounts;
	for(int i = 0;i<n;i++){
		allAccounts.push_back(Account());
		cin >> allAccounts.back().user >> allAccounts.back().password;
	}

	vector<Account> changedAccounts;
	bool changed;
	for(int i = 0;i<n;i++){
		changed = changeChar(allAccounts[i].password);
		if (changed){
			changedAccounts.push_back(allAccounts[i]);
		}
	}

	if (changedAccounts.empty()){
		if (n == 1){
			printf("%s","There is 1 account and no account is modified");
		} else {
			printf("%s%d%s","There are ",n," accounts and no account is modified");
		}		
	} else {
		printf("%d",changedAccounts.size());
		for(int i = 0;i<changedAccounts.size();i++){
			cout << endl << changedAccounts[i].user << " " <<  changedAccounts[i].password;
		}
	}

	return 0;
}