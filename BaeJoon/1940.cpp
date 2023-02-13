#include<bits/stdc++.h>

using namespace std;

int arr[20000];

int main(){
	int n,m;
	cin >> n >> m;

	for(int i=0;i<n;i++) cin>> arr[i];


	int cnt=0;
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			if(arr[i]+arr[j] ==m)  cnt++;
		}
	}

	cout << cnt<<'\n';

}


