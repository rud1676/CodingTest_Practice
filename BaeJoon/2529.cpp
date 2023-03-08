#include<bits/stdc++.h>
typedef long long ll;
using namespace std;


int vst[10];
char op[10];
int n;

string mx = "";
string mn= "";

bool check(char c1,char c2,char op){
	//cout << " c1 :"<<c1 << " c2 :"<<c2 << " op :" <<op<< endl; 
	if(op=='<'&& c1<c2) return true;
	else if(op=='>'&& c1>c2) return true;
	return false;
}
void brute(int idx,string num){
	if(idx==n+1){
		//cout << " num :"<<num<<endl; 
		//cout << " hasldfhkldsnfljkdnsajfnjsa"<<num<<endl; 
		mn=min(num,mn);
		mx=max(num,mx);
		return;
	}
	for(int i=0;i<10;i++){
		if(vst[i]) continue;
		if(idx==0||check(num[idx-1],i+'0',op[idx-1])){
			vst[i]=1;
			brute(idx+1,num+to_string(i));
			vst[i]=0;
		}
	}
	return;
}

int main(){
	cin >> n;
	for(int i=0;i<n;i++){
		cin >> op[i];
	}
	for(int i=0;i<n+1;i++){
		mx += "0";
		mn+="9";
	}

	brute(0,"");

	cout << mx << '\n' <<mn<<'\n';
}
