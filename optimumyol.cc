//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// 
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
// 
// You should have received a copy of the GNU Lesser General Public License
// along with this program.  If not, see http://www.gnu.org/licenses/.
// 

#include "optimumyol.h"


optimum_yol::optimum_yol() {



}

optimum_yol::~optimum_yol() {
    // TODO Auto-generated destructor stub
}
void optimum_yol :: dijkstra(int A[max][max],int n,int startnode)
{
    int cost[max][max],distance[max],pred[max];
       int visited[max],count,mindistance,nextnode,i,j;
       for(i=0;i<n;i++)
          for(j=0;j<n;j++)
       if(A[i][j]==0)
          cost[i][j]=INFINITY;
       else
          cost[i][j]=A[i][j];
       for(i=0;i<n;i++) {
          distance[i]=cost[startnode][i];
          pred[i]=startnode;
          visited[i]=0;
       }
       distance[startnode]=0;
       visited[startnode]=1;
       count=1;
       while(count<n-1) {
          mindistance=INFINITY;
          for(i=0;i<n;i++)
             if(distance[i]<mindistance&&!visited[i]) {
             mindistance=distance[i];
             nextnode=i;
          }
          visited[nextnode]=1;
          for(i=0;i<n;i++)
             if(!visited[i])
          if(mindistance+cost[nextnode][i]<distance[i]) {
             distance[i]=mindistance+cost[nextnode][i];
             pred[i]=nextnode;
          }
          count++;
       }
       for(i=0;i<n;i++)
       if(i!=startnode) {
         // EV<<"\nDistance of node"<<i<<"="<<distance[i];
        //  EV<<"\nPath="<<i;
           path[i].s_path.push_back(i);

          //EV<<path[i].s_path[0];
          j=i;
          int f=1;
          do {
             j=pred[j];
            //EV<<"<-"<<j;
             path[i].s_path.push_back(j);
           //  EV<<path[i].s_path[f];
             f++;

          }while(j!=startnode);
       }


}
