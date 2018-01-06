const int sz=100000;
typedef pair<int,int> PII;
vector<PII> g[sz];
int d[sz],p[sz];

void dijkastra(int sx) {

  for (int i = 0; i < sz; i++) {
    d[i] = INT_MAX;
    p[i] = INT_MAX;
  }
  set<PII> q;
  q.insert(make_pair(0, sx));
  d[sx] = 0;
  p[sx] = 0;
  while (!q.empty()) {
    PII curr = *q.begin();
    q.erase(q.begin());
    int u = curr.second;
    for (int i = 0; i < g[u].size(); i++) {
      int v = g[u][i].first;
      int w = g[u][i].second;

      //  cout<<u<< "    "<<v<<"  "<<endl;

      if (d[u] + w < d[v]) {
        // if(d[v]!=INF)
        q.erase(make_pair(d[v], v));
        d[v] = d[u] + w;
        q.insert(make_pair(d[v], v));
      }
    }
  }
}
