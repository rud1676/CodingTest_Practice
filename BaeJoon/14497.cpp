#include<bits/stdc++.h>
#define y1 yyyyy

using namespace std;

int n,m;
int x1,y1,x2,y2;
char mp[301][301];
int vst[301][301];
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};


void bfs(int sy,int sx){
	int cnt=0;
	queue<pair<int,int>> q;

	q.push({sy,sx});
	vst[sy][sx]=1;

	while(mp[y2-1][x2-1]!='0'){
		int x,y;
		cnt++;
		queue<pair<int,int>> qq;

		while(q.size()){
			tie(y,x) = q.front();q.pop();
			for(int i=0;i<4;i++){
				int nx =x+dx[i];
				int ny =y+dy[i];
				if(nx<0||ny<0||nx>=m||ny>=n||vst[ny][nx])continue;
				vst[ny][nx]=cnt;
				if(mp[ny][nx]!='0'){
					mp[ny][nx]='0';
					qq.push({ny,nx});
				}else q.push({ny,nx});
			}
		}
		q=qq;
	}

}

int main(){
	cin >> n>>m;
	cin >> y1 >> x1 >> y2 >> x2;
	for(int i=0;i<n;i++){
		string s;
		cin >>s;
		for(int j=0;j<m;j++){
			mp[i][j]=s[j];
		}
	}
	bfs(y1-1,x1-1);
	cout << vst[y2-1][x2-1] << endl;

}
