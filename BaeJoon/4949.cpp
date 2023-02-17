#include<bits/stdc++.h>

using namespace std;

bool checkp(string s){
	if(s[s.size()-1]!='.') return false;
	stack<char> st;
	for(char c:s){
		if(c=='[' || c=='(') st.push(c);
		else if(c==']' && st.size() && st.top()=='[') st.pop();
		else if(c==')' && st.size() && st.top()=='(') st.pop();
		else if(c==']' || c==')') return false;
	}
	return st.empty();
}
int main(){
	while(1){
		string n;
		getline(cin,n);
		if(n==".") return 0;
		if(checkp(n)) cout << "yes" <<'\n';
		else cout << "no" <<'\n';
	}
	return 0;

}
