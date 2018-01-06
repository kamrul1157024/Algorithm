
const int sz = 1000;
int visited[sz][sz];
int d[sz][sz];
char grid[sz][sz];
int fx[] = {-1, 1, 0, 0};
int fy[] = {0, 0, 1, -1};
int bfs(int sx, int sy, int r, int c) {
  int cn = 0;
  memset(visited, false, sizeof visited);
  queue<pair<int, int> > q;
  q.push(make_pair(sx, sy));
  visited[sx][sy] = true;
  d[sx][sy] = 0;
  while (!q.empty()) {
    pair<int, int> top;
    top = q.front();
    q.pop();
    for (int i = 0; i < 4; i++) {
      int x = top.first + fx[i];
      int y = top.second + fy[i];
      if (x < r && x >= 0 && y < c && y >= 0 && !visited[x][y] && grid[x][y] == '.') {
        cn++;
        visited[x][y] = true;
        d[x][y] = d[top.first][top.second] + 1;
        q.push(make_pair(x, y));
      }
    }
  }
  return cn;
}