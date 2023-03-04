#include<bits/stdc++.h>
using namespace std;

int n,m;
int vst[100002];
int cnt[100002];
int result=9999999;

void bfs(int here){
	queue<int> q;
	q.push(here);

	while(q.size()){
		int cur = q.front();	 q.pop();

		for(auto it:{cur-1,cur+1,cur*2}){
			if(0<=it && it <=100000){
				if(vst[it]==0){
					vst[it]=vst[cur]+1;
					cnt[it]+=cnt[cur];
					q.push(it);
				}else if(vst[it] == vst[cur]+1){
					cnt[it]+=cnt[cur];
				}
			}
		}
	}
}



int main(){
	cin >> n >> m;
	if(n==m){
		cout << 0 << endl << 1 << endl;
		return 0;
	}
	vst[n]=1;
	cnt[n]=1;
	bfs(n);
	cout <<vst[m]-1<<endl <<cnt[m]<<endl;
	return 0;
}
