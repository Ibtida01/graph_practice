#include <iostream>
#include<vector> 
using namespace std;

int main()
{
   int e,v;
   cin>>e>>v;
   vector<int> edges[v+1];
   int x,y;
   for(int i=0;i<e;i++)
   {
       cin>>x>>y;
       edges[x].push_back(y);//indicates a directed edge from x to y
   }
   for(int i=0;i<v;i++)
   {
       cout<<"out degree of "<<i<<" is "<<edges[i].size()<<endl;
   }
   int indegree[v+1]={0};
   for(int i=1;i<v+1;i++)
   {
       for(int j=1;j<v+1;j++)
       {
           for(int k=0;k<edges[j].size();k++)
           {
               cout<<edges[j][k]<<" ";
               if(edges[j][k]==i)
                ++indegree[i];
           }
           cout<<endl;
       }
   }
   for(int i=1;i<v+1;i++)
   {
       cout<<"in degree of "<<i<<" is "<<indegree[i]<<endl;
   }
}
/*
9
5
1 2
1 3
1 5
2 4
3 2
4 3
4 5
5 2
5 5
*/
