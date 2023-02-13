#include<bits/stdc++.h>
using namespace std;

int main(){
	string a,b;
	getline(cin,a);
	for(char c : a){
		if(c>='A' && c<='Z'){ // lowercase
			b += ((c - 'a' + 13)%26 + 'a');
		}else if(c>='a' && c<='z'){
			b += ((c - 'A' + 13)%26 + 'A');
		}
		else{
			b+= c;
		}
	}
	cout << b << '\n';
}
