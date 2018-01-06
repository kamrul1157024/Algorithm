#include <bits/stdc++.h>
using namespace std;
const int sz = 100000;
struct Edge {
  int u, v, w;
  Edge(){};
  Edge(int x, int y, int z) { u = x, v = y, w = z; }
};
 
bool cmpA(Edge E1, Edge E2) { return E1.w < E2.w; }
bool cmpD(Edge E1, Edge E2) { return E1.w > E2.w; }
 
vector<Edge> E1, E2;
 
int P1[sz],P2[sz];
 
void make()
{
    for(int i=0;i<sz;i++)
    P1[i]=i,P2[i]=i;
}
int findP1(int x) {
  if (P1[x] == x)
    return x;
  return P1[x] = findP1(P1[x]);
}
int findP2(int x) {
  if (P2[x] == x)
    return x;
  return P2[x] = findP2(P2[x]);
}
 
void process1(Edge &E, int &ans) {
  if (findP1(E.u) != findP1(E.v)) {
    P1[P1[E.u]] = P1[E.v];
    ans += E.w;
  }
}
void process2(Edge &E, int &ans) {
  if (findP2(E.u) != findP2(E.v)) {
    P2[P2[E.u]] = P2[E.v];
    ans += E.w;
  }
}
 
pair<int, int> kruskal() {
  sort(E1.begin(), E1.end(), cmpA);
  sort(E2.begin(), E2.end(), cmpD);
 
  int ss= E1.size();
  int maxi = 0, mini = 0;
  //cout<<ss<<endl;
  for (int i = 0; i < ss; i++) {
    process1(E1[i], mini);
    process2(E2[i], maxi);
  }
 // cout<<mini<<" "<<maxi<<endl;
  return make_pair(maxi, mini);
}
 
int main() {
  int t, cs = 1;
  scanf("%d", &t);
  while (t--) {
    make();
  //  map<pair<int,int>,int> mp;
    int f;
    scanf("%d", &f);
    while (1) {
      int x, y, z;
      scanf("%d %d %d", &x, &y, &z);
      if (x +y+z == 0)
        break;
      E1.push_back(Edge(x, y, z));
      E2.push_back(Edge(x, y, z));
      //mp[make_pair(x,y)]=z;
      //cout<<"C";
    }
   // cout<<"B";
    pair<int, int> ans = kruskal();
    //cout<<"A";
    printf("Case %d: ", cs++);
    int r=ans.first+ans.second;
    if (r%2==0) {
      printf("%d\n",r/2);
    } else {
      printf("%d/%d\n", r,2);
    }
    E1.clear();
    E2.clear();
  }
}