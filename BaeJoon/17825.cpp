#include<bits/stdc++.h>

using namespace std;

int mp[100];
vector<int> v(100);
int arr[10];
int score[4];

void ini();{
	for(int i=1;i<=20;i++){
		mp[i]=i*2;
	}
	mp[24]=25;
	mp[21]=13; mp[22]=16; mp[23]=19;
	mp[25]=22; mp[26]=24;
	mp[27]=28; mp[28]=27; mp[29]=26;
	mp[30]=30; mp[31]=35;

	for(int i=1;i<=20;i++){
		mv[i-1]=i;
	}
	mv[5]=21;mv[21]=22;mv[22]=23;mv[23]=24;
	mv[10]=25;mv[25]=26;mv[26]=24;
	mv[15]=27;mv[27]=28;mv[28]=29;mv[29]=24;
	mv[24]=30;mv[30]=31;mv[31]=20;mv[20]=999;

}
int main(){
	init();

	for(int i=0;i<10;i++){
		cin >> arr[i];
	}

}



