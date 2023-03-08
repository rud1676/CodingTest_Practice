#include<bits/stdc++.h>

using namespace std;


int arr[61][61][61];
int ar[3];

int diff[6][3]= {
	{9,3,1},{9,1,3},{3,9,1},{1,9,3},{1,3,9},{3,1,9}
};

int bfs(int r1,int r2,int r3){

	queue<vector<int>> q;
	q.push({r1,r2,r3});

	while(q.size()){
		int a1,a2,a3;
		a1 = q.front()[0];
		a2 = q.front()[1];
		a3 = q.front()[2];
		if(a1==0&&a2==0&&a3==0){
			return arr[a1][a2][a3];
		}
		q.pop();
		for(int i=0;i<6;i++){
			int b1 = max(a1-diff[i][0],0);
			int b2 = max(a2-diff[i][1],0);
			int b3 = max(a3-diff[i][2],0);
			if(arr[b1][b2][b3]!=0) continue;
			arr[b1][b2][b3] = arr[a1][a2][a3]+1;
			q.push({b1,b2,b3});
		}
	}
	return -1;
}

int main(){
	int n;
	cin >> n;
	for(int i=0;i<n;i++){
		cin >> ar[i];
	}
	cout << bfs(ar[0],ar[1],ar[2]) <<endl;



}
