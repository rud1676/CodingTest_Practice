#include<bits/stdc++.h>
using namespace std;
char mp[1001][1001];
int vstf[1001][1001];
int vstj[1001][1001];
int n,m;
int jx,jy;
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
vector<pair<int,int>> v;

int main(){
	cin >> n >> m;
	for(int i=0;i<n;i++){
		string s;
		cin >> s;
		for(int j=0;j<m;j++){
			mp[i][j] = s[j];
			if(mp[i][j]=='J'){
				jy=i;
				jx=j;
			}
			if(mp[i][j]=='F'){
				v.push_back({i,j});
			}
		}
	}

	//f bfs
	queue<pair<int,int>> q;
	fill(&vstf[0][0],&vstf[0][0]+1000*1000,123456789);
	for(auto it : v){
		q.push({it.first,it.second});
		vstf[it.first][it.second]=1;
	}
	while(q.size()){
		int x,y;
		tie(y,x) = q.front(); q.pop();
		for(int i=0;i<4;i++){
			int nx=x+dx[i];
			int ny=y+dy[i];
			if(nx<0||ny<0||nx>=m||ny>=n||vstf[ny][nx]!=123456789||mp[ny][nx]!='.') continue;
			vstf[ny][nx] = vstf[y][x]+1;
			q.push({ny,nx});
		}
	}

	//j bfs
	q.push({jy,jx});
	vstj[jy][jx]=1;
	int result=0;
	while(q.size()){
		int x,y;
		tie(y,x) = q.front(); q.pop();
		if(y==0||x==0||y==n-1||x==m-1){
			result =vstj[y][x];
			break;
		}
		for(int i=0;i<4;i++){
			int nx=x+dx[i];
			int ny=y+dy[i];
			if(nx<0||ny<0||nx>=m||ny>=n||vstj[ny][nx]!=0||mp[ny][nx]=='#') continue;
			if(vstf[ny][nx]>vstj[y][x]+1){
				vstj[ny][nx] = vstj[y][x]+1;
				q.push({ny,nx});
			}
		}
	}


	/*
		 for(int i=0;i<n;i++){
		 for(int j=0;j<m;j++){
		 cout << vstj[i][j] << " ";
		 }
		 cout << endl;
		 }
		 cout << endl;
		 for(int i=0;i<n;i++){
		 for(int j=0;j<m;j++){
		 cout << vstf[i][j] << " ";
		 }
		 cout << endl;
		 }
		 cout << endl;
		 */
	cout << ((result==0) ? "IMPOSSIBLE" : to_string(result)) << endl;
}
