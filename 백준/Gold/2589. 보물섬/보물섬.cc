#include <bits/stdc++.h>
using namespace std;

const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};
int m, n;
string temp;
char a[54][54];
queue<pair<int, int>> q;
int visited[54][54];
int mx = 0, ret = 0;

void bfs(int y, int x) {
  mx = 0;
  visited[y][x] = 1;
  q.push({y, x});
  while (q.size()) {
    tie(y, x) = q.front();
    q.pop();

    for (int i = 0; i < 4; i++) {
      int ny = y + dy[i];
      int nx = x + dx[i];
      if (ny < 0 || nx < 0 || ny >= m || nx >= n) continue;
      if (visited[ny][nx] || a[ny][nx] == 'W') continue;
      visited[ny][nx] = visited[y][x] + 1;

      mx = max(mx, visited[ny][nx]);
      // cout << mx << ' ';
      q.push({ny, nx});
    }
  }
  // cout << '\n';
  // cout << "mx : " << mx << '\n';
}

int main() {
  cin >> m >> n;
  for (int i = 0; i < m; i++) {
    cin >> temp;
    for (int j = 0; j < n; j++) {
      a[i][j] = temp[j];
    }
  }

  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      memset(visited, 0, sizeof(visited));
      while (q.size()) {
        q.pop();
      }
      if (a[i][j] == 'L') {
        // cout << i << " : " << j << '\n';
        bfs(i, j);
        ret = max(mx, ret);
      };
    }
  }
  cout << ret - 1;
  return 0;
}
