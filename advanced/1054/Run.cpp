#include <iostream>
#include <map>

using namespace std;

int main(){
	int m,n;
	scanf("%d%d",&m,&n);
	const unsigned int halfSize = m*n / 2;
	unsigned int domColor(0),couter(0);


	unsigned int ii = unsigned int();
	cout << ii;

	map<unsigned int,unsigned int> allColor;
	map<unsigned int,unsigned int>::iterator mit;
	unsigned int tmpValue;
	for(int i = 0;i<n;i++){
		for(int j = 0;j<m;j++){
			scanf("%d",&tmpValue);
			//allColor[tmpValue]++;
			mit = allColor.find(tmpValue);
			if (mit == allColor.end()){
				allColor.insert(pair<unsigned int,unsigned int>(tmpValue,1));
				if (1 > halfSize)
					domColor = tmpValue;
			} else {
				(mit->second)++;
				if (mit->second > halfSize)
					domColor = mit->first;
			}
		}
	}
	
	/*for(mit = allColor.begin();mit!=allColor.end();mit++){
		if (mit->second > couter){
			domColor = mit->first;
			couter = mit->second;
		}
	}*/
	printf("%d",domColor);
	return 0;
}