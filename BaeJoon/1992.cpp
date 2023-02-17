#include<bits/stdc++.h>
#define y1 aaaa

using namespace std;

int n;
int ma[65][65];


string split_map(int y1,int x1,int size){
	if(size==1) return string(1,ma[y1][x1]+'0');
	int b = ma[y1][x1];
	string s="";
	//cout << "y : " << y1 << " x : " << x1 << endl;

	for(int i=y1;i<size+y1;i++){
		for(int j=x1;j<size+x1;j++){
			if(b!=ma[i][j]){
				s+="(";
				s+=split_map(y1,x1,size/2);
				s+=split_map(y1,x1+size/2,size/2);
				s+=split_map(y1+size/2,x1,size/2);
				s+=split_map(y1+size/2,x1+size/2,size/2);
				s+=")";
				return s;
			}
		}
	}
	return string(1,b+'0');
}

int main(){
	cin >> n;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			scanf("%1d",&ma[i][j]);
		}
	}
	cout << split_map(0,0,n) << endl;
	return 0;
}
