#include<bits/stdc++.h>

using namespace std;

int m[101][101];
int n;
int vst[101][101];
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
int k;

void dfs(int y,int x){
	vst[y][x]=1;
	for(int i=0;i<4;i++){
		int ny = y+dy[i];
		int nx = x+dx[i];
		if(ny<0||nx<0||ny>=n||nx>=n||m[ny][nx]<=k) continue;
		if(vst[ny][nx]==1) continue;
		dfs(ny,nx);
	}
}
int main(){
	cin >> n;
	cin.tie(NULL);
	cout.tie(NULL);
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin >> m[i][j];
		}
	}

	int result = -1;
	for(k=0;k<=100;k++){
		fill(&vst[0][0],&vst[0][0]+101*101,0);
		int area=0;
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				if(m[i][j]>k && vst[i][j]==0){
					dfs(i,j);
					area++;
				}
			}
		}
		result =  max(result,area);
	}
	cout << result<<endl;
	return 0;
}
