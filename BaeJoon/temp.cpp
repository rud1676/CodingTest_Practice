#include<bits/stdc++.h>

using namespace std;

int n,l,h;
int mp[101][101];
int vst[101][101];
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};

vector<pair<int,int>> v;
int sum;

bool check(int num){
	if(num>=l && num<=h) return true;
	return false;
}
void dfs(int y,int x){
	v.push_back({y,x});
	vst[y][x]=1;
	sum+=mp[y][x];
	for(int i=0;i<4;i++){
		int ny = y+dy[i];
		int nx = x+dx[i];
		if(ny<0||nx<0||ny>=n||nx>=n||vst[ny][nx]!=0||check(abs(mp[ny][nx]-mp[y][x]))==false) continue;
		dfs(ny,nx);
	}

}

int main(){
	cin >>n >>l >> h;

	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin >> mp[i][j];
		}
	}

	int cnt=0;
	int sig=true;
	while(sig){
		sig=false;
		fill(&vst[0][0],&vst[0][0]+101*101,0);
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				if(vst[i][j]==0){
					dfs(i,j);
					if(sum>mp[i][j]){
						sig=true;
						int val = (int)(sum/v.size());
						for(auto it:v){
							mp[it.first][it.second]=val;
						}
					}
				}
				v.clear();
				sum=0;
			}
		}
		if(sig) cnt++;
	}
	cout << cnt <<'\n';

}
