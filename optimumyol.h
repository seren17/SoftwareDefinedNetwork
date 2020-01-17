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

#ifndef OPTIMUMYOL_H_
#define OPTIMUMYOL_H_
#include <omnetpp.h>
#define INFINITY 9999
#define max 10
#define max1 10
#include<iostream>
#include<vector>



using namespace omnetpp;
using namespace std;

struct shortestpath{
   vector<int>s_path;
   vector<int>s_path2;
};

class optimum_yol {
public:
    optimum_yol();
    virtual ~optimum_yol();
     void  dijkstra(int A[max][max],int n,int startnode);
      /*int G[max][max]= {{0,5,5,0,0,5,0},
               {5,0,0,5,0,5,0},
               {5,0,0,0,5,0,5},
               {0,5,0,0,5,0,0},
               {0,0,5,5,0,0,5},
               {5,5,0,0,0,0,5},
               {0,0,5,0,5,5,0}};*/

      int G[max][max]= {{0,5,5,0,0,5,0,0,0,0},
                     {5,0,0,0,0,5,0,0,5,0},
                     {5,0,0,0,5,0,0,5,0,5},
                     {0,0,0,0,0,0,5,0,5,0},
                     {0,0,5,0,0,0,5,0,0,0},
                     {5,5,0,0,0,0,0,5,0,0},
                     {0,0,0,5,5,0,0,0,0,5},
                     {0,0,5,0,0,5,0,0,5,5},
                     {0,5,0,5,0,0,0,5,0,5},
                     {0,0,5,0,0,0,5,5,5,0}};

     int H[max][max]= {{0,5,0,0,0,5,0,0,0,0},
                       {5,0,0,0,0,5,0,0,0,0},
                       {0,0,0,0,0,0,0,5,0,5},
                       {0,0,0,0,0,0,5,0,0,0},
                       {0,0,0,0,0,0,5,0,0,0},
                       {5,5,0,0,0,0,0,5,0,0},
                       {0,0,0,5,5,0,0,0,0,5},
                       {0,0,5,0,0,5,0,0,5,5},
                       {0,0,0,0,0,0,0,5,0,5},
                       {0,0,5,0,0,0,5,5,5,0}};

  /*   int H[max][max]= {{0,5,0,0,0,5,0,0,0,0},
                            {5,0,0,0,0,5,0,0,0,0},
                            {0,0,0,0,0,0,0,5,0,5},
                            {0,0,0,0,0,0,5,0,0,0},
                            {0,0,0,0,0,0,5,0,0,0},
                            {5,5,0,0,0,0,0,5,0,0},
                            {0,0,0,5,5,0,0,0,0,5},
                            {0,0,5,0,0,5,0,0,5,5},
                            {0,0,0,0,0,0,0,5,0,5},
                            {0,0,5,0,0,0,5,5,5,0}};*/

       /* int H[max][max]={{0,5,0,0,0,5,0},
                {5,0,0,0,0,5,0},
                {0,0,0,0,0,0,5},
                {0,0,0,0,5,0,0},
                {0,0,5,5,0,0,5},
                {5,5,0,0,0,0,5},
                {0,0,5,0,5,5,0}};*/

       /* int H1[max][max]={{0,5,0,0,0,5,0},
                        {5,0,0,0,0,5,0},
                        {0,0,0,0,0,0,5},
                        {0,0,0,0,0,0,5},
                        {0,0,5,0,0,0,5},
                        {5,5,0,0,0,0,5},
                        {0,0,5,5,5,5,0}};*/

        int u=0;
        int m=10;
        int u1=1;

        int startnode ;
       shortestpath path[10];




};

#endif /* OPTIMUMYOL_H_ */
