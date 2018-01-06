#include <bits/stdc++.h>
using namespace std;
const int sz = 100000 + 2;
struct node {
  int val;
  node *left, *right;
  node(){
      left=NULL;
      right=NULL;
      val=0;
  };
  node(node *l, node *r, int v) {
    left = l;
    right = r;
    val = v;
  }
};

int a[sz];
node* version[sz];
void built(node *n, int l, int r) {
  if (l == r) {
    n->val = a[l];
    return;
  }
  int mid = (l + r) / 2;
  n->left = new node();
  n->right = new node();
  built(n->left, l, mid);
  built(n->right, mid + 1, r);
  n->val = n->left->val + n->right->val;
}

void update(node *prev, node *curr, int l, int r, int idx, int val) {
  if (l == r) {
    curr->val = val;
    return;
  }

  int mid = (l + r) / 2;
  if (idx <= mid) {
    curr->right = prev->right;
    curr->left = new node();
    update(prev->left, curr->left, l, mid, idx, val);
  } else {
    curr->left = prev->left;
    curr->right = new node();
    update(prev->right, curr->right, mid + 1, r, idx, val);
  }
  curr->val = curr->left->val + curr->right->val;
}
int query(node *n, int l, int r, int i, int j) {
  if (j < l || i > r)
    return 0;
  if (l >= i && r <= j)
    return n->val;
  int mid = (l + r) / 2;
  int ret1 = query(n->left, l, mid, i, j);
  int ret2 = query(n->right, mid + 1, r, i, j);
  return ret1 + ret2;
}
void deleteT(node *n, int l, int r) {
  if (n == NULL)
    return;
  if (l == r) {
    delete (n);
    return;
  }
  int mid = (l + r) / 2;
  deleteT(n->left, l, mid);
  deleteT(n->right, mid + 1, r);
  delete (n);
}
void deleteTree(int cnt) { 
    for(int i=0;i<=cnt;i++)
    deleteT(version[i],l,r);
 }
int main() {
int n;
scanf("%d",&n);
for(int i=1;i<=n;i++)
{
    scanf("%d",&a[i]);
}
version[0]=new node();
built(version[0],1,n);
int q;

scanf("%d",&q);
int cnt=1;
for(int i=0;i<q;i++)
{
    int tp,x,y,z;
    scanf("%d %d %d %d",&tp,&x,&y,&z);
    if(tp==1)
    {
        node *prev=version[x];
        version[cnt]=new node();
        node *curr=version[cnt];
        update(prev,curr,1,n,y,z);
        cnt++;
    }
    else
    {
        node *curr=version[x];
        int ans=query(curr,1,n,y,z);
        printf("%d\n",ans);
    }
}
#ifndef ONLINE_JUDGE
deleteTree(cnt);
#endif
}
