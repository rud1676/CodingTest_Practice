#include<bits/stdc++.h>

using namespace std;

int main(){
	string s;
	cin >> s;

	string a = s;
	reverse(s.begin(),s.end());

	if(a==s) cout << 0 << '\n';
	cout << 1 << '\n';

	return 0;

}
