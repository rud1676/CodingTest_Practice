#include<bits/stdc++.h>

using namespace std;

int cnt[101];
int main(){
	int a,b;
	int n[3];
	cin >> n[0] >> n[1] >> n[2];

	for(int i=0;i<3;i++){
		cin >> a >> b;
		for(int j=a;j<b;j++){cnt[j]++;}
	}

	int result=0;
	for(int i=1;i<=100;i++){
		if(cnt[i]!=0){
			if(cnt[i]==3) result += 3*n[2];
			if(cnt[i]==2) result += 2*n[1];
			if(cnt[i]==1) result += 1*n[0];
		}
	}
	cout << result<<'\n';
}
