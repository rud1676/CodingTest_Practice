#include<bits/stdc++.h>
using namespace std;

int n;
int m;

vector<int> v[10001];
int vst[10001];
int dp[10001];

int dfs(int start){
	int ret =1;
	vst[start] = 1;

	for(int it: v[start]){
		if(vst[it]==0){
			ret+=dfs(it);
		}
	}
	return ret;
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	cin >> n >> m;
	int a,b;
	for(int i=0;i<m;i++){
		cin >> a >> b;
		v[b].push_back(a);
	}


	int mx=0;
	for(int i=1;i<=n;i++)
	{
		memset(vst,0,sizeof(vst));
		dp[i] = dfs(i);
		mx = max(mx,dp[i]);
	}

	for(int i=1;i<=n;i++){
		if(dp[i]==mx) cout << i << " ";
	}
	return 0;



}
