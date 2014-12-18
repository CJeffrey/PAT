#include <iostream>
#include <string.h>
#include <string>

std::string digitForm[10] = {"zero","one","two","three","four","five","six","seven","eight","nine"};

int main(){
	int sum(0);
	char tmpChar;
	while (scanf("%c",&tmpChar) != EOF){
		if (tmpChar == '\n')
			break;
		else 
			sum += (tmpChar-48);
	}
	//printf("%d",sum);
	
	char buffer[4];
	memset(buffer,0,4);
	sprintf(buffer,"%d",sum);

	for(int i = 0 ;i<4;i++){
		if (buffer[i] == 0){
			break;
		} else {
			if (i!=0)
				printf("%c",' ');
			printf("%s",digitForm[buffer[i]-48].c_str());
		}
	}

	return 0;
}