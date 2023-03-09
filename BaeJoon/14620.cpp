#include<bits/stdc++.h>

using namespace std;

int n;
int mp[100][100];
int vst[100][100];
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
int ret=1e9;
int k;

int cal(int y,int x){
	int sum=mp[y][x];
	for(int i=0;i<4;i++){
		int ny = y + dy[i];
		int nx = x + dx[i];
		vst[ny][nx]=1;
		sum+=mp[ny][nx];
	}
	vst[y][x]=1;
	return sum;
}
void erase(int y,int x){
	for(int i=0;i<4;i++){
		int ny = y + dy[i];
		int nx = x + dx[i];
		vst[ny][nx]=0;
	}
	vst[y][x]=0;
}

bool check(int y,int x){
	if(vst[y][x]) return false;
	for(int i=0;i<4;i++){
		int ny = y + dy[i];
		int nx = x + dx[i];
		if(ny<0||nx<0||ny>=n||nx>=n) return false;
		if(vst[ny][nx])return false;
	}
	return true;
}



void brute(int cnt,int hap){
	if(cnt>3 || ret<hap) return;
	if(cnt==3){
		ret=min(ret,hap);
		return;
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(check(i,j)){
				brute(cnt+1,hap+cal(i,j));
				erase(i,j);
			}
		}
	}
}



int main(){
	cin >> n;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin >> mp[i][j];
		}
	}

	brute(0,0);
	cout<< ret<<endl;

}
