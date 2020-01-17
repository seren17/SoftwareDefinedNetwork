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

#include "Switch.h"



Define_Module(Switch);

Switch::Switch()
{
    selfmsg = nullptr;
}

Switch::~Switch()
{
    cancelAndDelete(selfmsg);
}


void Switch::initialize()
{
     selfmsg = new Switch_msg("selfmsg");

        msg_sayi = par("limit");
        f = par("limit");
        temp = par("limit");
        counter = par("limit");
        countergelen =par("limit");
        hata_mi =par("hata");
        a = 1;
        b = 1;

        for(int j=0; j<11;j++){
                    komsudizi[j]=0;
                }
                for(int k=0; k<3;k++){
                        dizi2[k]=0;
                    }


    /*cTopology swtnesne;
    swtnesne.extractByProperty("swt");
    cTopology::Node *swtnode = swtnesne.getNode(nesne1.h);
    Weight_arr[h]=0;
    nesne1.h++;
    //EV<<swtnode->getModule()<<"\n";
    //EV<<swtnode->getLinkOut(j)->getWeight();

    for(int i = 0; i<swtnode->getNumOutLinks();i++){
        swtnode->getLinkOut(i)->setWeight(nesne1.in_weight++);
        swtnode->getLinkIn(i)->setWeight(nesne1.out_weight++);


       // EV<<swtnode->getLinkIn(i)->getWeight()<<"\n";
        //EV<<swtnode->getLinkIn()->getWeight()<<"\n";
    }*/


    cTopology knesne;
    knesne.extractByProperty("kaynak");
    cTopology::Node *knode = knesne.getNode(0);
    kaynakid = knode->getModuleId();
    cTopology hnesne;
    hnesne.extractByProperty("hedef");
    cTopology::Node *hnode = hnesne.getNode(0);
    hedefid = hnode->getModuleId();

    for (int i = 1; i <  gate("gate$o", 1)->getVectorSize(); i++){
        if(gate("gate$o", i)->getNextGate()->getOwnerModule()->getId()==hedefid){
            komsudizi[i]=hedefid;
           //EV<<"\n"<<getId()<<" == "<<i<<" ___" <<hedefid;

        }

    }
   /* if(getId() == 3){ //switch
        group_table.node[0] = 76;
        group_table.node[1] = 8;

            }*/
  /*  if(getId() == 4){ //switch1
           group_table.node[0] = 77;
           group_table.node[1] = 8;
       }*/
  if(getId() == 5){ //switch2
           // group_table.node[0] = 3;
           // group_table.node[1] = 14;
        group_table.node[0] = 12;
        group_table.node[1] = 7;
            }
   /* if(getId() ==6){ //switch3
            group_table.node[0] = 13;
            group_table.node[1] = 11;
          //  group_table.node[0] = 9;
         //   group_table.node[1] = 11;

           }*/
   if(getId() == 7){ //switch4
               group_table.node[0] = 5;
               group_table.node[1] = 11;
           // group_table.node[0] = 9;
           // group_table.node[1] = 11;
    }
   /* if(getId() == 8){ //switch5
         //  group_table.node[0] = 4;
         //  group_table.node[1] = 12;
           group_table.node[0] = 3;
           group_table.node[1] = 12;
    }*/
    if(getId() == 9){ //switch6
            group_table.node[0] = 14;
            group_table.node[1] = 7;
          // group_table.node[1] = 14;
          // group_table.node[0] = 6;
          //  group_table.node[1] = 7;
        }
  /*  if(getId() == 12){ //switch7
                group_table.node[0] = 8;
                group_table.node[1] = 5;
              // group_table.node[1] = 13;
              // group_table.node[0] = 5;
              //  group_table.node[1] = 7;
            }*/
   /* if(getId() == 13){ //switch8
                   group_table.node[0] = 12;
                   group_table.node[1] = 6;
                  // group_table.node[0] = 4;
                  // group_table.node[1] = 14;

               }*/
    if(getId() == 14){ //switch9
                    group_table.node[0] = 5;
                    group_table.node[1] = 9;
                  // group_table.node[1] = 13;
                  // group_table.node[0] = 9;
                  //  group_table.node[1] = 7;
                }



            flow_table.dest__id=0;
            flow_table.host__id=0;
            flow_table.port__id=0;


        //lastFrameReceived = simTime();
            //scheduleAt(simTime(), selfmsg);

       Switch_msg *msg_switch = new Switch_msg("msg_switch");


        for (int i = 1; i <  gate("gate$o", 1)->getVectorSize(); ++i) {

           Switch_msg *copy = msg_switch->dup();
           //send(copy, "gate$o", i);
          // EV<<gate("gate$o", 1)->getNextGate()-><<"\n";
           if(gate("gate$o", i)->getNextGate()->getOwnerModule()->getId()!=kaynakid && gate("gate$o", i)->getNextGate()->getOwnerModule()->getId()!=hedefid){
               counter++;
              // if(getId()== 6 && gate("gate$o", i)->getNextGate()->getOwnerModule()->getId()==4 ){
               //  sendDelayed(copy,delay1,gate("gate$o", i));

             // }
            //   else{
                   sendDelayed(copy,delay2,gate("gate$o", i));
           //  }

           }
    }

}
void Switch::handleMessage(cMessage *msg){  // protection
/*if(msg == selfmsg){
    Switch_msg *msg_switch = new Switch_msg("msg_switch");


            for (int i = 1; i <  gate("gate$o", 1)->getVectorSize(); ++i) {

               Switch_msg *copy = msg_switch->dup();
               //send(copy, "gate$o", i);
              // EV<<gate("gate$o", 1)->getNextGate()-><<"\n";
               if(gate("gate$o", i)->getNextGate()->getOwnerModule()->getId()!=kaynakid && gate("gate$o", i)->getNextGate()->getOwnerModule()->getId()!=hedefid){
                   counter++;
                  // if(getId()== 6 && gate("gate$o", i)->getNextGate()->getOwnerModule()->getId()==4 ){
                   //  sendDelayed(copy,delay1,gate("gate$o", i));

                 // }
                //   else{
                       sendDelayed(copy,delay2,gate("gate$o", i));
               //  }

               }
        }
            scheduleAt(simTime()+0.006, selfmsg);
}*/
 /*   if(strcmp("switch",getName())==0 && msg_sayi==25 && hata_mi==false){
           hata_mi = true;
           msg_sayi=26;
       drop(msg);

   }
       else if(strcmp("msg_source",msg->getName())==0 && msg->getArrivalGate()->getIndex()!=0 && hata_mi==true){
           drop(msg);
       }

*/
     if(strcmp("msg_switch",msg->getName())==0){

            if(counter != countergelen){         //&& msg->getArrivalTime()==delay2
                   Switch_msg *Msg1 = check_and_cast<Switch_msg *>(msg);
                     komsuindex = msg->getArrivalGate()->getIndex();
                     komsudizi[komsuindex]= msg->getSenderModuleId();

                     countergelen++;
                }
            else{
                EV<<"***mesaj gec geldi ya da link koptu***";
                countergelen++;
               }

            if(counter==countergelen){
                    kontrol = TRUE;
                    Controller_msg *msg_contrllr = new Controller_msg("msg_contrllr");
                    msg_contrllr->setKontrol_dizi(0, getId());
                    for(int i=1; i<5;i++){
                        msg_contrllr->setKontrol_dizi(i, komsudizi[i]);
                       //EV<<"/*//*/"<<komsudizi[i-1]<<"\n";
                       // msg_contrllr->setWeight_arr(i, weight_arr)
                    }
                    send(msg_contrllr,"gate$o", 0);
                    //counter = 0;
                }
        }


    else if(strcmp("msg_source",msg->getName())==0 && msg->getArrivalGate()->getIndex()!=0 ){
        msg_sayi++;
        EV<<"mesaj sayisi =="<<msg_sayi;

        Source_msg *Msg3 = check_and_cast<Source_msg *>(msg);

        if(msg_sayi ==3  && strcmp("switch2",getName())==0){
            //drop(msg);
          //  delete msg;
            temp++;
            EV<<"TEMP"<< temp;
          //  EV<<"\n*****DRopppp";
           // groupTable();
        }
        else if(msg->getSenderModuleId()==group_table.node[0]){

            for (int i = 1; i <  gate("gate$o", 1)->getVectorSize(); i++){
               if(gate("gate$o", i)->getNextGate()->getOwnerModule()->getId()== group_table.node[1]){

                   sendDelayed(msg,delay,gate("gate$o", i));
                           }
                   }

        }

        else if(flow_table.host__id == Msg3->getSourceid() && flow_table.dest__id == Msg3->getDestid())
       {
           flwportid=flow_table.port__id;
           //EV<<"flowport"<<flwportid;
           sendDelayed(msg, delay, gate("gate$o",flwportid));
       }

       else
      {
          Sorgu*msg_sorgu = new Sorgu ("msg_sorgu");
          msg_sorgu->setKaynakid(Msg3->getSourceid());
          msg_sorgu->setHedefid(Msg3->getDestid());
          sendDelayed(msg_sorgu,delayc,gate("gate$o", 0));
          sendDelayed(msg,delayc,gate("gate$o", 0));
          //send(msg_sorgu, "gate$o",0);
         // send(msg,"gate$o",0);
          //delete msg;
     }

}

    else if(strcmp("msg_sorgu",msg->getName())==0){

               Sorgu *Msg5 = check_and_cast<Sorgu *>(msg);

                   flow_table.host__id =Msg5->getKaynakid();
                   flow_table.dest__id =Msg5->getHedefid();
                   flow_table.port__id =Msg5->getGateindex();

                   sendergateindex = Msg5->getGateindex();


                   delete msg;

                }
    else
        EV<<"\n";


   if (strcmp("msg_source",msg->getName())==0 && strcmp("controllerr",msg->getSenderModule()->getName())==0){

             sendDelayed(msg,delay,gate("gate$o", sendergateindex));

              }

}




