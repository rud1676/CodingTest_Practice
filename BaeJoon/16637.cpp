#include<bits/stdc++.h>
using namespace std;
int n;
vector<char> op;
vector<int> nums;
int result =-123456789;

int cal(int a,int b,char op){
	if(op=='*') return a*b;
	if(op=='+') return a+b;
	if(op=='-') return a-b;
	return 0;
}

void bfs(int here,int sum){
	if(here == n/2){
		result = max(result,sum);
		return;
	}
	bfs(here+1,cal(sum, nums[here+1], op[here]));
	if(here+2<=n/2){
		int temp = cal(nums[here+1], nums[here+2], op[here+1]);
		bfs(here+2,cal(sum,temp,op[here]));
	}

}
int main(){
	cin >> n;
	string str;
	cin >> str;

	for(int i=0;i<n;i++){
		if(i%2==0) nums.push_back(str[i]-'0');
		else op.push_back(str[i]);
	}
	bfs(0,nums[0]);
	cout  << result << endl;
	return 0;
}


