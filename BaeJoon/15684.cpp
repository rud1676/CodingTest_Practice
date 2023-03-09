#include<bits/stdc++.h>
using namespace std;

int n,m,h;
int mp[100][100];
int vst[100][100];
int result =4;


bool check(){
	for(int i=1;i<=n;i++){
		int start=i;
		for(int j=1;j<=h;j++){
			if(mp[j][start]) start++;
			else if(mp[j][start-1]) start--;
		}
		if(start!=i) return false;
	}
	return true;
}

void dfs(int here,int cnt){
	if(result<=cnt || cnt>4) return;
	if(check()){
		result = min(cnt,result);
		return;
	}
	for(int i=here;i<=h;i++){
		for(int j=1;j<=n;j++){
			if(mp[i][j]||mp[i][j-1]||mp[i][j+1]) continue;
			mp[i][j]=1;
			dfs(i,cnt+1);
			mp[i][j]=0;
		}
	}

}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	cin >> n >> m>> h;

	for(int i=0;i<m;i++){
		int a,b;
		cin >> a>>b;
		mp[a][b]=1;
	}
	dfs(1,0);
	if(result >3) cout << -1 << endl;
	else
		cout << result  <<endl;
	return 0;

}
