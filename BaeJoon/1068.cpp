#include<bits/stdc++.h>

using namespace std;

bool vst[100];
vector<int> v[53];

int n;
int d;


int dfs(int a){
	vst[a]=1;
	int ret=0;
	int child=0;
	for(int i:v[a]){
		if(i==d) continue;
		if(vst[i]==0){
			ret+=dfs(i);
			child++;
		}
	}
	if(child==0) return 1;
	return ret;

}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;

	int root=0;

	for(int i=0;i<n;i++){
		int input=0;
		cin >> input;
		if(input == -1) root=i;
		else{
			v[input].push_back(i);
		}
	}
	cin >> d;
	if(d==root) cout << 0 << '\n';
	else cout << dfs(root)<<'\n';
	return 0;

}
