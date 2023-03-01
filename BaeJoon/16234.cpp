#include<bits/stdc++.h>

using namespace std;

int n,l,r;
int arr[101][101];
int vst[101][101];
int sum;
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
vector<pair<int,int>> v;

bool comp(int b,int l,int r){
	return l<=b && r>=b;
}

void dfs(int y,int x){
	vst[y][x]=1;
	v.push_back({y,x});
	sum+=arr[y][x];

	for(int i=0;i<4;i++){
		int nx = x+dx[i];
		int ny = y+dy[i];
		if(nx<0||ny<0||nx>=n||ny>=n||vst[ny][nx]!=0) continue;
		int diff=abs(arr[y][x]-arr[ny][nx]);
		if(comp(diff,l,r)){
			dfs(ny,nx);
		}
	}
}

int main(){
	cin >> n >> l >> r;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin >> arr[i][j];
		}
	}
	int cnt=0;
	int ck=true;
	while(ck){
		fill(&vst[0][0],&vst[0][0]+101*101,0);
		sum=0;
		v.clear();
		ck=false;
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				if(vst[i][j]==0) {
					sum=0;
					v.clear();
					dfs(i,j);
				}
				if(v.size()==1) continue;
				for(auto it: v){
					ck=true;
					arr[it.first][it.second] = sum/v.size();
				}
			}
		}
		if(ck) cnt++;
	}
	cout << cnt<<endl;
	return 0;

}
