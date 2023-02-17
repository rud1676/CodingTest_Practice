#include<bits/stdc++.h>
using namespace std;

bool cmp(string s1,string s2){
	if(s1.size() == s2.size()){
		return s1 < s2;
	}
	return s1.size() < s2.size();
}
vector<string> v;
void go(string str){
	while(1){
		if(str.size() && str.front()=='0') str.erase(str.begin());
		else break;
	}
	if(str.size()==0) v.push_back("0");
	else v.push_back(str);
}

int main(){

	int n=0;
	cin >> n;
	for(int i=0;i<n;i++){
		string str;
		cin >> str;
		string tstr="";
		for(char c:str){
			if(c<65) tstr+=c;
			else if(tstr.size()){
				go(tstr);
				tstr="";
			}
		}
		if(tstr.size()) go(tstr);
	}


	sort(v.begin(),v.end(),cmp);
	for(auto i: v){
		cout << i << '\n';
	}
	return 0;


}
