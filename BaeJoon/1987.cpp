#include<bits/stdc++.h>

using namespace std;

int n,m;
char mp[21][21];
int vst[30];
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
int result=1;

void dfs(int y,int x,int cnt){
	/*
		 cout << " v status : ";
		 for(char c : v){
		 cout << c << ", "  ;
		 }
		 cout << endl;
		 */
	result = max(result,cnt);
	for(int i=0;i<4;i++){
		int nx=x+dx[i];
		int ny=y+dy[i];
		if(nx<0||ny<0||ny>=n||nx>=m) continue;
		int next = (int)(mp[ny][nx]-'A');
		if(vst[next]==0){
			vst[next]=1;
			dfs(ny,nx,cnt+1);
			vst[next]=0;
		}
	}
}
int main(){
	cin >> n >>m;
	for(int i=0;i<n;i++){
		string s;
		cin >> s;
		for(int j=0;j<m;j++){
			mp[i][j]=s[j];
		}
	}

	int a =(int)(mp[0][0]-'A');
	vst[a]=1;
	dfs(0,0,1);
	/*
		 for(int i=0;i<n;i++){
		 for(int j=0;j<m;j++){
		 cout << vst[i][j] << " ";
		 }
		 cout << endl;
		 }
		 cout << endl;
		 */


	cout << result << endl;
}
