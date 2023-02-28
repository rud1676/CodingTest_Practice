#include<bits/stdc++.h>

using namespace std;

int n;
int arr[1000001], ret[1000001];
stack<int> s;

int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	cin >> n;
	for(int i=0;i<n;i++){
		cin >> arr[i];
		ret[i] = -1;
		while(s.size() && arr[s.top()] < arr[i]){
			ret[s.top()] = arr[i]; s.pop();
		}
		s.push(i);
	}

	for(int i=0;i<n;i++) cout << ret[i] << " ";


	return 0;
}
