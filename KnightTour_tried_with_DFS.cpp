//This DFS approach is not correct, see the explanation here...why ....
//https://youtu.be/husnmGdfMmc
#include <bits/stdc++.h>
#include <iostream>
#include <cmath>
#include<iomanip>
#define dbg(x) cout << #x << " = " << x << endl;
#define pans cout << ans << "\n";
#define endl "\n"
#define pb push_back
#define mp make_pair
#define GREY 1
#define WHITE 0
#define BLACK 2
// const ll mod=1e9+7;
typedef long long int ll;
typedef unsigned long long int ull;
typedef long double ld;
using namespace std;
int dx[8] = { 2, 1, -1, -2, -2, -1,  1,  2 };
int dy[8] = { 1, 2,  2,  1, -1, -2, -2, -1 };
int ct=0;
struct cell
{
    int x,y;
};
int grid[8][8];
bool valid(struct cell c,int** color)
{
    if((c.x>=0 && c.x<8) && (c.y>=0 && c.y<8) && color[c.x][c.y]==WHITE)
        return true;
    //else
    return false;
}
void dfs(struct cell source,int** color)//adjList==adjacency list,we want the shortest path distance between source & x,source & x both user defined
{

   color[source.x][source.y]=GREY;
    //cout<<source.x<<" "<<source.y<<endl;
   for(int i=0;i<8;i++)
   {
       cell neighbor;

       neighbor.x=source.x+dx[i];
       neighbor.y=source.y+dy[i];
       if(valid(neighbor,color))
       {
           ++ct;
        grid[neighbor.x][neighbor.y]=ct;
           dfs(neighbor,color);

       }

   }
   color[source.x][source.y]=BLACK;

}

void solve()
{
    int n;
    cin>>n;
    int** color=new int*[n];
    for(int i=0;i<n;i++)
    {
        color[i]=new int[n];
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
            color[i][j]=WHITE;
    }
    int x,y;
    cin>>x>>y;
    struct cell src;
    src.x=x;
    src.y=y;
    dfs(src,color);
    //cout<<"total completed "<<ct<<endl;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
            cout<<setw(2)<<grid[i][j]<<" ";
        cout<<endl;
    }
}

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
// int t;
// cin >> t;
// while (t--)
    solve();
}
