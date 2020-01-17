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

#ifndef __DENEME_6_KAYNAK_H_
#define __DENEME_6_KAYNAK_H_
#define STACKSIZE 16384


#include <omnetpp.h>
#include "Source_msg_m.h"

using namespace omnetpp;

/**
 * TODO - Generated class
 */
class Kaynak : public cSimpleModule
{
private:
    cMessage *selfmsg;
    int seqNum;
    int a;

public:
   /* Kaynak() : cSimpleModule(STACKSIZE)
{

    }*/   Kaynak();
          virtual ~Kaynak();


   // virtual void activity() override;

    simtime_t dtime;
    simtime_t dtime2;
    simtime_t delay1;
  protected:
    virtual void initialize();
    virtual void handleMessage(cMessage *msg);
};

#endif
