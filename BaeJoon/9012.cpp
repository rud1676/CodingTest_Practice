#include<bits/stdc++.h>

using namespace std;
bool check(string s){
	stack<char> st;
	for(char c : s){
		if(c=='(') st.push(c);
		else{
			if(st.size()) st.pop();
			else return false; 
		}
	}
	return st.empty();
}
int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	int n=0;
	cin >> n;
	for(int i=0;i<n;i++){
		string str;
		cin >> str;

		if(!check(str)) cout << "NO" << '\n';
		else cout << "YES" << '\n';

	}
}
