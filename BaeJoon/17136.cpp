#include<bits/stdc++.h>

using namespace std;

int arr[10][10];
map<int,int> mp;
int ret = 123456789;
int n=10;
bool check(int y,int x,int size){
	if(y+size > n || x+size>n) return false;
	for(int i=y;i<y+size;i++){
		for(int j=x;j<x+size;j++){
			if(arr[i][j]==0) return false;
		}
	}
	return true;
}
void draw(int y,int x,int size,int num){
	for(int i=y;i<y+size;i++){
		for(int j=x;j<x+size;j++){
			arr[i][j]=num;
		}
	}
}
void dfs(int y,int x,int cnt){
	//cout << "input dfs : " << " x : " << x << " y : " << y << endl;
	if(cnt>=ret) return;
	if(x==n){ dfs(y+1,0,cnt); return;}
	if(y==n){
		ret = min(cnt,ret);return;
	}
	if(arr[y][x]==0){ dfs(y,x+1,cnt); return; }

	for(int size=5;size>=1;size--){
		if(mp[size]==5) continue;
		if(check(y,x,size)){
			if(size==5){
				//			cout << " x : " << x << " y : " << y << endl;
			}
			mp[size]++;
			draw(y,x,size,0);
			dfs(y,x+size,cnt+1);
			draw(y,x,size,1);
			mp[size]--;
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	for(int i=0;i<10;i++){
		for(int j=0;j<10;j++){
			cin >> arr[i][j];
		}
	}
	dfs(0,0,0);
	cout << (ret == 123456789 ? -1 : ret) << endl;


	return 0;
}

