#include<bits/stdc++.h>
using namespace std;

void program(){
	int n;
	cin >> n;
	map<string,int> m;
	for(int i=0;i<n;i++)
	{
		string s;
		string b;
		cin >> s >> b;
		m[b]++;
	}
	long long result=1;
	for(auto i : m){
		result *= (i.second+1);
	}
	cout << result -1<<'\n';
}


int main(){
	int t;
	cin >> t;
	for(int i=0;i<t;i++){
		program();
	}
}
