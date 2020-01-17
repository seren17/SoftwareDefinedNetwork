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

#include "Hedef.h"

Define_Module(Hedef);


void Hedef::initialize()
{
    // TODO - Generated method body
}

void Hedef::handleMessage(cMessage *msg)
{
    Source_msg *Msgs = check_and_cast<Source_msg *>(msg);

    EV<<"\nmsg id = "<<msg->getId()<<" arrivaltime =  "<<msg->getArrivalTime();
    delete msg;

  //  EV<<"drop = ";
   // cObject().drop(msg);
            //msg->drop(msg);
    //EV<<"take = "<<msg->take(msg);

}
