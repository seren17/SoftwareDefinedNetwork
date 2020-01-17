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

#ifndef __DENEME_6_SWÝTCH_H_
#define __DENEME_6_SWÝTCH_H_

#include <omnetpp.h>
#include "Switch.msg_m.h"
#include "Controller_msg_m.h"
#include "Sorgu_m.h"
#include "Source_msg_m.h"
#include "Hata_msg_m.h"


using namespace omnetpp;

/**
 * TODO - Generated class
 */
/*struct a{
    int h =0;
    int in_weight=5;
    int out_weight=5;
    int arr[7][7];
};a nesne1;*/

struct flow__table{
    int host__id;
    int dest__id;
    int port__id;
};

struct group__table{
    int nexthope;
    int prehope;
    int node[2];

};

class Switch : public cSimpleModule
{
  protected:
    virtual void initialize();
    virtual void handleMessage(cMessage *msg);
  public:
    void groupTable();

    Switch();
    virtual ~Switch();
    Switch_msg *selfmsg;
   // void groupTable();
    struct group__table group_table;
    simtime_t delay=  0.00001;
    SimTime delay1 =  0.000002;
    simtime_t delay2= 0.0000001;
    simtime_t delayc =0.0000001;
    simtime_t timeout;
       int counter;
       int countergelen;
       int komsudizi[11];
       int komsuindex, sendergateindex;
       int dizi2[3];
       int Weight_arr[4];
       int index;
       int a;
       int b;
       int kaynakid;
       int hedefid;
       bool kontrol = FALSE;
       int m, f, flwportid = 0;
       struct flow__table flow_table;
       int temp, msg_sayi;
       bool hata_mi;
       //simtime_t skewMax;
       //simtime_t lastFrameReceived;
       //simtime_t_cref time;
       //simtime_t_cref time2;
};

#endif
