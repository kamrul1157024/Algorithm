#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
const int sz = 1000000*5+10 ;
ll phi[sz];
bool mark[sz];
void sievephi(int n) {
  for (int i = 1; i <= n; i++)
    phi[i] = i;

  phi[1] = 1;
  mark[1] = 1;
  for (int i = 2; i <= n; i++) {
    if (!mark[i]) {
      for (int j = i; j <= n; j += i) {
        mark[j] = 1;
        phi[j] = phi[j] / i * (i - 1);
      }
    }
  }
}
//ll cum[sz];
void score()
{
    for(int i=1;i<sz-3;i++)
    {
        phi[i]=phi[i-1]+phi[i]*phi[i];
    }
}
int main() {

    int t,cs=1;
    sievephi(sz-2);
    score();
    scanf("%d",&t);
    while(t--)
    {
        ll a,b;
        scanf("%llu %llu",&a,&b);
        printf("Case %d: %llu\n",cs++,phi[b]-phi[--a]);
    }
}
