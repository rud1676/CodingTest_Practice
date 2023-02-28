#include<bits/stdc++.h>

using namespace std;

int arr[12][12];

int fill(int n){
	int cnt=0;
	for(int i=0;i<10-n+1;i++){
		for(int j=0;j<10-n+1;j++){

			bool ischange=true;
			for(int a=i;a<i+n;a++){
				for(int b=j;b<j+n;b++){
					if(arr[a][b]!=1){
						ischange=false;
					}
				}
			}

			if(ischange){
				cnt++;

				for(int a=i;a<i+n;a++){
					for(int b=j;b<j+n;b++){
						arr[a][b]=0;
					}
				}
			}
		}
	}
	return cnt;
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	for(int i=0;i<10;i++){
		for(int j=0;j<10;j++){
			cin >> arr[i][j];
		}
	}

	int result=0;
	for(int i=5;i>=1;i--){
		result +=fill(i);
	}
	cout << result<< endl;
	return 0;
}

