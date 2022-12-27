#include <iostream>
#include <queue>

#define MAX 100001
using namespace std;

int v[MAX];
int n, k;

queue<int> q;

void checkandplay(int n, int oldn) {
  if (n >= 0 && n < MAX && v[n] == 0) {
    q.push(n);
    v[n] = v[oldn] + 1;
  }
  if (n == k) {
    cout << v[n] - 1 << endl;
    exit(0);
  }
}
int main() {

  cin >> n >> k;

  q.push(n);
  v[n] = 1;

  while (!q.empty()) {
    int c = q.front();
    q.pop();
    checkandplay(c - 1, c);
    checkandplay(c + 1, c);
    checkandplay(c * 2, c);
    /*
if (c - 1 >= 0 && c - 1 < MAX && v[c - 1] == 0) {
q.push(c - 1);
v[c - 1] = v[c] + 1;
}
if (c + 1 >= 0 && c + 1 < MAX && v[c + 1] == 0) {
q.push(c + 1);
v[c + 1] = v[c] + 1;
}
if (c * 2 >= 0 && c * 2 < MAX && v[c * 2] == 0) {
q.push(c * 2);
v[c * 2] = v[c] + 1;
}
            */
  }
}
