#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

int main() {

  vector<string> result;

  int t;

  cin >> t;

  for (int z = 0; z < t; z++) {
    int n;
    cin >> n;
    vector<vector<int>> vis;
    vector<vector<int>> cus;
    vector<int> home;
    vector<int> goal;

    for (int zz = 0; zz < n + 2; zz++) {
      int y, x;
      cin >> y >> x;
      if (zz == 0) {
        home.push_back(y);
        home.push_back(x);
      } else if (zz == n + 1) {
        goal.push_back(y);
        goal.push_back(x);
      } else {
        vector<int> cu = {y, x};
        cus.push_back(cu);
      }
    }

    queue<vector<int>> q;
    q.push(home);
    bool isntcheck = true;
    while (!q.empty()) {
      vector<int> c = q.front();
      q.pop();
      if (abs(goal[0] - c[0]) + abs(goal[1] - c[1]) <= 1000) {
        result.push_back("happy\n");
        isntcheck = false;
        break;
      } else {
        for (int k = 0; k < cus.size(); k++) {
          vector<int> check = cus[k];
          auto f = find_if(vis.begin(), vis.end(),
                           [&check](const vector<int> &elem) {
                             return elem[0] == check[0] && elem[1] == check[1];
                           });
          if (f == vis.end()) {
            if (abs(c[0] - check[0]) + abs(c[1] - check[1]) <= 1000) {
              q.push(check);
              vis.push_back(check);
            }
          }
        }
      }
    }
    if (isntcheck)
      result.push_back("sad\n");
  }
  for (int i = 0; i < result.size(); i++) {
    cout << result[i];
  }
}
