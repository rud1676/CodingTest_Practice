#include<bits/stdc++.h>

using namespace std;

int n,m;
char mp[1001][1001];
int vst[1001][1001];
int vstf[1001][1001];
int sy,sx;
queue<pair<int,int>> fq;
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};

void bfsf(){
	while(fq.size()){
		int x,y;
		tie(y,x)=fq.front();fq.pop();
		for(int i=0;i<4;i++){
			int nx = x+dx[i];
			int ny = y+dy[i];
			if(nx<0||ny<0||ny>=n||nx>=m||mp[ny][nx]=='#'||vstf[ny][nx]!=123456789)  continue;
			vstf[ny][nx]=vstf[y][x]+1;
			fq.push({ny,nx});
		}
	}	
}

int bfsj(){
	queue<pair<int,int>> jq;
	jq.push({sy,sx});
	vst[sy][sx]=1;
	while(jq.size()){
		int x,y;
		tie(y,x)=jq.front();jq.pop();
		if(y==0||x==0||y==n-1||x==m-1) {
			return vst[y][x];
		}
		for(int i=0;i<4;i++){
			int nx = x+dx[i];
			int ny = y+dy[i];
			if(nx<0||ny<0||ny>=n||nx>=m||mp[ny][nx]=='#'||vst[ny][nx]!=0)  continue;
			if(vst[y][x]+1>=vstf[ny][nx]) continue;
			vst[ny][nx]=vst[y][x]+1;
			jq.push({ny,nx});

		}
	}
	return -1;
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	cin >> n >> m;
	fill(&vstf[0][0],&vstf[0][0]+1001*1001,123456789);
	for(int i=0;i<n;i++){
		string s;
		cin >> s;
		for(int j=0;j<m;j++){
			mp[i][j]=s[j];
			if(mp[i][j]=='J'){
				sy=i;
				sx=j;
			}else if(mp[i][j]=='F'){
				vstf[i][j]=1;
				fq.push({i,j});
			}
		}
	}

	bfsf();
	int result =bfsj();
	if(result==-1)
		cout<< "IMPOSSIBLE\n";
	else cout << result << '\n';

	return 0;


}

