#include <iostream>
#include <map>
#include <set>
#include <string.h>
using namespace std;

struct StuName{
	StuName(){
		memset(name,0,5);
	};
	char name[5];
	
	bool operator<(const StuName & sn)const{
		return strcmp(name,sn.name) < 0;
	}

	int getHash()const{
		return ((name[0]-'A') * 26*26*10 + (name[1]-'A') *26*10 +(name[2]-'A') *10 +(name[3]-'0'));
	}
};

int main(){
	int n,k;
	scanf("%d%d",&n,&k);

	map<int,set<int>> allRecords;
	StuName tmpName;
	int tmpCourseID,StuNum;
	int i,j;
	
	for(i = 0;i<k;i++){
		scanf("%d %d",&tmpCourseID,&StuNum);
		for(j=0;j<StuNum;j++){
			scanf("%s",&tmpName.name);
			allRecords[tmpName.getHash()].insert(tmpCourseID);
		}
	}

	int courseNum;
	map<int,set<int>>::iterator mit;
	const map<int,set<int>>::const_iterator mitEnd(allRecords.end());
	set<int>::const_iterator sit,sitEnd;
	for(i = 0;i<n;i++){
		scanf("%s",&tmpName.name);
		mit = allRecords.find(tmpName.getHash());
		if (mit == mitEnd)
			courseNum = 0;
		else
			courseNum = mit->second.size();
		printf("%s %d",tmpName.name,courseNum);
		if (mit != mitEnd){
			for(sit=mit->second.begin(),sitEnd=mit->second.end();sit!=sitEnd;sit++){
				printf(" %d",*sit);
			}
		}
		printf("\n");
	}

	return 0;
}