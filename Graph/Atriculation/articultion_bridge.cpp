typedef pair<int, int> PII;
const int sz = 10000+5;
vector<int> g[sz];
bool vis[sz];
int d[sz], parent[sz],low[sz];

vector<PII> bridge;
int cnt = 0,br = 0;
void init(int n) {
  for (int i = 0; i <= n; i++)
    g[i].clear();
  memset(vis, false, sizeof vis);
  memset(parent, -1, sizeof parent);
  bridge.clear();
}

void dfsap(int node) {
  low[node] = d[node] = cnt++;
  vis[node] = true;
  for (int i = 0; i < g[node].size(); i++) {
    int curr = g[node][i];
    if (curr == parent[node])
      continue;
    if (vis[curr])
      low[node] = min(d[curr], low[node]);
    if (!vis[curr]) {
      parent[curr] = node;
      dfsap(curr);
      low[node] = min(low[node], low[curr]);
      if (d[node] < low[curr] && parent[curr] != -1) {
        int u = min(node, curr);
        int v = max(node, curr);
        bridge.push_back(make_pair(u, v));
      }
    }
  }
}
