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

#include "Kaynak.h"

Define_Module(Kaynak);
Kaynak::Kaynak()
{
    selfmsg = nullptr;

}

Kaynak::~Kaynak()
{
    cancelAndDelete(selfmsg);

}


void Kaynak::initialize()
{
    dtime = 0.001;
    dtime2 = 1.3;
    selfmsg = new cMessage("selfmsg");

    delay1 = 0.00001;
    seqNum = par("seqNum");
     a = par("seqNum");

   // scheduleAt(simTime(), MsgSource);
     //Source_msg *copy = (Source_msg * ) msg_source->dup();
//    send(msg_source, "gate$o", 0);
            //send(msg_source,"gate$o",0);

            //send(copy,"gate$o",1);
    //scheduleStart(dtime);
    scheduleAt(simTime()+0.000001, selfmsg);
   // scheduleAt(simTime(),MsgSource2);

    EV<<"***"<<simTime()<<"\n";

}
void Kaynak::handleMessage(cMessage *msg)
{
    if (msg == selfmsg){
           Source_msg *msg_source = new Source_msg("msg_source");
           msg_source->setSeqNum(seqNum);
           msg_source->setSourceid(10);
           msg_source->setDestid(11);
           Source_msg *copy = (Source_msg * ) msg_source->dup();
           seqNum ++;
           sendDelayed(msg_source,delay1,gate("gate$o", 0));
           sendDelayed(copy,delay1,gate("gate$o", 1));
           scheduleAt(simTime()+0.000001, selfmsg);
    }
    if ( ++seqNum > 255 )
               seqNum = 1;
  /*  if (msg == selfmsg && a < 10){
               a++;
               Source_msg *msg_source = new Source_msg("msg_source");
               msg_source->setSeqNum(seqNum);
               msg_source->setSourceid(10);
               msg_source->setDestid(11);
               Source_msg *copy = (Source_msg * ) msg_source->dup();
               seqNum ++;
               sendDelayed(msg_source,delay1,gate("gate$o", 0));
               sendDelayed(copy,delay1,gate("gate$o", 1));
               scheduleAt(simTime()+0.000001, selfmsg);
    }*/



 /*   if (msg == selfmsg){
        Source_msg *msg_source = new Source_msg("msg_source");
        msg_source->setSourceid(10);
        msg_source->setDestid(11);

        //msg_source->setTimestamp(dtime2);
        Source_msg *copy = (Source_msg * ) msg_source->dup();


        EV<<"KAYNAK";

        EV<<"\nmsg id = "<<msg_source->getId()<<" sendertime= "<<msg_source->getArrivalTime();
        EV<<" msg id = "<<copy->getId()<<" sendertime= "<<copy->getSendingTime();
      //send(msg_source,"gate$o",0);
      //  send(copy,"gate$o",1);
      sendDelayed(msg_source,delay1,gate("gate$o", 0));
        sendDelayed(copy,delay1,gate("gate$o", 1));



        // scheduleAt(simTime()+0.001, MsgSource);
        scheduleAt(simTime()+0.000001, selfmsg);


       //  dtime2 = dtime2 + 0.1;
    }*/
//cancelAndDelete(MsgSource);

  /*  else{
        Source_msg *msg_source = new Source_msg("msg_source");
                msg_source->setSourceid(2);
                   msg_source->setDestid(3);
                    Source_msg *copy = (Source_msg * ) msg_source->dup();
        send(msg_source,"gate$o",0);
                         send(copy,"gate$o",1);
                         scheduleAt(simTime(), MsgSource2);

    }*/


}

/*void Kaynak::activity()
{
    Source_msg *msg_source = new Source_msg("msg_source");
    msg_source->setSourceid(2);
    msg_source->setDestid(3);
    Source_msg *copy = (Source_msg * ) msg_source->dup();

    //sleep(10.0);

   /*wait(dtime);
    send(msg_source,"gate$o",0);
    send(copy,"gate$o",1);*/

   /* wait(dtime);
    for (int i=0;i<3;i++)
          {

              for (int j=0;j<10;j++)
              {

                  Source_msg *copy = msg_source->dup();
                  Source_msg *copy1 = msg_source->dup();
                  send(copy,"gate$o",0);
                  send(copy1,"gate$o",1);

              }

          }*/

   /* for (int i=0;i<2;i++)
              {
                  for (int j=1;j<2;j++)
                  {

                      Source_msg *copy1 = msg_source->dup();
                      send(copy1,"gate$o",j);
                  }
              }


}*/



