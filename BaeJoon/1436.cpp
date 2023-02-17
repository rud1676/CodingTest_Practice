#include<bits/stdc++.h>

using namespace std;

int main(){
	int n;
	int cnt=0;
	cin >> n;

	for(int i=0;i<66600000;i++){
		string str = to_string(i);
		if(str.find("666") != string::npos) cnt++;
		if(cnt==n){
			cout << str << '\n';
			return 0;
		}
	}
	return 0;
}
