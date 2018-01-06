#include<bits/stdc++.h>
using namespace std;

const int sz=100000+10;

vector< vector<int> > dp(sz,vector<int>(2));
vector<int> g[sz];
void dfs(int node,int par)
{
    dp[node][1]=1;
    dp[node][0]=0;
    for(int i=0;i<g[node].size();i++)
    {
        int v=g[node][i];
        if(v!=par)
        {
            dfs(v,node);
            dp[node][0]+=dp[v][1];
            dp[node][1]+=min(dp[v][1],dp[v][0]);
        }
    }
}


int main()
{

int n;
cin>>n;
for(int i=0;i<n-1;i++)
{
    int x,y;
    cin>>x>>y;
    g[x].push_back(y);
    g[y].push_back(x);
}

dfs(1,-1);
cout<<min(dp[1][0],dp[1][1])<<endl;


}