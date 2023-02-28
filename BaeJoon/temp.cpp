#include <bits/stdc++.h>

using namespace std;

char arr[65][65];
int n;

string tree(int y,int x,int level){
	if(level==1){
		string ss="";ss.push_back(arr[y][x]);
		return ss;
	}

	string s = "(";
	s+=tree(y,x,level/2);
	s+=tree(y,x+level/2,level/2);
	s+=tree(y+level/2,x,level/2);
	s+=tree(y+level/2,x+level/2,level/2);
	s+=")";
	auto it = s.find("(1111)");
	if(it!=string::npos){
		s.erase(it,6);
		s.insert(it,"1");
	}
	it = s.find("(0000)");
	if(it!=string::npos){
		s.erase(it,6);
		s.insert(it,"0");
	}
	return s;
}

int main(){
	cin >> n;
	for(int i=0;i<n;i++){
		string str;
		cin >> str;
		for(int j=0;j<n;j++){
			arr[i][j]=str[j];
		}
	}
	cout << tree(0,0,n)<<endl;

}



