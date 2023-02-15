#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

int modsum=0;
int n=1;
int cnt=0;


int main(){
	while(scanf("%d",&n)!=EOF){
		int ret =1,cnt=1;
		while(1){
			if(ret%n==0){ cout << cnt << '\n'; break;}
			else{
				ret = (ret*10) + 1;
				ret %=n;
				cnt++;

			}
		}



	}
}
