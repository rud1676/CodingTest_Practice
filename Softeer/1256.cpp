//https://softeer.ai/practice/info.do?idx=1&eid=1256&sw_prbl_sbms_sn=148875

#include<bits/stdc++.h>
using namespace std;
int h,k,r;

struct person{
	queue<int> left;
	queue<int> right;
	queue<int> endjob;
};

int main(int argc, char** argv)
{
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> h >> k >>r;
	person p[(int)pow(2,h+1)];
	queue<int> tail[(int)pow(2,h)];

	for(int i=0;i<pow(2,h);i++){
		for(int j=0;j<k;j++){
			int num;
			cin >> num;
			tail[i].push(num);
		}
	}

	int day=0;
	int result=0;

	while(day<r){
		day++;
		if(p[1].endjob.size()){
			result += p[1].endjob.front();
			p[1].endjob.pop();
		}
		for(int i=1;i<(int)pow(2,h);i++){
			if(day%2==1){
				if(i*2<(int)pow(2,h+1) && p[i*2].endjob.size()){
					p[i].left.push(p[i*2].endjob.front());
					p[i*2].endjob.pop();
				}
				if(p[i].left.size()){
					p[i].endjob.push(p[i].left.front());
					p[i].left.pop();
				}
			}else{
				if(i*2+1<(int)pow(2,h+1) && p[i*2+1].endjob.size()){
					p[i].right.push(p[i*2+1].endjob.front());
					p[i*2+1].endjob.pop();
				}
				if(p[i].right.size()){
					p[i].endjob.push(p[i].right.front());
					p[i].right.pop();
				}
			}
			//cout << " i : "<< i <<endl;
			//if(p[i].endjob.size())
			//cout << " p[i].endjob.front() : " << p[i].endjob.front()<<endl;
		}
		for(int i=(int)pow(2,h);i<(int)pow(2,h+1);i++){
			int tn=i-(int)pow(2,h);
			if(tail[tn].size()){
				//cout << "endjob create!!" <<endl;
				p[i].endjob.push(tail[tn].front());tail[tn].pop();
			}
		}

		//for(int i=0;i<pow(2,h+1);i++){
		//	cout << "p["<<i<<"] : "<< p[i].endjob.front() << endl;
		//}

	}
	if(p[1].endjob.size()){
		result += p[1].endjob.front();
	}
	cout << result << '\n';


	return 0;
}
