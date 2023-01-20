#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>

using namespace std;

// 회의실 문제는 끝이 중요하게 작용한다함.
int main() {
  int n;
  cin >> n;
  vector<pair<int, int>> conf(n);

  for (int i = 0; i < n; i++) {
    int a, b;
    cin >> a >> b;
    conf[i] = make_pair(a, b);
  }

  sort(conf.begin(), conf.end(), [](pair<int, int> &p1, pair<int, int> &p2) {
    if (p1.second == p2.second) {
      return p1.first < p2.first;

    } else {
      return p1.second < p2.second;
    }
  });

  int curend = 0;
  int confcount = 0;
  for (int i = 0; i < n; i++) {
    if (conf[i].first >= curend) {
      confcount++;
      curend = conf[i].second;
    }
  }
  cout << confcount << endl;

  return 0;
}
