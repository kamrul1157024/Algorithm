#include <bits/stdc++.h>
using namespace std;
const int sz = 100000 + 1;

int root, nnode;
int isword[sz];
int node[sz][26];
void init() {
  root = 0;
  nnode = 0;
  for (int i = 0; i < 26; i++)
    node[root][i] = -1;
}

void insert(string str) {
  int len = str.size();
  int now = root;
  for (int i = 0; i < len; i++) {
    if (node[now][str[i] - 'a'] == -1) {
      node[now][str[i] - 'a'] = ++nnode;
      for (int j = 0; j < 26; j++)
        node[nnode][j] = -1;
    }
    now = node[now][str[i] - 'a'];
  }

  isword[now] = 1;
}

bool search(string str) {
  int len = str.size();
  int now = root;
  for (int i = 0; i < len; i++) {
    if (node[now][str[i] - 'a'] == -1)
      return false;
    now = node[now][str[i] - 'a'];
  }
  return isword[now];
}

void printAll(int curr=root,string str="")
{
    if(isword[curr])
    {
        cout<<str<<endl;
    }
    for(int i=0;i<26;i++)
    {
        if(node[curr][i]!=-1)
        {
           // cout<<char(i+'a');
            printAll(node[curr][i],str+(char)(i+'a'));
        }
    }
}
int main() {

  int n;
  string str;
  init();
  int t=3;
  while (t--) {
    cin >> str;
     insert(str);

  }
  printAll();
}
