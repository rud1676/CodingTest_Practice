#include<bits/stdc++.h>

using namespace std;

int arr[101][101];
int vis[101][101];
int n,m;
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};

int main(){
	cin >> n >> m;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			scanf("%1d",&arr[i][j]);
		}
	}

	queue<pair<int,int>> q;
	q.push({0,0});
	int y,x;
	int nx,ny;
	vis[0][0] = 1;
	while(q.size()){
		tie(y,x) = q.front();q.pop();
		for(int i=0;i<4;i++){
			ny = y+dy[i];
			nx = x+dx[i];
			if(nx<0||ny<0||nx>=m||ny>=n||arr[ny][nx]==0) continue;
			if(vis[ny][nx]) continue;
			vis[ny][nx] = vis[y][x]+1;
			q.push({ny,nx});
		}
	}

	cout << vis[n-1][m-1] << endl;
	return 0;

}
