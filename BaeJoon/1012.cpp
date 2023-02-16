#include<bits/stdc++.h>

using namespace std;

int arr[51][51];
int vis[51][51];
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
int n,m;
void dfs(int y,int x){
	vis[y][x]=1;
	for(int i=0;i<4;i++){
		int ny = y+dy[i];
		int nx = x+dx[i];
		if(ny<0||nx<0||ny>=n||nx>=m||arr[ny][nx]==0) continue;
		if(vis[ny][nx]==1) continue;
		dfs(ny,nx);
	}
}
int main(){
	int t=0;
	cin >> t;
	while(t--){
		memset(arr,0,sizeof(arr));
		memset(vis,0,sizeof(vis));
		int k=0;
		cin >> m >> n >> k;
		int a,b;
		for(int i=0;i<k;i++){
			cin >> a >> b;
			arr[b][a] = 1;
		}

		int result=0;
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				if(arr[i][j]==1 && vis[i][j]==0){
					dfs(i,j);
					result++;
				}
			}
		}
		cout << result << endl;
	}
}
