#include<bits/stdc++.h>
#define move aaaa;
using namespace std;


int main(){
	int n,m,k;
	cin >> n >> m >> k;

	int left=1,right=m;

	int mv=0;
	for(int i=0;i<k;i++){
		int p;
		cin >> p;
		if(left<=p && p<=right) continue;
		else if(p < left){
			mv+=(left-p);
			right -= (left -p);
			left = p;
		}else if(p > right){
			mv+=(p-right);
			left += (p-right);
			right=p;
		}
	}
	cout << mv << endl;
	return 0;

}
