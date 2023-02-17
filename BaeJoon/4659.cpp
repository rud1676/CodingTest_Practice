#include<bits/stdc++.h>
using namespace std;

bool checkchar(char c){
	return (c=='i' || c=='o' || c=='a' || c=='e' || c=='u');
}
int main(){
	string str="";
	while(str!="end"){
		cin >> str;
		bool flag=false,is_vowel=false;
		int vcnt=0,ccnt=0;
		char prev='-';
		for(char c:str){
			if(checkchar(c)){
				ccnt=0;
				vcnt++;
				is_vowel=true;
			}else{
				vcnt=0;
				ccnt++;
			}
			if(ccnt==3 || vcnt==3) flag=true;
			if(prev==c && prev!='o' && prev !='e') flag=true;
			prev=c;
		}
		if(!is_vowel) flag=true;
		if(flag){
			cout << "<" << str << "> is not acceptable."<<'\n';
		}else if(str!="end"){
			cout << "<" << str << "> is acceptable."<<'\n';
		}
	}

}