/*void Switch::handleMessage(cMessage *msg) // Rstorasyon1
{
    if(strcmp("switch",getName())==0 && msg_sayi==25 && hata_mi==false){
        hata_mi = true;
        msg_sayi=26;
        temp++;
    drop(msg);
    Hata_msg * msg_hata = new Hata_msg("msg_hata");
                           msg_hata->setKynkid(10);
                           msg_hata->setHdfid(11);

                           flow_table.dest__id=0;
                           flow_table.host__id=0;
                           flow_table.port__id=0;

                           //send(msg_hata,"gate$o",0);
                           sendDelayed(msg_hata,delay,gate("gate$o", 0));
}
    else if(strcmp("msg_source",msg->getName())==0 && msg->getArrivalGate()->getIndex()!=0 && hata_mi == true){
        temp++;
        EV<<"DROP SAYISI ="<<temp;
        drop(msg);
    }
    else if(strcmp("msg_sorgu2",msg->getName())==0){
             EV<<"SORGU2";
            hata_mi = false;
             a=2;
               Sorgu *Msg6 = check_and_cast<Sorgu *>(msg);
               flow_table.host__id =Msg6->getKaynakid();
               flow_table.dest__id =Msg6->getHedefid();
               flow_table.port__id =Msg6->getGateindex();
               delete msg;

           }

else if(strcmp("msg_switch",msg->getName())==0){

        if(counter != countergelen){
                 Switch_msg *Msg1 = check_and_cast<Switch_msg *>(msg);
                 komsuindex = msg->getArrivalGate()->getIndex();
                 komsudizi[komsuindex]= msg->getSenderModuleId();

                 countergelen++;
            }
        else{
            EV<<"***mesaj gec geldi ya da link koptu***";
            countergelen++;
           }

        if(counter==countergelen){
                kontrol = TRUE;
                Controller_msg *msg_contrllr = new Controller_msg("msg_contrllr");
                msg_contrllr->setKontrol_dizi(0, getId());
                for(int i=1; i<5;i++){
                    msg_contrllr->setKontrol_dizi(i, komsudizi[i]);
                   //EV<<"/*//*/"<<komsudizi[i-1]<<"\n";
                   // msg_contrllr->setWeight_arr(i, weight_arr)
                }
                send(msg_contrllr,"gate$o", 0);
            }
    }


 else if(strcmp("msg_source",msg->getName())==0 && msg->getArrivalGate()->getIndex()!=0 && hata_mi == false){
              // Sorgu*msg_sorgu = new Sorgu ("msg_sorgu");

               Source_msg *Msg3 = check_and_cast<Source_msg *>(msg);
                if(strcmp("switch",getName())==0 ){
                    msg_sayi++;
                    EV<<"MESAJ SAYISI = "<<msg_sayi;
                }

                  if(flow_table.host__id == Msg3->getSourceid() && flow_table.dest__id == Msg3->getDestid())
                   {
                       flwportid=flow_table.port__id;
                      // sendDelayed(msg,delay2,gate("gate$o", flwportid));
                       //send(msg, "gate$o", flwportid);

                       EV<<"flowport"<<flwportid;
                       sendDelayed(msg, delay, gate("gate$o",flwportid));
                   }

                  else
                  {
                      Sorgu*msg_sorgu = new Sorgu ("msg_sorgu");
                      msg_sorgu->setKaynakid(Msg3->getSourceid());
                      msg_sorgu->setHedefid(Msg3->getDestid());
                      sendDelayed(msg_sorgu,delayc,gate("gate$o", 0));
                      sendDelayed(msg,delayc,gate("gate$o", 0));
                      //send(msg_sorgu, "gate$o",0);
                     // send(msg,"gate$o",0);
                      //delete msg;
                 }
            }


    /*  else if(strcmp("msg_sorgu3",msg->getName())==0){
          EV<<"SORGU3";
                 Sorgu *Msg6 = check_and_cast<Sorgu *>(msg);
                 flow_table.host__id =0;
                 flow_table.dest__id =0;
                 flow_table.port__id =0;
                 delete msg;

             }*/

