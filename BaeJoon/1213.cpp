#include<bits/stdc++.h>

using namespace std;

int main(){
	map<char,int> m;
	string str;
	cin >> str;

	for(char c : str){
		m[c]++;
	}

	int odd=0;
	string s="";
	char centerchar=0;
	for(char i='Z';i>='A';i--){
		if(m[i]&1){
			odd++;
			centerchar = i;
			m[i]=m[i] -1;
		}
		if(odd>=2){ 
			cout<< "I'm Sorry Hansoo" << '\n';
			return 0;
		}
		for(int j=0;j<m[i];j+=2){
			s=i + s;
			s+=i;
		}
	}
	if(centerchar)s.insert((s.begin()+s.size()/2),centerchar);

	cout <<s<<'\n';

	return 0;

}
