#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> PII;
typedef long long ll;
const int sz = 1000000;
vector<PII> g[sz];

int T[sz], L[sz];
ll d[sz];
int P[sz][22];

void bfs(int sx) {
  bool vis[sz];
  memset(vis, false, sizeof vis);
  queue<int> q;
  q.push(sx);
  vis[sx] = true;
  L[sx] = 0;
  d[sx] = 0;
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    for (int i = 0; i < g[u].size(); i++) {
      int v = g[u][i].second;
      int w = g[u][i].first;
      if (!vis[v]) {
        vis[v] = true;
        T[v] = u;
        L[v] = L[u] + 1;
        d[v] = d[u] + w;
        q.push(v);
      }
    }
  }
}

void lca_init(int n) {
  memset(P, -1, sizeof P);
  for (int i = 0; i < n; i++) {
    // cout<<T[i]<<endl;
    P[i][0] = T[i];
  }

  for (int j = 1; (1 << j) < n; j++) {
    for (int i = 0; i < n; i++) {
      if (P[i][j - 1] != -1) {
        P[i][j] = P[P[i][j - 1]][j - 1];
      }
    }
  }
};

int lca_query(int p, int q) {
  int log;
  if (L[p] < L[q])
    swap(p, q);
  log = 0;
  while (1) {
    int next = log + 1;
    if ((1 << next) > L[p])
      break;
    log++;
  }

  for (int i = log; i >= 0; i--) {
    if (L[p] - (1 << i) >= L[q])
      p = P[p][i];
  }

  if (p == q)
    return p;

  for (int i = log; i >= 0; i--) {
    if (P[p][i] != -1 && P[p][i] != P[q][i])
      p = P[p][i], q = P[q][i];
  }

  return T[p];
}

ll getDist(int u, int v) {
  int common_par = lca_query(u, v);
  // cout<<common_par<<endl;
  return d[u] + d[v] - 2 * d[common_par];
}

int getKth(int u, int v, int k) {
  int par = lca_query(u, v);
  int curr;
  if (L[u] - L[par] + 1 >= k) {
    curr = u;
    k--;
  } else {
    curr = v;
    k = L[v] + L[u] - 2 * L[par] - k + 1;
  }
  int j = 0;
  // cout<<k<<" oka "<<curr<<endl;

  while (k) {
    if (k & 1) {
      curr = P[curr][j];
    }
    k >>= 1;
    j++;
  }

  return curr;
}

void resetall(int n) {
  for (int i = 0; i <= n; i++)
    g[i].clear();
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n - 1; i++) {
      int x, y, z;
      scanf("%d%d%d", &x, &y, &z);
      g[x].push_back(make_pair(z, y));
      g[y].push_back(make_pair(z, x));
    }
    bfs(1);
    lca_init(n + 1);
    while (1) {
      char cmd[56];
      scanf("%s", cmd);
      if (cmd[1] == 'I') {
        int x, y;
        scanf("%d%d", &x, &y);
        printf("%lld\n", getDist(x, y));
      } else if (cmd[0] == 'K') {
        int u, v, k;
        scanf("%d%d%d", &u, &v, &k);
        printf("%d\n", getKth(u, v, k));
      } else if (cmd[0] == 'D') {
        break;
      }
    }
    resetall(n);
  }
}
