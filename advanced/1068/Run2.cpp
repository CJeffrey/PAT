#include <iostream>
#include <fstream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;

#define MAXTOTAL	10001
#define MAXAMOUNT	101

int f[MAXTOTAL][MAXAMOUNT];			//f[n][m]表示 前n个数中 得出的 最接近m 的值
bool has[MAXTOTAL][MAXAMOUNT];		//has[n][m]表示在前n个数中得出最接近m的值时 是否用到c[n]
int* c = NULL;

int calcClosestSum(int n,int m)
{
	memset(f,0,sizeof(int)*MAXTOTAL*MAXAMOUNT);
	memset(has,false,sizeof(bool)*MAXTOTAL*MAXAMOUNT);
	int i,j;
	int sec;
	for(i=1;i<n+1;i++)
	{
		for(j=1;j<=m;j++)
		{
			if(j-c[i]<0)sec=0;
			else sec = f[i-1][j-c[i]]+c[i];
			if(f[i-1][j] > sec)
			{
				f[i][j]=f[i-1][j];
			}else
			{
				f[i][j]=sec;
				has[i][j]=true;
			}
		}
	}
	return f[n][m];
}

bool cmp(const int& A,const int& B)
{
	return A>B;
}

int main()
{
	unsigned int n,m;
	cin>>n>>m;
	c = new int[n+1];
	memset(c,0,sizeof(int)*(n+1));

	unsigned int i;
	for(i=0;i<n;i++)
	{
		cin>>c[i+1];
	}
	sort(&c[1],&c[n+1],cmp);

	int res = calcClosestSum(n,m);
	if(res==m)
	{
		vector<int> v;
		while(m)
		{
			while(!has[n][m])		
				n--;
			v.push_back(c[n]);
			m = m - c[n];
			n--;
		}
		for(i=0;i<v.size()-1;i++)
			cout<<v[i]<<' ';
		cout<<v[i]<<endl;
	}else
		cout<<"No Solution"<<endl;

	return 0;
}