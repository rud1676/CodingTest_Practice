#include<bits/stdc++.h>

using namespace std;

int cnt[100];

int main(){
	int num=0;
	cin >> num;

	if(num<5){
		cout << "PREDAJA" << '\n';
		return 0;
	}
	for(int i=0;i<num;i++){
		string s;
		cin >> s;
		cnt[s[0]-'a']++;
	}

	bool die =true;
	for(int i=0;i<26;i++){
		if(cnt[i] >=5){
			cout << (char)(i+'a');
			die=false;
		}
	}
	if(die) cout << "PREDAJA" << '\n';
	else cout << '\n';
	return 0;



}
