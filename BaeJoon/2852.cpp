#include<bits/stdc++.h>
using namespace std;

int a=0,b=0;
int win1=0,win2=0;
string prevtime;

int totalminute(string str){
	return atoi(str.substr(0,2).c_str())*60+atoi(str.substr(3,2).c_str());
}

string mintotime(int t){
	string t1 = "00"+to_string(t/60);
	string t2 = "00"+to_string(t%60);
	return t1.substr(t1.size()-2,2) + ":" + t2.substr(t2.size()-2,2);
}

int main(){
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;
	for(int i=0;i<n;i++){
		string ti;
		int team;
		cin >> team >> ti;

		if(a>b) win1 += totalminute(ti) - totalminute(prevtime);
		else if(b>a) win2 += totalminute(ti) - totalminute(prevtime);
		if(team==1) a++;
		else  b++;
		prevtime = ti;
	}
	if(a>b) win1 += totalminute("48:00") - totalminute(prevtime);
	else if(b>a) win2 += totalminute("48:00") - totalminute(prevtime);

	cout << mintotime(win1) << endl;
	cout << mintotime(win2) << endl;
	return 0;
}
