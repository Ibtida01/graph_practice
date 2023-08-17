#include <iostream>
#include<vector>
#include<queue>
using namespace std;

void bfs(int source,vector<int>* adjList,int vCt,int x)//adjList==adjacency list
{
    cout<<"vCt is "<<vCt<<endl;
    int color[vCt+1]={0};//all are white
    int distance[vCt+1];//distance[i] = distance of node i from source node, for s it is 0
    for (int i = 1; i <= vCt; i++) 
             distance[i] = -1; // Initialize with an invalid value
   std::queue<int> q;
   color[source]=1;//source is grey
   q.push(source);
   distance[source]=0;
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
               cout<<"present node distance is "<<distance[adjList[currentNode][i]]<<" and parent is "<<distance[currentNode]<<endl;
           }
       }
       color[currentNode]=2;//black
   }
   cout<<endl;
     if(distance[x]!=INT_MAX)
            {
                cout<<distance[x]<<endl;;
                int temp=x;
                vector<int> path;
                path.push_back(x);
                while(parent[temp]!=-1)
                {
                    int insertNode=parent[temp];
                    path.push_back(insertNode);
                    temp=insertNode;
                }
                for(int i=path.size()-1; i>=0; i--)
                {
                    cout<<path[i]<<" ";
                }
                cout<<endl;
            }
            else cout<<-1<<endl;//this condition will ONLY satisfy if the graph is directed,-1 if x is not reachable from source
    cout<<endl;
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
    int destinationNode;
  cout<<"Enter destination: ";
  cin>>destinationNode;
   bfs(source,edges,v,destinationNode);
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
