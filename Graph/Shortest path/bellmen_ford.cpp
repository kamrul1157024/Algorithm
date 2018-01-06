const int sz = 1000 + 1;
struct Edge {
  int u, v, w;
  Edge(){};
  Edge(int u, int v, int w) {
    this->u = u;
    this->v = v;
    this->w = w;
  }
};

vector<Edge> E;
int dist[sz];
int n;
void bellmen_ford(int s) {
  for (int i = 1; i <= n; i++) {
    dist[i] = 123456789;
  }
  dist[s] = 0;
  for (int i = 1; i <=n; i++) {
    int update = 0;
    for (int j = 0; j < E.size(); j++) {
      if (dist[E[i].v] > dist[E[i].u] + E[i].w) {
        dist[E[i].v] = dist[E[i].u] + E[i].w;
        update++;
      }
    }
    //  if (!update)
    //    break;
  }
}

