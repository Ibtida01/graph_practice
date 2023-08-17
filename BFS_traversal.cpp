#include <iostream>
#include<vector>
#include<queue>
using namespace std;

void bfs(int source,vector<int>* adjList)//adjList==adjacency list
{
    int vCt=adjList->size()-1;
    int color[vCt+1]={0};//all are white
    int distance[vCt+1];//distance[i] = distance of node i from source node, for s it is 0
    distance[source]=0;
   std::queue<int> q;
   color[source]=1;//source is grey
   q.push(source);
   cout<<source<<" ";
   while(q.empty()==false)
   {
       int currentNode=q.front();
       q.pop();
       for(int i=0;i<adjList[currentNode].size();i++)
       {
           if(color[adjList[currentNode][i]]==0)
           {
               cout<<adjList[currentNode][i]<<" ";
               q.push(adjList[currentNode][i]);
               color[adjList[currentNode][i]]=1;//grey
               distance[adjList[currentNode][i]]=distance[currentNode]+1;
           }
       }
       color[currentNode]=2;//black
   }
}
int main()
{
   int e,v;
   cin>>e>>v;
   vector<int> edges[v+1];
   int x,y;
   //taking graph input
   for(int i=0;i<e;i++)
   {
       cin>>x>>y;
       edges[x].push_back(y);//indicates a directed edge from x to y
   }
   //graph input taken
   int source;
   cout<<"Input source node: ";
   cin>>source;

   bfs(source,edges);
}
/*
graph taken from http://www.shafaetsplanet.com/planetcoding/?p=604
26
10
1 2
1 3 
1 4
2 1
2 6
3 1
3 7
3 8
4 1
4 7
5 8
5 10
6 2
6 10
7 3
7 4
7 8
7 9
8 3
8 5
8 7
9 7
9 10
10 5
10 6
10 9
*/
