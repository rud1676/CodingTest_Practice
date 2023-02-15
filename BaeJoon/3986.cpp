#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin >> n;
	int ret=0;
	while(n--){
		string st;
		cin >> st;

		stack<char> s;
		for(char c: st){
			if(s.size() && s.top()==c) s.pop();
			else s.push(c);
		}
		if(s.size()==0) ret++;
	}

	cout << ret <<endl;
}
