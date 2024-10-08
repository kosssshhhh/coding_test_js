#include <bits/stdc++.h>
using namespace std;

const int INF = 987654321;
int n, s[24][24], visited[24], ret = INF;

int go(vector<int>& a, vector<int>& b) {
  pair<int, int> ret;
  for (int i = 0; i < n / 2; i++) {
    for (int j = 0; j < n / 2; j++) {
      if (i == j) continue;
      ret.first += s[a[i]][a[j]];
      ret.second += s[b[i]][b[j]];
    }
  }
  return abs(ret.first - ret.second);
}

int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> s[i][j];
    }
  }

  // 비트마스킹 
  for (int i = 0; i < (1 << n); i++) {
    if (__builtin_popcount(i) != n / 2) continue; // i에 몇 개의 비트가 켜져있는지 확인
    vector<int> start, link;
    for (int j = 0; j < n; j++) {
      if (i & (1 << j))
        start.push_back(j);
      else
        link.push_back(j);
    }
    ret = min(go(start, link), ret);
  }

  cout << ret;

  return 0;
}