/*
    else if(strcmp("msg_sorgu",msg->getName())==0){

            Sorgu *Msg5 = check_and_cast<Sorgu *>(msg);
         //  if((Msg5->getGateindex()) == 0 ){
               /* Hata_msg * msg_hata = new Hata_msg("msg_hata");
                msg_hata->setKynkid(Msg5->getKaynakid());
                msg_hata->setHdfid(Msg5->getHedefid());
                sendergateindex = 0;
                //sendDelayed(msg_hata,delay2,gate("gate$o", 0));
                hata_mi = true;*/
           /*      flow_table.host__id =0;
                flow_table.dest__id =0;
                flow_table.port__id =0;*/
                //send(msg_hata,"gate$o",0);
                //sendDelayed(msg_hata,delay,gate("gate$o", 0));


          //  }

/*
               sendergateindex = Msg5->getGateindex();
                // EV<<"\nswitch = "<<getId()<<" ** gonderilecek port id =="<<Msg5->getGateindex();
                flow_table.host__id =Msg5->getKaynakid();
                flow_table.dest__id =Msg5->getHedefid();
                flow_table.port__id =Msg5->getGateindex();
                //EV<<"\nkim = "<<getId()<<" = "<<sendergateindex;
                delete msg;



        }

      if (strcmp("msg_source",msg->getName())==0 && strcmp("controllerr",msg->getSenderModule()->getName())==0){

        EV<<msg->getArrivalModuleId()<<" == switch== "<<sendergateindex;
                        //send(msg,"gate$o",sendergateindex);
                        sendDelayed(msg,delay,gate("gate$o", sendergateindex));
                        // delete msg;
       }

}*/


