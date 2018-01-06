const int sz = 1000;
vector<int> g[sz];
bool vis[sz];
int d[sz];
int parent[sz];
int low[sz];
vector<int> articulation_point;

int cnt = 0;

void init(int n) {
  for (int i = 0; i <= n; i++)
    g[i].clear();
  memset(vis, false, sizeof vis);
  memset(parent, -1, sizeof parent);
  articulation_point.clear();
}

void dfsap(int node) {
  low[node] = d[node] = cnt++;
  vis[node] = true;
  int no_of_children = 0;
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
      if (d[node] <=low[curr]&&parent[node]!=-1)
        articulation_point.push_back(node);
      no_of_children++;
    }

    if (no_of_children > 1 &&parent[node] == -1)
      articulation_point.push_back(node);
  }
}

