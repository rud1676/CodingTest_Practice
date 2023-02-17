#include<bits/stdc++.h>
using namespace std;

int n,m;
int arr[101][101];
int vst[101][101];
vector<pair<int,int>> v;

int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};

void dfs(int y,int x){
	vst[y][x]=1;
	if(arr[y][x]==1){
		v.push_back({y,x});
		return;
	}
	for(int i=0;i<4;i++){
		int nx = x + dx[i];
		int ny = y + dy[i];
		if(nx<0||ny<0||nx>=m||ny>=n||vst[ny][nx]) continue;
		dfs(ny,nx);
	}
}

int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin >> arr[i][j];
		}
	}

	int cycle=0;
	while(true){
		bool flag=true;
		fill(&vst[0][0],&vst[0][0]+101*101,0);
		v.clear();
		cycle++;
		dfs(0,0);
		int cnt=0;
		for(auto it :v){
			arr[it.first][it.second] = 0;
			cnt++;
		}
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				if(arr[i][j]!=0) flag=false;
			}
		}
		if(flag){
			cout << cycle << '\n';
			cout << cnt << '\n';
			return 0;
		}
	}
	return 0;

}
