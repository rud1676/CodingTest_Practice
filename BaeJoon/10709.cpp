#include<bits/stdc++.h>
using namespace std;

int arr[101][101];
int n,m;
int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m;

	string str;
	for(int i=0;i<n;i++){
		cin >> str;
		for(int j=0;j<m;j++){
			if(str[j]=='c') arr[i][j]=0;
			else arr[i][j]=-1;
		}
	}

	for(int i=0;i<n;i++){
		int cnt=-1;
		for(int j=0;j<m;j++){
			if(arr[i][j]==0){
				cnt=1;
			}else if(cnt!=-1){
				arr[i][j]=cnt++;
			}
		}
	}

	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cout << arr[i][j] << " ";
		}
		cout << '\n';
	}
	return 0;
}
