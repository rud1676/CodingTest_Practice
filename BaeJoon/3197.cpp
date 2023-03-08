#include<bits/stdc++.h>

using namespace std;

int n,m;
char mp[1501][1501];
bool swan_vst[1501][1501];
bool water_vst[1501][1501];
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
int lx,ly;


queue<pair<int,int>> swan_temp;
queue<pair<int,int>> swan_q;
queue<pair<int,int>> water_temp;
queue<pair<int,int>> water_q;


bool swan_bfs(){
	while(swan_q.size()){
		int x,y;
		tie(y,x)=swan_q.front();swan_q.pop();
		for(int i=0;i<4;i++){
			int ny=y+dy[i];
			int nx=x+dx[i];
			if(ny<0||ny>=n||nx<0||nx>=m||swan_vst[ny][nx]) continue;
			swan_vst[ny][nx]=1;
			if(mp[ny][nx]=='X'){
				swan_temp.push({ny,nx});
			}else if(mp[ny][nx]=='.'){
				swan_q.push({ny,nx});
			}else if(mp[ny][nx]=='L') return true;

		}
	}
	return false;
}

void water_bfs(){
	while(water_q.size()){
		int x,y;
		tie(y,x)=water_q.front();water_q.pop();
		for(int i=0;i<4;i++){
			int ny=y+dy[i];
			int nx=x+dx[i];
			if(ny<0||ny>=n||nx<0||nx>=m||water_vst[ny][nx]) continue;
			if(mp[ny][nx]=='X'){
				mp[ny][nx]='.';
				water_vst[ny][nx]=1;
				water_temp.push({ny,nx});
			}	
		}
	}
}

void Qclear(queue<pair<int,int>> &q){
	queue<pair<int,int>> temp;
	swap(q,temp);
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	cin >> n >> m;
	for(int i=0;i<n;i++){
		string s;
		cin >> s;
		for(int j=0;j<m;j++){
			mp[i][j]=s[j];
			if(mp[i][j]=='L'){
				lx=j;
				ly=i;
			}	
			if(mp[i][j]=='.' || mp[i][j]=='L' ){
				water_vst[i][j]=1;
				water_q.push({i,j});
			}
		}
	}
	swan_vst[ly][lx]=1;
	swan_q.push({ly,lx});
	int day=0;
	while(true){
		if(swan_bfs()) break;
		water_bfs();
		swan_q=swan_temp;
		water_q=water_temp;
		Qclear(swan_temp);
		Qclear(water_temp);
		day++;
	}
	cout << day <<'\n';
	return 0;
}
