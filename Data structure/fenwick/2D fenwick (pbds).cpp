#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define mp make_pair
using namespace std;
using namespace __gnu_pbds;
typedef pair<int, int> pii;
typedef tree<pii, null_type, less<pii>, rb_tree_tag,
             tree_order_statistics_node_update>
    OST;

const int N = 1001;

OST bit[N];

void insert(int x, int y) {
  for (int i = x; i < N; i += i & -i)
    bit[i].insert(mp(y, x));
}

void remove(int x, int y) {
  for (int i = x; i < N; i += i & -i)
    bit[i].erase(mp(y, x));
}

int query(int x, int y) {
  int ans = 0;
  for (int i = x; i > 0; i -= i & -i)
    ans += bit[i].order_of_key(mp(y + 1, 0));
  return ans;
}
int mat[N][N];
int main()
{
    int t,cs=1;
    scanf("%d",&t);
    while(t--)
    {
        memset(mat,0,sizeof mat);
        int q;
        scanf("%d",&q);
        printf("Case %d:\n",cs++);
        while(q--)
        {
        int c;
        scanf("%d",&c);
        if(c==0)
        {
            int x,y;
            scanf("%d %d",&x,&y);
            if(!mat[x][y])
            {
            insert(x,y);
            mat[x][y]=1;
            }
        }
        else
        {
            int x1,x2,y1,y2;
            scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
            int ans=query(x2,y2)+query(x1-1,y1-1)-query(x1-1,y2)-query(x2,y1-1);
            printf("%d\n",ans);
        }

    }
    }
}
