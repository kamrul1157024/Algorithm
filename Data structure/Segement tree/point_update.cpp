void init(int l, int r,int node=1) {
  if (l == r) {
    tree[node] = 0;
    return;
  }
  int mid = (l + r) / 2;
  int left = mid * 2;
  int right = mid * 2 + 1;
  init(left, l, mid);
  init(right, mid + 1, r);
  tree[node] = tree[left]+ tree[right];
}
void update(int l, int r, int i, ll val, int node = 1) {
  if (i < l || i > r)
    return;
  if (l == r && l == i) {
    tree[node] = val;
    return;
  }
 
  int mid = (l + r) / 2;
  int left = node * 2;
  int right = node * 2 + 1;
  update(l, mid, i, val, left);
  update(mid + 1, r, i, val, right);
 
  tree[node] = tree[left] + tree[right];
}
 
ll query(int l, int r, int i, int j, int node = 1) {
  if (j < l || i > r)
    return 0;
  if (l >= i && r <= j)
    return tree[node];
  int mid = (l + r) / 2;
  int left = node * 2;
  int right = node * 2 + 1;
  ll x = query(l, mid, i, j, left);
  ll y = query(mid + 1, r, i, j, right);
  return x + y;
}
 
