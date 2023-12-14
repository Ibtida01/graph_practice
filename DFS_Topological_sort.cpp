#include <bits/stdc++.h>
#include <iostream>
#include <cmath>
#include<iomanip>
#define dbg(x) cout << #x << " = " << x << endl;
#define fast_io ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define pans cout << ans << "\n";
#define endl "\n"
#define pb push_back
#define mp make_pair
#define MAX 1000000000
#define pii pair<int,int>
#define EPS 1e-9
// const ll mod=1e9+7;
typedef long long int ll;
typedef unsigned long long int ull;
typedef long double ld;
using namespace std;
vector<int> adjList[100];
bool visited[100];
list<int> l;
void dfs(int currNode)
{
    //currNode has just been discovered
    visited[currNode]=true;
    for(auto neighbour:adjList[currNode])
    {
        if(visited[neighbour]==false)
        {
            dfs(neighbour);
        }

    }
     l.push_front(currNode);
}
void solve()
{
    int n,e;
    cin>>n>>e;
    int p,q; //p -> q edge
    for(int i=0;i<e;i++)
    {
        cin>>p>>q;
        adjList[p].pb(q);
    }
    for(int i=0;i<n;i++)
    {
        if(visited[i]==false)
            {
                dfs(i);
            }
         // l.push_front(i);
    }
  //Topological order:
    for(auto it:l)
        cout<<it<<" ";
    cout<<endl;
}
int main()
{
      solve();
}
/*Sample input
8
13
0 1
0 4
1 2
1 4
2 3
3 1
4 3
5 6
5 7
6 0
6 4
7 5
7 6
*/
