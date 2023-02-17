//https://softeer.ai/practice/info.do?idx=1&eid=1309
#include<bits/stdc++.h>


using namespace std;
int n;
map<int,int> m; //입력한 값 > 숫자갯수
map<int,int> mmm; //입력한 값 > 숫자 순위
vector<int> p; //입력한 값 정렬을 위한.
vector<int> total;
int main(int argc, char** argv)
{
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;//max 100,000
	for(int i=0;i<3;i++){
		p.clear();
		m.clear();
		mmm.clear();
		for(int j=0;j<n;j++){
			int num=0;
			cin >> num;

			p.push_back(num); // 정렬을 위해 담는 백터
			m[num]++;

			if(i==0) total.push_back(num); // 총합을 위해 더함
			else total[j]+=num;
		}

		vector<int> v = p; //순위 순서대로 보이기 위함
		sort(p.begin(),p.end(),greater<int>()); //nlogn
		for(int j=0;j<n;j++){
			if(mmm.find(p[j])==mmm.end()){
				mmm[p[j]]=j+1;
			}
		}
		for(int num : v){
			cout << mmm[num] << " ";
		}
		cout << '\n';
	}

	p.clear();
	m.clear();
	mmm.clear();

	vector<int> v = total; //순위 순서대로 보이기 위함
	sort(total.begin(),total.end(),greater<int>()); //nlogn
	for(int j=0;j<n;j++){
		if(mmm.find(total[j])==mmm.end()){
			mmm[total[j]]=j+1;
		}
	}
	for(int num : v){
		cout << mmm[num] << " ";
	}
	cout << '\n';
	return 0;
}
