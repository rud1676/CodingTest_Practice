#include<bits/stdc++.h>
using namespace std;

int n[26];

int main(){
	string s;
	cin >> s;
	for(char c:s){
		n[c-'a']++;
	}
	for(int i=0;i<26;i++){
		cout << n[i] << " ";
	}
}
