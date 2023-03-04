#include<bits/stdc++.h>

using namespace std;

int n,m;
const int max_int = 300000;
int vst[max_int];
int pv[max_int];

vector<int> bfs(){

	queue<int> q;
	q.push(n);

	while(q.size()){
		int cur = q.front();q.pop();
		if(cur==m) break;
		for(int nc:{cur+1,cur-1,cur*2}){
			if(0<=nc && nc<max_int && vst[nc]==0){
				pv[nc]=cur;
				vst[nc] = vst[cur]+1;
				q.push(nc);
			}
		}
	}

	vector<int> v;
	for(int i=m;i!=n;i=pv[i]){
		v.push_back(i);
	}
	v.push_back(n);
	reverse(v.begin(),v.end());
	return v;
}

int main(){
	cin >> n >> m;
	if(n==m){
		cout << 0 << endl;
		cout << n << endl;
		return 0;
	}

	vst[n]=1;
	vector<int> result = bfs();

	cout << vst[m]-1 << endl;

	for(int i:result){
		cout << i << " ";
	}
	cout << endl;

	return 0;
}
