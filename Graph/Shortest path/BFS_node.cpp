const int sz = 100000 + 2;

vector<int> g[sz];
int dist[sz];
bool visited[sz];

void bfs(int sx) {
  memset(visited, false, sizeof visited);

  queue<int> q;
  int i;
  q.push(sx);
  dist[sx] = 1;
  visited[sx] = true;
  int odd = 1, even = 0;
  while (!q.empty()) {
    int top = q.front();
    q.pop();
    for (i = 0; i < g[top].size(); i++) {
      int curr = g[top][i];
      if (!visited[curr]) {
        visited[curr] = true;
        dist[curr] = dist[top] + 1;
        q.push(curr);
      }
    }
  }
}

void clearAll(int n)
{
    for(int i=0;i<=n;i++)
    g[i].clear();
}
