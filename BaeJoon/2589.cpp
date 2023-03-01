#include<bits/stdc++.h>

using namespace std;

int n,m;
char mp[100][100];
int vst[100][100];
int dx[4]={0,0,-1,1};
int dy[4]={1,-1,0,0};

void bfs(int y,int x){
	queue<pair<int,int>> q;
	q.push({y,x});
	while(q.size()){
		int x,y;
		tie(y,x) = q.front(); q.pop();
		for(int i=0;i<4;i++){
			int nx= x + dx[i];
			int ny= y + dy[i];
			if(nx<0||ny<0||nx>=m||ny>=n||vst[ny][nx]!=0||mp[ny][nx]=='W') continue;
			vst[ny][nx]=vst[y][x]+1;
			q.push({ny,nx});
		}
	}
}

int bomul(){
	int result =0;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			result = max(result,vst[i][j]);
		}
	}
	return result;
}

void print(){
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cout << vst[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}


int main(){
	cin >> n >> m;
	for(int i=0;i<n;i++){
		string s;
		cin >>s;
		for(int j=0;j<m;j++){
			mp[i][j]=s[j];
		}
	}
	int dist=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(mp[i][j]=='L'){
				fill(&vst[0][0],&vst[0][0]+100*100,0);
				vst[i][j]=1;
				bfs(i,j);
				dist=max(dist,bomul());
				//				print();
			}
		}
	}
	cout << dist-1 << endl;

}
