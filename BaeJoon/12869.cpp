//각 인풋에 대한 bfs하면될듯?
//
#include<bits/stdc++.h>

using namespace std;

int n;
int arr[3];
int vst[61][61][61];

vector<vector<int>> v;
void init(){
	v.push_back({9,3,1});
	v.push_back({9,1,3});
	v.push_back({1,3,9});
	v.push_back({3,1,9});
	v.push_back({3,9,1});
	v.push_back({1,9,3});
}
int cal(int a,int b){
	if(a<=b) return 0;
	return a-b;
}

void print(){
	for(int i=0;i<n;i++){
		cout << arr[i] << " ";
	}
	cout << endl;
}

int bfs(int z,int y,int x){
	vst[z][y][x]=1;

	queue<vector<int>> q;
	q.push({z,y,x});
	while(q.size()){
		int cz= q.front()[0];
		int cy= q.front()[1];
		int cx= q.front()[2];
		q.pop();
		for(int i=0;i<v.size();i++){
			int nz = cal(cz,v[i][0]);
			int ny = cal(cy,v[i][1]);
			int nx = cal(cx,v[i][2]);
			if(vst[nz][ny][nx]==0){
				vst[nz][ny][nx] = vst[cz][cy][cx]+1;
				if(nz==0&&ny==0&&nx==0) return vst[0][0][0];
				q.push({nz,ny,nx});
			}
		}
	}
	return 0;
}



int main(){
	cin >> n;
	for(int i=0;i<n;i++){
		cin >> arr[i];
	}
	init();
	cout << bfs(arr[0],arr[1],arr[2])-1<<endl;
}
