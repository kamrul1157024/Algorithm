#include <bits/stdc++.h>
using namespace std;
int n;
int p[1010][1010];
int book[1010];
int match[1010];
int mat[1010][1010];
int dfs(int u) {
  for (int v = 0; v < n; v++) {
    if (book[v] == 0 && p[u][v] == 1) {
      book[v] = 1;
      if (match[v] == -1 || dfs(match[v])) {
        match[v] = u;
        return 1;
      }
    }
  }
  return 0;
}

int main() {
  cin >> n;
  memset(match, -1, sizeof match);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> mat[i][j];
      if (mat[i][j] != 0)
        p[i][j] = 1;
    }
  }
  for (int i = 0; i < n; i++) {
    memset(book, 0, sizeof book);
    dfs(i);
  }
  cout<<n<<endl;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cout << mat[match[i]][j] << " ";
    }
    cout << endl;
  }
}