#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int a,b,c;

ll cal(ll a,ll b){
	if(b ==1) return a % c;
	ll ret = cal(a,b/2);
	ret = (ret*ret)%c;
	if(b %2) ret = (ret*a)%c;
	return ret;
}

int main(){
	cin >> a >> b >> c;
	cout << cal(a,b) << endl;
	return 0;

}
