#include<bits/stdc++.h>
using namespace std;

int n[9];

void comb(int start, vector<int> b,int k){
	if(b.size()==k){
		int sum =0;
		for(int i:b) sum+=i;
		sort(b.begin(),b.end());
		if(sum == 100){
			for(int i:b) cout << i << '\n';
			exit(0);
		}
	}
	for(int i = start+1;i<9;i++){
		b.push_back(n[i]);
		comb(i,b,k);
		b.pop_back();
	}
	return;
}

int main(){

	for(int i=0;i<9;i++) cin >> n[i];
	vector<int> b;

	comb(-1,b,7);


}
