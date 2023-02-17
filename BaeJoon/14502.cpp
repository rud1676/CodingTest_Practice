#include<bits/stdc++.h>

using namespace std;
int n,m;
int arr[10][10];
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
vector<pair<int,int>> emptyv;

void dfs(int temp[][10],int y,int x){
	temp[y][x]=2;
	for(int i=0;i<4;i++){
		int nx= x +dx[i];
		int ny= y +dy[i];
		if(nx>=m || ny>=n || nx<0||ny<0||temp[ny][nx]!=0) continue;
		dfs(temp,ny,nx);
	}
}

//벽에서 퍼트리고 0의 갯수 구하는 문제
int go(){
	int temp[10][10];
	memcpy(temp,arr,sizeof(arr));

	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(arr[i][j]==2){
				dfs(temp,i,j);
			}
		}
	}

	//0의갯수
	int cnt=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(temp[i][j]==0) cnt++;
		}
	}
	return cnt;
}

int main(){
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			scanf("%1d",&arr[i][j]);
			if(arr[i][j]==0) emptyv.push_back({i,j});
		}
	}
	int mx =-1;
	for(int i=0;i<emptyv.size()-2;i++){
		for(int j=i+1;j<emptyv.size()-1;j++){
			for(int k=j+1;k<emptyv.size();k++){
				arr[emptyv[i].first][emptyv[i].second]=1;
				arr[emptyv[j].first][emptyv[j].second]=1;
				arr[emptyv[k].first][emptyv[k].second]=1;
				mx = max(mx,go());
				arr[emptyv[i].first][emptyv[i].second]=0;
				arr[emptyv[j].first][emptyv[j].second]=0;
				arr[emptyv[k].first][emptyv[k].second]=0;
			}
		}
	}

	cout << mx << '\n';
	return 0;
}
