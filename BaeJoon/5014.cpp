#include <iostream>
#include <queue>
#define MAX 1000001

using namespace std;

int total;
int start, ed;
int up, down;
int v[MAX]; // not use 0
queue<int> q;

int main() {

  cin >> total >> start >> ed >> up >> down;

  if (up == 0 && start < ed) {
    cout << "use the stairs" << endl;
    return 0;
  } else if (down == 0 && start > ed) {
    cout << "use the stairs" << endl;
    return 0;
  } else if (start == ed) {
    cout << 0 << endl;
    return 0;
  }

  q.push(start);
  v[start] = 1;
  while (!q.empty()) {
    int c = q.front();
    q.pop();

    if (c + up > 0 && c + up <= total) {
      if (v[c + up] == 0) {
        q.push(c + up);
        v[c + up] = v[c] + 1;
        if (c + up == ed) {
          cout << v[c] << endl;
          return 0;
        }
      }
    }
    if (c - down > 0 && c - down <= total) {
      if (v[c - down] == 0) {
        q.push(c - down);
        v[c - down] = v[c] + 1;
        if (c - down == ed) {
          cout << v[c] << endl;
          return 0;
        }
      }
    }
  }
  cout << "use the stairs" << endl;

  return 0;
}
