#include <bits/stdc++.h>
using namespace std;
const int sz = 500 + 3;
struct Edge {
  int u, v, w;
  Edge(){};
  Edge(int x, int y, int z) { u = x, v = y, w = z; }
};
 
bool cmpA(Edge E1, Edge E2) { return E1.w <E2.w; }
// bool cmpD(Edge E1, Edge E2) { return E1.w > E2.w; }
 
vector<Edge> E1;
 
int P1[sz];
 
void make() {
  for (int i = 0; i < sz; i++)
    P1[i] = i; // P2[i] = i;
}
int findP1(int x) {
  if (P1[x] == x)
    return x;
  return P1[x] = findP1(P1[x]);
}
 
void process1(Edge &E, int &ans) {
  if (findP1(E.u) != findP1(E.v)) {
    P1[P1[E.u]] = P1[E.v];
    ans += E.w;
  }
}
 
int kruskal() {
  sort(E1.begin(), E1.end(), cmpA);
  // sort(E2.begin(), E2.end(), cmpD);
 
  int ss = E1.size();
  int maxi = 0, mini = 0;
  // cout<<ss<<endl;
  for (int i = 0; i < ss; i++) {
    process1(E1[i], maxi);
    // process2(E2[i], maxi);
  }
  // cout<<mini<<" "<<maxi<<endl;
  return maxi;
}
 

 
 
