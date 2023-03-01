#include <bits/stdc++.h>

using namespace std;

int dice[10];
int m[100];
int mal[4];
int msc[4];
vector<vector<int>> v(100);
int r;

void init(){
	for(int i=1;i<=20;i++){
		m[i]=i*2;
	} //i 20 => 32
	m[21]=13; m[22]=16; m[23]=19;
	m[24]=25; //center;
	m[25]=22; m[26]=24;
	m[27]=28; m[28]=27;m[29]=26;
	m[30]=30;m[31]=35;m[32]=999;

	for(int i=0;i<=31;i++){
		v[i].push_back(i+1);
	}
	v[5].push_back(21);
	v[10].push_back(25);
	v[15].push_back(27);

	v[26].pop_back();
	v[26].push_back(24);

	v[29].pop_back();
	v[29].push_back(24);

	v[24].pop_back();
	v[24].push_back(30);

	v[31].pop_back();
	v[31].push_back(20);
	v[20].pop_back();
	v[20].push_back(32);
}

bool ismal(int pos,int ml){
	for(int i=0;i<4;i++){
		if(ml==i) continue; // 자기자신 체크 x
		if(mal[i] == pos && pos!=32) return true;
	}
	return false;
}
int movemal(int pos,int cnt){
	if(v[pos].size()>=2){
		pos = v[pos][1];
		cnt--;
	}

	while(cnt--){
		pos = v[pos][0];
		if(pos==32) break;
	}
	return pos;
}

int bfs(int level){
	if(level==10){return 0; }

	int ret=0;
	for(int i=0;i<4;i++){
		int temp_pos=mal[i];
		if(temp_pos==32) continue;

		int mov_pos= movemal(temp_pos,dice[level]);
		if(!ismal(mov_pos,i)){
			//가능하다면
			mal[i] = mov_pos;
			ret = max(ret, bfs(level+1)+m[mov_pos]);
			mal[i] = temp_pos;
		}
	}

	cout << "mal pos:---" << endl;
	cout << mal[0] << " " <<mal[1] << " "<< mal[2] << " "<< mal[3] << " " <<endl<<endl;
	cout << " ret : " << ret<<endl<<endl;

	return ret;
}
int main(){
	for(int i=0;i<10;i++){
		cin >> dice[i];
	}
	init();

	cout << bfs(0)<<endl;

}



