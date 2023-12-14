#include <bits/stdc++.h>
#include <iostream>
#include <cmath>
#include<iomanip>
#include<cstring>
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
//void printStack(stack<int>& stk)
//{
//    while(stk.empty()==false)
//    {
//        cout<<stk.top()<<endl;
//        stk.pop();
//    }
//}
vector<int> adjList[100];
vector<int> revAdjList[100];
bool visited[1000];
void dfs(int currNode,stack<int>& nodes)
{
    //cout<<currNode<<endl;
    visited[currNode]=true;
    for(auto neighbour:adjList[currNode])
    {
        if(visited[neighbour]==false)
        {
            dfs(neighbour,nodes);
        }
    }
    nodes.push(currNode);
}
void dfs2(int currNode,set<int>& scc)
{
    scc.insert(currNode);
    //cout<<currNode<<endl;
    visited[currNode]=true;
    for(auto neighbour:revAdjList[currNode])
    {
        if(visited[neighbour]==false)
        {
            dfs2(neighbour,scc);
        }
    }
}
void reverseGraph(int n)
{
    for(int i=0;i<n;i++)
    {
        for(auto neighbour:adjList[i])
        {
            revAdjList[neighbour].push_back(i);
        }
    }
}
void solve()
{
    int e,p,q,x,n;// n =# of nodes, e=# of edges
    cin>>n>>e;
    for(int i=1;i<=e;i++)
    {
        cin>>p>>q;
        //edge is  p -> q;
        adjList[p].push_back(q);
    }
    //graph input done
    stack<int> nodes;//contains nodes in reverse finishing order, top finishes last,vice versa
    dfs(0,nodes);
    //printStack(nodes); for debugging
    reverseGraph(n);
    memset(visited,false,sizeof(visited));
    vector<set<int>> SCCs;
    while(nodes.empty()==false)
    {
        int source=nodes.top();
        nodes.pop();
        set<int> SCC;
        if(visited[source]==false)
            {
                dfs2(source,SCC);
                //cout<<"came back\n";
            }
        if(SCC.empty()==false)
            SCCs.push_back(SCC);
    }
    cout<<"SCCs are: \n";
    for(auto SCC:SCCs)
    {
        for(auto node: SCC)
        {
            cout<<node<<" ";
        }
        cout<<endl;
    }
}
int main()
{
//    freopen("input.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    //fast_io;
   // int t;
    //cin>>t;
//    for(int i=1;i<=t;i++)
    //while(t--)
        solve();
}
// Sample test case
//1st line # of nodes=8 and # of edges=10
//then following 10 lines have p --> q pair
/*
8 10
0 1
1 2
2 0
2 3
3 4
4 7
5 6
6 4
4 5
6 7
 */
