#include<bits/stdc++.h>

using namespace std;

int n,m,k;
char arr[100][100];
int vst[100][100];

int dx[4]={0,0,-1,1};
int dy[4]={1,-1,0,0};

int dfs(int y,int x){
	if(y==0 && x == m-1){
		if(vst[y][x]==k) return 1;
		else return 0;
	}

	int ret = 0;
	for(int i=0;i<4;i++){
		int nx = dx[i]+x;
		int ny = dy[i]+y;
		if(nx<0 || ny< 0 || ny>=n || nx>=m || vst[ny][nx] !=0 || arr[ny][nx] == 'T') continue;
		vst[ny][nx] = vst[y][x] +1;
		ret += dfs(ny,nx);
		vst[ny][nx] = 0;
	}
	return ret;
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	cin >> n >> m >> k;
	for(int i=0;i<n;i++){
		string s;
		cin >> s;
		for(int j=0;j<m;j++){
			arr[i][j] = s[j];
		}
	}

	vst[n-1][0]=1;
	cout << dfs(n-1,0);
}
