#include <iostream>
#include <string.h>
int main(){
	char s1[81],s2[81];
	char result[38];
	memset(s1,0,81);
	memset(s2,0,81);
	memset(result,0,38);

	scanf("%s",&s1);
	scanf("%s",&s2);

	char * ptr1(s1);
	char * ptr2(s2);
	int resultCounter = 0;
	char tmp;
	bool exist;
	while (*ptr1 != 0 || *ptr2 != 0){
		if (*ptr1 == 0)
			break;
		if (*ptr1 != *ptr2){
			tmp=*ptr1;
			if (tmp> 96 && tmp<=122){
				tmp-=32;
			}
			exist = false;
			for(int i = 0;i<resultCounter;i++){
				if (result[i] == tmp){
					exist = true;
					break;
				}
			}
			if (!exist){
				result[resultCounter++]=tmp;
			}
			ptr1++;
		} else {
			if (*ptr1 == 0 && *ptr2 == 0){
				break;
			} else {
				ptr1++;
				ptr2++;
			}
		}
	}

	for(int i = 0;i<resultCounter;i++){
		printf("%c",result[i]);
	}

	return 0;
}