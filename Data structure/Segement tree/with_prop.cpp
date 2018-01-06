#include <bits/stdc++.h>
using namespace std;
const int sz = 100000+5;
 
struct Data {
  int val[3];
  int prop;
  Data() { prop = 0; }
  Data operator+(Data d) {
    Data result;
    for (int i = 0; i < 3; i++)
      result.val[i] = this->val[i] + d.val[i];
    return result;
  }
 
//   friend ostream &operator<<(ostream &stream,Data dt);
 
};
 
 
// ostream &operator<<(ostream &stream,Data dt)
// {
//     stream<<dt.val[0]<<" "<<dt.val[1]<<" "<<dt.val[2]<<" prop->"<<dt.prop;
//     return stream;
// }
 
 
vector<Data> tree(4*sz,Data());
 
 
 
// void print(int node=1)
// {
//     if(node>=sz-1000)
//     return;
//     print(node*2);
//     cout<<tree[node]<<endl;
//     print(node*2+1);
// }
 
 
void init(int l, int r, int node = 1) {
  if (l == r) {
    tree[node].val[0] = 1;
    tree[node].val[1]=0;
    tree[node].val[2]=0;
    return;
  }
  int mid = (l + r)/2;
  int left = node * 2;
  int right = node * 2 + 1;
  init(l, mid, left);
  init(mid + 1, r, right);
  tree[node]=tree[left]+tree[right];
}
 
void update(int node, int x) {
  x %= 3;
 // if(x==0) return;
 //cout<<"initial->"<<tree[node]<<endl;
  int temp[3];
  for (int i = 0; i < 3; i++)
    temp[i] = tree[node].val[i];
  for (int i = 0; i < 3; i++) {
    tree[node].val[(i + x) % 3] = temp[i];
  }
  tree[node].prop += x;
 
  //cout<<"now->"<<tree[node]<<endl;
}
 
void propagation(int node) {
  int left = node * 2;
  int right = node * 2 + 1;
  update(left, tree[node].prop);
  update(right, tree[node].prop);
  tree[node].prop=0;
}
 
void update(int l, int r, int i, int j, int node = 1) {
  if (j < l || i > r)
    return;
  if (l >= i && r <= j) {
   // tree[node].prop+=1;
    update(node,1);
    return;
  }
  propagation(node);
 
  int mid = (l + r) / 2;
  int left = node * 2;
  int right = node * 2 + 1;
  update(l, mid, i, j, left);
  update(mid + 1, r, i, j, right);
 
  tree[node] = tree[left] + tree[right];
}
 
int query(int l, int r, int i, int j, int node = 1) {
  if (j <l || i > r)
    return 0;
  if (l >= i && r <= j)
    return tree[node].val[0];
    propagation(node);
  int mid = (l + r) / 2;
  int left = node * 2;
  int right = node * 2 + 1;
  int x = query(l, mid, i, j, left);
  int y = query(mid + 1, r, i, j, right);
  return x + y;
}
 
int main() {
   // freopen("in","r",stdin);
    //freopen("out", "w", stdout);
    int t,cs=1;
    cin >> t;
    while (t--) {
      int n, q;
      scanf("%d %d", &n, &q);
      n--;
      init(0, n);
      printf("Case %d:\n",cs++);
      for (int i = 0; i < q; i++) {
        int x, y, z;
        scanf("%d %d %d", &x, &y, &z);
        //      print();
        if (x) {
 
          int ans = query(0, n, y, z);
          printf("%d\n", ans);
        } else
          update(0, n, y, z);
      }
  }
}