#include<bits/stdc++.h>

using namespace std;

const int max_int=500000;
int n,m;
int vst[2][max_int+4];

int main(){
	cin >> n >> m;
	if(n==m) {
		cout << 0 << endl;
		return 0;
	}

	queue<int> q;
	q.push(n);

	int turn =1;
	bool ok=false;
	vst[0][n]=1;
	while(q.size()){
		m+=turn;
		if(m>max_int){
			break;
		}
		if(vst[turn%2][m]){
			ok=true;
			break;
		}
		int qSize=q.size();
		for(int i=0;i<qSize;i++){
			int here=q.front();q.pop();
			for(int next:{here+1,here-1,here*2}){
				if(next<0 || next>max_int ||vst[turn%2][next]) continue;
				vst[turn%2][next] = vst[(turn+1)%2][here]+1;
				if(next==m){
					ok = true;
					break;
				}
				q.push(next);
			}
			if(ok)break;
		}
		if(ok) break;
		turn++;
	}


	if(ok)
		cout << turn << endl;
	else
		cout << -1 << endl;

	return 0;
}
