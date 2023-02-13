#include<bits/stdc++.h>

using namespace std;

vector<string> split(string s,string del){
	int pos;
	vector<string> v;
	while((pos = s.find(del)) != string::npos){
		v.push_back(s.substr(0,pos));
		s.erase(0,pos+del.size());
	}
	v.push_back(s);
	return v;
}
int main(){
	int n;
	cin >> n;
	string pattern;
	cin >> pattern;
	vector<string> patterns = split(pattern,"*");

	for(int i=0;i<n;i++){
		string s;
		cin >> s;
		if(s.size() < patterns[0].size() + patterns[1].size()) cout << ("NE") << '\n';
		else if(s.find(patterns[0]) == 0 && s.substr(s.size()-patterns[1].size(),patterns[1].size()) == patterns[1]) cout << ("DA")<<'\n';
		else cout << ("NE") << '\n';
	}

	return 0;
}
