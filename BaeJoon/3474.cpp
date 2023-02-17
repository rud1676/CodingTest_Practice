#include<bits/stdc++.h>

using namespace std;
int n=0;

int go(int a){
	if(a>1000000000) return 0;
	int ret = n/a;
	ret += go(a*5);
	return ret;
}

int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	int tc=0;
	cin >> tc;
	while(tc--){
		cin >> n;
		cout << go(5) << '\n';
	}
	return 0;
}
