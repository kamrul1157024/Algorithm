#include <bits/stdc++.h>
using namespace std;
const int sz = 1000 + 4;
vector<int> g[sz], rg[sz], scc[sz];
int vis[sz];
stack<int> s;
void dfsts(int u) {
  vis[u] = true;
  for (int i = 0; i < g[u].size(); i++) {
    int v = g[u][i];
    if (!vis[v]) {
      dfsts(v);
    }
  }
  s.push(u);
}

void dfsscc(int u, int cmp) {
  vis[u] = true;
  scc[cmp].push_back(u);
  for (int i = 0; i < rg[u].size(); i++) {
    int v = rg[u][i];
    if (!vis[v]) {
      dfsscc(v, cmp);
    }
  }
}

int findscc(int n) {
  memset(vis, false, sizeof vis);
  for (int i = 1; i <= n; i++) {
    if (!vis[i])
      dfsts(i);
  }
  memset(vis, false, sizeof vis);
  int cmp = 0;
  while (!s.empty()) {
    int top = s.top();
    s.pop();
    if (!vis[top]) {
      dfsscc(top, ++cmp);
    }
  }
  return cmp;
}

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  for (int i = 1; i <= m; i++) {
    int u, v;
    scanf("%d %d", &u, &v);
    g[u].push_back(v);
    rg[v].push_back(u);
  }

  int cmp = findscc(n);
  for (int i = 1; i <= cmp; i++) {
    cout << i << " ->";
    for (int j = 0; j < scc[i].size(); j++) {
      cout << scc[i][j] << " ";
    }
    cout << endl;
  }
}
