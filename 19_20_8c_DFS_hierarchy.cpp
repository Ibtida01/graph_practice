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

map<int,string> id_dir;
bool visited[100];
vector<int> adjList[100];
void dfs(int currNode,int depth)
{
    cout<<id_dir[currNode]<<endl;
    visited[currNode]=true;
    for(auto neighbour:adjList[currNode])
    {
        if(visited[neighbour]==false)
        {
            for(int i=1;i<=depth+1;i++)
                cout<<"    ";
            dfs(neighbour,depth+1);
        }
    }
}
void solve()
{
    id_dir.insert(make_pair(0,"C:\\"));
    id_dir.insert(make_pair(1,"Program Files\\"));
    id_dir.insert(make_pair(2,"Temp\\"));
    id_dir.insert(make_pair(3,"Windows\\"));
    id_dir.insert(make_pair(4,"System32\\"));
    id_dir.insert(make_pair(5,"Tasks\\"));
    id_dir.insert(make_pair(6,"Web\\"));
    id_dir.insert(make_pair(7,"Spool\\"));
    adjList[0].push_back(1);
    adjList[0].push_back(2);
    adjList[0].push_back(3);
    adjList[3].push_back(4);
    adjList[3].push_back(5);
    adjList[3].push_back(6);
    adjList[4].push_back(7);
    dfs(0,0);
}

int main()
{
    //fast_io;
//    int t;
//    cin>>t;
//    while(t--)
        solve();
}


