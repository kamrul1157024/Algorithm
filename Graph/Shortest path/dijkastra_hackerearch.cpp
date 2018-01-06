const int sz = 100000 + 1;
typedef pair<int, int> PII;
vector<PII> g[sz];
int dist[sz];
bool vis[sz];

void init(int n) {
  for (int i = 0; i <= n; i++)
    g[i].clear();
  memset(vis, false, sizeof vis);
  memset(dist, INT_MAX, sizeof dist);
}

void dijkstra(int sx) {

  dist[sx] = 0;
  multiset<PII> s;

  s.insert(make_pair(0, sx));

  while (!s.empty()) {

    PII curr = *s.begin();
    s.erase(s.begin());

    int u = curr.second;
    int wei = curr.first;
    if (vis[u])
      continue;
    vis[u] = true;

    for (int i = 0; i < g[u].size(); i++) {
      int v = g[u][i].first;
      int w = g[u][i].second;
      if (dist[u] + w < dist[v]) {
        dist[v] = dist[u] + w;
        s.insert(make_pair(dist[v], v));
      }
    }
  }
}
