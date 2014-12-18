#include <iostream>
#include <string.h>
int sizeN;
int * oriData;
int * retIns;
int * retMer;
int * swapMer;
int * retStandard;

void mergeSort(int startPos1,int endPos1,int startPos2,int endPos2){
	const int totalStart = startPos1;
	const int totalEnd = endPos2;
	//data is [starPos,endPos)
	int totalSize = endPos1 - startPos1 + endPos2 - startPos2;
	int merCounter = startPos1;
	while ((startPos1 != endPos1) || (startPos2 != endPos2)){
		if (startPos1 == endPos1){
			swapMer[merCounter++] = retMer[startPos2++];
		} else if (startPos2 == endPos2){
			swapMer[merCounter++] = retMer[startPos1++];
		} else {
			if (retMer[startPos1] < retMer[startPos2]){
				swapMer[merCounter++] = retMer[startPos1++];
			} else {
				swapMer[merCounter++] = retMer[startPos2++];
			}
		}
	}
	for(int i = totalStart;i<totalEnd;i++){
		retMer[i] = swapMer[i];
	}
}

void runMergeSort(const int mergeSize){
	int tmpStart = 0;
	int tmpMiddle = tmpStart + mergeSize;
	int tmpEnd = tmpMiddle + mergeSize;
	while(tmpMiddle < sizeN){
		if (tmpEnd > sizeN){
			tmpEnd = sizeN;
		}
		mergeSort(tmpStart,tmpMiddle,tmpMiddle,tmpEnd);
		tmpStart = tmpEnd;
		tmpMiddle = tmpStart + mergeSize;
		tmpEnd = tmpMiddle + mergeSize;
	}
}

void runInsertSort(const int InsertSize){
	for(int i = 0;i<InsertSize;i++){
		if (retIns[i] > retIns[InsertSize]){
			int tmpValue = retIns[InsertSize];
			for(int j = InsertSize;j>i;j--){
				retIns[j] = retIns[j-1];
			}
			retIns[i] = tmpValue;
			return;
		}
	}
}

void myPrint(int * ret){
	for(int i = 0;i<sizeN;i++){
		printf("%d",ret[i]);
		if (i+1 !=sizeN){
			printf("%c",' ');
		}
	}		
	printf("%c",'\n');
}

bool isSame(int * ret){
	for(int i = 0;i<sizeN;i++){
		if (ret[i] != retStandard[i]){
			return false;
		}
	}
	return true;
}

int main(){
	scanf("%d",&sizeN);
	oriData = new int[sizeN];
	retIns = new int[sizeN];
	retMer = new int[sizeN];
	swapMer = new int[sizeN];
	retStandard = new int[sizeN];

	for(int i = 0;i<sizeN;i++){
		scanf("%d",oriData + i);
	}
	for(int i = 0;i<sizeN;i++){
		scanf("%d",retStandard + i);
	}
	
	memcpy(retIns,oriData,sizeN*sizeof(int));
	memcpy(retMer,oriData,sizeN*sizeof(int));

	bool successFlag = false;
	for(int mergeSize = 1;mergeSize<sizeN;mergeSize*=2){
		runMergeSort(mergeSize);
		if (isSame(retMer)){
			successFlag = true;
			continue;
		}
		if (successFlag){
			printf("%s","Merge Sort\n");
			myPrint(retMer);
			break;
		}
	}

	if (!successFlag){
		for(int i = 0;i<sizeN;i++){
			runInsertSort(i);
			if (isSame(retIns)){
				successFlag = true;
				continue;
			}
			if (successFlag){
				printf("%s","Insertion Sort\n");
				myPrint(retIns);
				break;
			}
		}
	}
	

	delete [] retStandard;
	delete [] swapMer;
	delete [] retMer;
	delete [] retIns;
	delete [] oriData;
	return 0;
}