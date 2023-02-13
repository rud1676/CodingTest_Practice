#include<bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string str;
	int n,m;
	cin >> n >> m;
	map<string,int> poketm;
	vector<string> poketv;


	for(int i=0;i<n;i++){
		cin >> str;
		poketv.push_back(str);
		poketm[str]=i+1;
	}

	for(int i=0;i<m;i++){
		cin >> str;
		if(int a = atoi(str.c_str())) cout << poketv[a-1] <<'\n';
		else cout << poketm[str] <<'\n';
	}

}
