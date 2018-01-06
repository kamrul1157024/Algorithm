#include <bits/stdc++.h>
using namespace std;
 
#define what(x) cout << #x << "->" << x << endl;
 
const int sz = 311111;
int block = 555;
 
int cnt[1111111], a[sz], ans[sz];
int answer = 0;
struct Node {
  int L, R, i;
//   bool operator<(Node node) {
//     if (this->L / block != node.L / block)
//       return this->L / block < node.L / block;
 
//     return this->R < node.R;
//   }
} q[sz];
 
bool cmp(Node a,Node b)
{
    if(a.L/block!=b.L/block)
    return a.L/block<b.L/block;
    return a.R<b.R;
}
 
 
 
 
void add(int position) {
  cnt[a[position]]++;
  if (cnt[a[position]] == 1)
    answer++;
}
 
void remove(int position) {
 
  cnt[a[position]]--;
  if (cnt[a[position]] == 0)
    answer--;
}
 
int main() {
 // freopen("in","r",stdin);
 // freopen("out", "w", stdout);
  int t, cs = 1;
  scanf("%d", &t);
  while(t--)
  {
      memset(cnt,0,sizeof cnt);
      answer=0;
    int n,m;
    scanf("%d %d", &n,&m);
    for (int i = 1; i <= n; i++)
      scanf("%d", &a[i]);
    for (int i = 0; i < m; i++) {
      scanf("%d %d", &q[i].L, &q[i].R);
      q[i].i = i;
    }
 
    sort(q, q + m,cmp);
    int currL = 1, currR = 1;
    memset(cnt, 0, sizeof cnt);
    for (int i = 0; i < m; i++) {
      int L = q[i].L, R = q[i].R;
      while (currL < L) {
        remove(currL);
        currL++;
      }
      while (currL > L) {
        add(currL - 1);
        currL--;
      }
      while (currR <= R) {
        add(currR);
        currR++;
      }
      while (currR - 1 > R) {
        remove(currR - 1);
        currR--;
      }
      ans[q[i].i] = answer;
    }
    printf("Case %d:\n",cs++);
    for (int i = 0; i < m; i++)
      printf("%d\n", ans[i]);
  }
}
