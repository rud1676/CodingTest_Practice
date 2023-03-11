#include<bits/stdc++.h>

using namespace std;

int vst[100001];
int cnt[100001];
int a,b;


void bfs(int a){

	queue<int> q;
	q.push(a);
	while(q.size()){
		int cur = q.front();q.pop();
		for(int a:{cur-1,cur+1,cur*2}){
			if(a<0||a>100000) continue;
			if(vst[a]==0){
				vst[a]=vst[cur]+1;
				cnt[a] +=cnt[cur];
				q.push(a);
			}else if(vst[a]==vst[cur]+1) cnt[a]+=cnt[cur];
		}
	}
}

int main(){
	cin >> a>> b;
	if(a==b){
		cout << "0" << '\n'<<"1"<<'\n';
		return 0;
	}

	vst[a]=1;
	cnt[a]=1;
	bfs(a);


	cout << vst[b]-1 << '\n' << cnt[b] << '\n';
	return 0;
}
