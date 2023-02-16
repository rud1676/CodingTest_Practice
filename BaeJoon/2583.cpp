#include<bits/stdc++.h>
using namespace std;

int ma[101][101];
int m,n,k;
int vst[101][101];
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};

int dfs(int y,int x){
	vst[y][x] =1;
	int ret=1;
	for(int i=0;i<4;i++){
		int nx=x+dx[i];
		int ny=y+dy[i];
		if(nx<0||ny<0||nx>=n||ny>=m||ma[ny][nx]==1) continue;
		if(vst[ny][nx]) continue;
		ret += dfs(ny,nx);
	}
	cout  << " y : " <<y<<" x : " << x<< " ret : " << ret<<endl;
	return ret;
}

int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> m >> n >> k;
	vector<int> v;

	for(int i=0;i<k;i++){
		int a,b,c,d;
		cin >> a >> b >> c >>d;
		for(int y=b;y<d;y++){
			for(int x=a;x<c;x++){
				ma[y][x]=1;
			}
		}
	}

	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			if(ma[i][j] == 0 && vst[i][j]==0){
				v.push_back(dfs(i,j));
			}
		}
	}
	sort(v.begin(),v.end());
	cout << v.size() << '\n';
	for(int i : v){
		cout << i << " ";
	}
	cout << '\n';
	return 0;

}
