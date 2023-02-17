//메세지 수 1000
#include<bits/stdc++.h>
typedef long long ll;

using namespace std;

map<ll,ll> m1; //size,
map<ll,ll> m2; //position
vector<pair<ll,ll>> v;
bool cmp(pair<ll,ll> a1,pair<ll,ll> a2){
	if(a1.first==a2.first) return m2[a1.second] < m2[a2.second];
	return a1.first>a2.first;
}

int main(){
	ll n,c;
	cin >> n >> c;

	for(int i=0;i<n;i++){
		ll temp;
		cin >> temp;
		m1[temp]++;
		if(m2.find(temp)==m2.end()){
			m2[temp] = i;
		}
	}
	for(auto i:m1){
		v.push_back({i.second,i.first});
	}

	sort(v.begin(),v.end(),cmp);

	for(auto it:v){
		for(int i=0;i<it.first;i++){
			cout << it.second << " ";
		}
	}

	cout << '\n';
	return 0;

}
