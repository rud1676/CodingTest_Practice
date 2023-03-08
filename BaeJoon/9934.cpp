#include<bits/stdc++.h>
using namespace std;
int n=0;
int arr[1200];
bool vst[1200];
vector<int> v[10];


int main(){
	cin >> n;

	for(int i=1;i<(int)pow(2,n);i++){
		int a;
		cin >> a;
		//cout << " i : " << i<<endl;
		if(i%2==1){
			v[n-1].push_back(a);
			continue;
		}
		for(int j=n;j>1;j--){
			//	cout << "i%(int)pow(2,j-1) : " << i%(int)pow(2,j-1)<<endl;
			if(i%(int)pow(2,j-1)==0){
				//		cout << " n-j :" << n-j<<endl;
				v[n-j].push_back(a); break;
			}
		}
	}

	for(int i=0;i<n;i++){
		for(int b: v[i]){
			cout << b << " " ;
		}
		cout<<'\n';
	}


}