/*void Switch::handleMessage(cMessage *msg) // Restorasyon2
{
    if(strcmp("msg_switch",msg->getName())==0){

        if(counter != countergelen && msg->getArrivalTime()==delay2){
             Switch_msg *Msg1 = check_and_cast<Switch_msg *>(msg);
             komsuindex = msg->getArrivalGate()->getIndex();
             komsudizi[komsuindex]= msg->getSenderModuleId();

             countergelen++;
        }
    else{
        EV<<"***mesaj gec geldi ya da link koptu***";
        countergelen++;
       }

    if(counter==countergelen){
            kontrol = TRUE;
            Controller_msg *msg_contrllr = new Controller_msg("msg_contrllr");
            msg_contrllr->setKontrol_dizi(0, getId());
            for(int i=1; i<5;i++){
                msg_contrllr->setKontrol_dizi(i, komsudizi[i]);
               //EV<<"////"<<komsudizi[i-1]<<"\n";
               // msg_contrllr->setWeight_arr(i, weight_arr)
            }
            send(msg_contrllr,"gate$o", 0);
        }
}
    else if(strcmp("msg_source",msg->getName())==0 && msg->getArrivalGate()->getIndex()!=0 ){
                      // Sorgu*msg_sorgu = new Sorgu ("msg_sorgu");
                       Source_msg *Msg3 = check_and_cast<Source_msg *>(msg);
                           if(flow_table.host__id == Msg3->getSourceid() && flow_table.dest__id == Msg3->getDestid())
                           {
                               flwportid=flow_table.port__id;
                              // sendDelayed(msg,delay2,gate("gate$o", flwportid));
                               //send(msg, "gate$o", flwportid);

                               EV<<"flowport"<<flwportid;
                               sendDelayed(msg, delay, gate("gate$o",flwportid));
                           }

                          else if(getId() != 4){
                              Sorgu*msg_sorgu = new Sorgu ("msg_sorgu");
                               msg_sorgu->setKaynakid(Msg3->getSourceid());
                               msg_sorgu->setHedefid(Msg3->getDestid());
                               sendDelayed(msg_sorgu,delay,gate("gate$o", 0));
                               sendDelayed(msg,delay,gate("gate$o", 0));
                               //send(msg_sorgu, "gate$o",0);
                              // send(msg,"gate$o",0);
                               //delete msg;

                           }
                          else if(getId() == 4){
                              Source_msg *Msg4 = check_and_cast<Source_msg *>(msg);
                          if(hata_mi == true){
                             temp++;
                             EV<<"\nson drop sayisi = "<<temp;
                             drop(msg);
                          }
                          else{
                              drop(msg);
                             temp++;
                             EV<<"\nilk drop sayisi = "<<temp;
                             drop(msg);
                          Hata_msg * msg_hata = new Hata_msg("msg_hata");
                          msg_hata->setKynkid(Msg4->getSourceid());
                          msg_hata->setHdfid(Msg4->getDestid());
                          sendergateindex = 0;
                          //sendDelayed(msg_hata,delay2,gate("gate$o", 0));
                          hata_mi = true;
                          flow_table.host__id =0;
                          flow_table.dest__id =0;
                          flow_table.port__id =0;
                          //send(msg_hata,"gate$o",0);
                          sendDelayed(msg_hata,delay,gate("gate$o", 0));

                          }

                    }


   else if(strcmp("msg_sorgu2",msg->getName())==0){
                    Sorgu *Msg6 = check_and_cast<Sorgu *>(msg);
                    flow_table.host__id =Msg6->getKaynakid();
                    flow_table.dest__id =Msg6->getHedefid();
                    flow_table.port__id =Msg6->getGateindex();
                    delete msg;
   }


    }
    else if(strcmp("msg_sorgu",msg->getName())==0){
        Sorgu *Msg5 = check_and_cast<Sorgu *>(msg);
        sendergateindex = Msg5->getGateindex();
        EV<<"\nswitch = "<<getId()<<" ** gonderilecek port id =="<<Msg5->getGateindex();
        flow_table.host__id =Msg5->getKaynakid();
        flow_table.dest__id =Msg5->getHedefid();
        flow_table.port__id =Msg5->getGateindex();
        //EV<<"\nkim = "<<getId()<<" = "<<sendergateindex;
        delete msg;
    }
    else if(strcmp("msg_sorgu2",msg->getName())==0){
        Sorgu *Msg6 = check_and_cast<Sorgu *>(msg);
        flow_table.host__id =Msg6->getKaynakid();
        flow_table.dest__id =Msg6->getHedefid();
        flow_table.port__id =Msg6->getGateindex();
        delete msg;
    }

    if (strcmp("msg_source",msg->getName())==0 && strcmp("controllerr",msg->getSenderModule()->getName())==0){

                  //EV<<msg->getArrivalModuleId()<<" == switch== "<<sendergateindex;
                   //send(msg,"gate$o",sendergateindex);
                   sendDelayed(msg,delay,gate("gate$o", sendergateindex));
                   // delete msg;


    }


}*/


  void Switch::groupTable(){
  /*   if(getId() == 3){ //switch
           group_table.node[0] = 76;
           group_table.node[1] = 8;
               }*/
     /*  if(getId() == 4){ //switch1
              group_table.node[0] = 14;
              group_table.node[1] = 8;
          }*/
      /* if(getId() == 5){ //switch2
               group_table.node[0] = 3;
               group_table.node[1] = 14;
          // group_table.node[0] = 3;
          // group_table.node[1] = 9;
               }*/
      /* if(getId() ==6){ //switch3
               group_table.node[0] = 9;
               group_table.node[1] = 11;
              }*/
   /*   if(getId() == 7){ //switch4
                  group_table.node[0] = 5;
                 // group_table.node[1] = 11;
               //group_table.node[0] = 9;
               group_table.node[1] = 11;
       }*/
    /*   if(getId() == 8){ //switch5
              //group_table.node[0] = 4;
              group_table.node[0] = 3;
              group_table.node[1] = 9;
       }*/
    /*   if(getId() == 9){ //switch6
               group_table.node[0] = 8;
               //group_table.node[1] = 5;
             // group_table.node[1] = 6;
             // group_table.node[0] = 5;
               group_table.node[1] = 7;
           }*/
}



