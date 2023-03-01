#include<bits/stdc++.h>

using namespace std;


//치킨집 경우를 모두 선택한다. 13Cm
//선택된 치킨집에서 치킨거리를 구하는 알고리즘.
//50*50*100 * 13C6
//
//

int n, m;
vector<pair<int,int>> ck;
vector<pair<int,int>> homes;
int mp[51][51];
int result=9999999;

int calckdist(vector<pair<int,int>> newck){
	int chdist = 0;
	for(auto home : homes){
		int mindist = 9999999;
		for(auto pos : newck){
			mindist = min(mindist,abs(pos.first-home.first) + abs(pos.second - home.second));
		}
		chdist+=mindist;
	}
	return chdist;
}

void comb(vector<int> v,int start){
	if(v.size()==m){
		vector<pair<int,int>> newck;
		for(int i :v){
			newck.push_back(ck[i]);
		}
		result = min(result,calckdist(newck));
		return;
	}

	for(int i=start;i<ck.size();i++){
		v.push_back(i);
		comb(v,i+1);
		v.pop_back();
	}
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	cin >> n >> m;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin >> mp[i][j];
			if(mp[i][j]==2) ck.push_back({i,j});
			if(mp[i][j]==1) homes.push_back({i,j});
		}
	}
	vector<int> v;
	comb(v,0);
	cout << result << endl;



}
