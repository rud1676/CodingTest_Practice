#include<bits/stdc++.h>
using namespace std;

int psum[100001];
int main(){
	int n,k;
	cin >> n >> k;
	int temp;
	for(int i=1;i<=n;i++){
		cin >> temp;
		psum[i] = psum[i-1] + temp;
	}

	int ret= -100000004;
	for(int i=k;i<=n;i++){
		ret = max(ret,psum[i] - psum[i-k]);
	}

	cout << ret << '\n';

}
