#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <sstream>
#include <algorithm>
using namespace std;

int main(){
	int n;
	scanf("%d",&n);

	multimap<string,int> title;
	multimap<string,int> author;
	multimap<string,int> keyWord;
	multimap<string,int> publisher;
	multimap<string,int> year;

	int tmpID;
	string tmpString,subStr;
	for(int i = 0;i<n;i++){
		scanf("%d\n",&tmpID);

		getline(cin,tmpString);
		title.insert(pair<string,int>(tmpString,tmpID));

		getline(cin,tmpString);
		author.insert(pair<string,int>(tmpString,tmpID));

		getline(cin,tmpString);
		stringstream ss(tmpString);
		while(!ss.eof()){
			subStr="";
			ss>>subStr;
			keyWord.insert(pair<string,int>(subStr,tmpID));
		}

		getline(cin,tmpString);
		publisher.insert(pair<string,int>(tmpString,tmpID));

		getline(cin,tmpString);
		year.insert(pair<string,int>(tmpString,tmpID));
	}

	int m;
	scanf("%d",&m);
	int queryType;
	multimap<string,int>* mapPtr;
	multimap<string,int>::const_iterator mit;
	vector<int>::const_iterator vit,vitEnd;
	int resultNum,counter;
	for(int i = 0;i<m;i++){
		mapPtr = NULL;
		scanf("%d: ",&queryType);
		getline(cin,tmpString);
		switch(queryType){
			case 1:
				mapPtr = &title;
				break;
			case 2:
				mapPtr = &author;
				break;
			case 3:
				mapPtr = &keyWord;
				break;
			case 4:
				mapPtr = &publisher;
				break;
			case 5:
				mapPtr = &year;
				break;
		}
		printf("%d: %s\n",queryType,tmpString.c_str());
		resultNum = mapPtr->count(tmpString);
		if (resultNum == 0){
			printf("%s\n","Not Found");
		} else {
			vector<int> allIDs;
			for(mit=mapPtr->find(tmpString),counter=0;counter<resultNum;counter++,mit++){
				allIDs.push_back(mit->second);
			}
			sort(allIDs.begin(),allIDs.end());
			vitEnd = allIDs.end();
			for(vit=allIDs.begin();vit<vitEnd;vit++){
				printf("%07d\n",*vit);
			}			
		}
	}


	return 0;
}