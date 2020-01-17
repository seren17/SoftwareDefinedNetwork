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

#ifndef __DENEME_6_CONTROLLERR_H_
#define __DENEME_6_CONTROLLERR_H_

#include <omnetpp.h>
#include "optimumyol.h"
#include "Controller_msg_m.h"
#include "Sorgu_m.h"
#include <vector>
#include "Hata_msg_m.h"
using namespace omnetpp;
using namespace std;

struct modull{
   int arr[11][6];
};modull swt_arr;

struct optimum__yol{
    int opty_arr[8];
    int opty_arr2[8];
   // vector<int>opty_vector;
}; optimum__yol optimum_yoll[2];

struct yedek__yol{
    int yedek_arr[9];
};yedek__yol yedek_yol;

/**
 * TODO - Generated class

 */
class Controllerr : public cSimpleModule
{
  protected:
    virtual void initialize();
    virtual void handleMessage(cMessage *msg);


  public:
    simtime_t delay= 0.0000001;
    simtime_t delay2=0.0000001;
    void optimum_yol_func();
    void yedek_yol_func();
    int optindex;
    int hindex;
    int k , sd ,sd1, z , opt_id,opt_m, d,o, st;
    int kid, hid, start_m, finish_m , start_node, finish_node,finish_node_ydk,finish_node_no ;
    int nodenumber;
    bool faildetect;
    int kdizi[7];
    int hdizi[7];
    int yenidizi[5];
    int hatadizi[2];
    int hataindex;



    vector<int>opt1;

};

#endif
