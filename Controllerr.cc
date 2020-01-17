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


#include "Controllerr.h"
#include "optimumyol.h"
#include <vector>

using namespace std;

Define_Module(Controllerr);

void Controllerr::initialize()
{
    k = par("limit");
    sd = par("limit1");
    sd1 =par("limit1");
    optindex = par("limit");
    st = par("limit1");

    faildetect = par("booll");
     //arr[9][5];
    for(int i=0; i<11;i++){
        for(int j = 0;j<6;j++){
            swt_arr.arr[i][j]=NULL;
            //arr[i][j]=NULL;
        }
    }
    for(int i = 0; i<7;i++){
        kdizi[i]=NULL;
        hdizi[i]=NULL;

    }
    for(int i =0; i<3; i++){
        for(int j=0; j<9; j++){
            optimum_yoll[i].opty_arr[j]=NULL;
            optimum_yoll[i].opty_arr2[j]=NULL;
            yedek_yol.yedek_arr[j]=NULL;
        }
    }
   /* yedek_yol_func();
    for(int j=0; j<8; j++){

               EV<<"yedekyol = "<<yedek_yol.yedek_arr[j];
           }*/


       cTopology knesne;
       knesne.extractByProperty("kaynak");
       cTopology hnesne;
       hnesne.extractByProperty("hedef");

               cTopology::Node *knode = knesne.getNode(0);
               cTopology::Node *hnode = hnesne.getNode(0);
              //EV<< node->getModule()->gate("gate$o", 0)->getNextGate()->getOwnerModule();
              //EV<< node->getModule()->gate("gate$o", 1)->getNextGate()->getOwnerModule();

              kdizi[0]= knode->getModuleId();
              hdizi[0]= hnode->getModuleId();
              for(int i=1; i<3; i++){

                  kdizi[i]=knode->getModule()->gate("gate$o", i-1)->getNextGate()->getOwnerModule()->getId();
                  hdizi[i]=hnode->getModule()->gate("gate$o", i-1)->getNextGate()->getOwnerModule()->getId();
                 // hindex = hnode->getModule()->gate("gate$o", i-1)->getNextGate()->getIndex();
                 // EV<<"\n**hindex = "<<hindex<<"\n";
                 //EV<<" module id==="<<hdizi[i];

          }

             /* for(int c=0;c<8;c++)
                                  {
                      for(int b=0;b<5;b++)
                      {
                          EV<<swt_arr.arr[c][b];
                      }
                      EV<<"\n";
                  }*/

            /*         k++;
              EV<<"\n";       //host dest matrisi
              for(int i=0; i<5; i++)
              {
                  EV<<kdizi[i];
              }
              EV<<"\n";
              for(int i=0; i<5; i++)
              {
                 EV<<hdizi[i];
              }*/
              /*********************************/

            optimum_yol_func();

}
void Controllerr::handleMessage(cMessage *msg)
{
   if(strcmp("msg_contrllr", msg->getName())==0){
       if(st == 11){
           st = 1;
       }
        Controller_msg *Msg1 = check_and_cast<Controller_msg *>(msg);
        for(int j =0;j<6; j++){
        swt_arr.arr[st][j]=Msg1->getKontrol_dizi(j);
           //arr[st][j]=Msg1->getKontrol_dizi(j);
    }
        st++;
        for(int c=0;c<11;c++)
                    {
        for(int b=0;b<6;b++)
        {
            EV<<swt_arr.arr[c][b];
        }
        EV<<"\n";
    }

        delete msg;
  }
    else if(strcmp("msg_hata", msg->getName())==0){
        EV<<"controller hata kosulu";
        faildetect = true;

                Sorgu*msg_sorgu2 = new Sorgu ("msg_sorgu2");
                Sorgu*msg_sorgu3 = new Sorgu ("msg_sorgu3");
                msg_sorgu2->setFaildetect(true);

             /*   for(int i =2 ; i<6;i++)
                             {
                                 for(int j=0; j<9; j++){
                                   if(swt_arr.arr[j][0]== optimum_yoll[0].opty_arr[i]){
                                       for(int m=1; m<5;m++)
                                       {

                                      if(swt_arr.arr[j][m] == optimum_yoll[i].opty_arr[i-1]){
                                     msg_sorgu2->setGateindex(m);
                                     msg_sorgu2->setKaynakid(kid);
                                     msg_sorgu2->setHedefid(hid);
                                     for (int k = 0; k <  gate("gate$o", 1)->getVectorSize(); k++){
                                     if(gate("gate$o", k)->getNextGate()->getOwnerModule()->getId()==(optimum_yoll[0].opty_arr[i])){
                                         Sorgu *copy = msg_sorgu3->dup();
                                         sendDelayed(copy,delay,gate("gate$o", k));
                                         //send(copy,"gate$o",k);

                                           }
                                   }
                                       }
                                   }

                               }


                             }

                             }*/

        Hata_msg *Msg4 = check_and_cast<Hata_msg *>(msg);
             kid= Msg4->getKynkid();
             hid= Msg4->getHdfid();

             yedek_yol_func();

             for(int i =2 ; i<9;i++)
             {
                 for(int j=0; j<11; j++){
                   if(swt_arr.arr[j][0]== yedek_yol.yedek_arr[i]){
                       for(int m=1; m<6;m++)
                       {

                      if(swt_arr.arr[j][m] == yedek_yol.yedek_arr[i-1]){
                     msg_sorgu2->setGateindex(m);
                     msg_sorgu2->setKaynakid(kid);
                     msg_sorgu2->setHedefid(hid);
                     for (int k = 0; k <  gate("gate$o", 1)->getVectorSize(); k++){
                     if(gate("gate$o", k)->getNextGate()->getOwnerModule()->getId()==(yedek_yol.yedek_arr[i])){
                         Sorgu *copy = msg_sorgu2->dup();
                         sendDelayed(copy,delay2,gate("gate$o", k));
                         //send(copy,"gate$o",k);

                           }
                   }
                       }
                   }

               }


             }

             }



              delete msg;

    }

   else if(strcmp("msg_sorgu", msg->getName())==0){

       Sorgu *Msg2 = check_and_cast<Sorgu *>(msg);
               kid= Msg2->getKaynakid();
               hid= Msg2->getHedefid();


       for(int i = 0; i<2; i++){
           if(optimum_yoll[i].opty_arr[0] == kid && optimum_yoll[i].opty_arr[1] == hid){
               for(int j = 2; j<9; j++){
                   if(msg->getSenderModuleId() == optimum_yoll[i].opty_arr[j]){
                       if(msg->getSenderModuleId() == optimum_yoll[i].opty_arr[2]){
                           opt_id = optimum_yoll[i].opty_arr[1];
                           EV<<"\nswitchhh == "<<msg->getSenderModuleId()<<" opt id =="<<opt_id;

                       }
                       else{
                           opt_id = optimum_yoll[i].opty_arr[j-1];
                           EV<<"\nswitchhh == "<<msg->getSenderModuleId()<<" opt id =="<<opt_id;
                       }
                   }
               }
           }
       }

               for(int j=0; j<11; j++){
                   if(swt_arr.arr[j][0]== msg->getSenderModuleId()){
                       for(int m=1; m<6;m++)
                       {
                           if(swt_arr.arr[j][m] == opt_id){
                           Msg2->setGateindex(m);
                           }
                       }
                   }

               }

           //send(msg,"gate$o",msg->getArrivalGate()->getIndex());
           sendDelayed(msg,delay,gate("gate$o", msg->getArrivalGate()->getIndex()));

}
    else if(strcmp("msg_source",msg->getName())==0)
    {
        //send(msg,"gate$o",msg->getArrivalGate()->getIndex());
        sendDelayed(msg,delay,gate("gate$o", msg->getArrivalGate()->getIndex()));


    }

}
void Controllerr::optimum_yol_func(){
     cTopology swt_;
     swt_.extractByProperty("swt");
     nodenumber = swt_.getNumNodes();
     EV<<"node sayisi ="<<nodenumber;


    for(int i = 1; i < 3; i++)
    {
        optimum_yoll[optindex].opty_arr[0]=kdizi[0];
        optimum_yoll[optindex].opty_arr[1]=hdizi[0];

        start_m = kdizi[i];
        finish_m = hdizi[i];

        for(int k=0; k< nodenumber; k++)
               {
                    cTopology ::Node * swt_node = swt_.getNode(k);
                    if( swt_.getNode(k)->getModuleId()==start_m)
                    {
                        start_node = k;
                        EV<<"** startnode="<<start_node;
                    }
                    if(swt_.getNode(k)->getModuleId()==finish_m)
                    {
                        finish_node = k;
                        EV<<"** finishnode="<<finish_node;
                    }

               }
        int kl;
            optimum_yol obj;
            obj.dijkstra(obj.G,nodenumber, start_node);

            for(int i=1; i<10; i++)
            {
                for(int j=0; j<obj.path[i].s_path.size();j++){
                kl = obj.path[i].s_path[j];
                        break;
            }
              if(kl==finish_node)
                    {
                  for(int j=0; j<obj.path[i].s_path.size(); j++)
                  {
                      cTopology ::Node * swt_node1 = swt_.getNode(obj.path[i].s_path[j]);
                      swt_node1->getModuleId();
                      //EV<<"\n"<<obj.path[i].s_path[j]<<"== modul id==="<<swt_node1->getModuleId();
                    opt1.push_back(swt_node1->getModuleId());
                         }
                    }
            }
            for(int i = 0; i<opt1.size();i++){
                      optimum_yoll[optindex].opty_arr[i+2] = opt1[i];
            }

            for(int i = 0; i<8;i++){
                    EV<<" "<< optimum_yoll[optindex].opty_arr[i]<<"-->";
                }
            EV<<"\n";

            optindex++;
               opt1.clear();
    }
}
void Controllerr::yedek_yol_func()
{
          yedek_yol.yedek_arr[0] = kdizi[0];
          yedek_yol.yedek_arr[1] = hdizi[0];
          //finish_node_ydk=hdizi[1];
          finish_node_ydk=hdizi[1];
          cTopology ctopo;
          ctopo.extractByProperty("swt");
          for(int fn=0; fn<(ctopo.getNumNodes()-1); fn++)
          {
              cTopology::Node * ydknode = ctopo.getNode(fn);
              //EV<<"FGFGG==="<<ydknode->getModule();
              if(ydknode->getModuleId()==finish_node_ydk)
              {
                  finish_node_no=fn;
              }
          }

     int kl1;
     optimum_yol obj2;
     obj2.dijkstra(obj2.H, obj2.m, obj2.u);
     for(int i=1; i<11; i++)
         {
             for(int j=0; j<obj2.path[i].s_path.size();j++){
             kl1 = obj2.path[i].s_path[j];
                     break;
         }
           if(kl1==finish_node_no)
                 {
               for(int j=0; j<obj2.path[i].s_path.size(); j++)
               {
                   cTopology ::Node * swt_node2 = ctopo.getNode(obj2.path[i].s_path[j]);
                   swt_node2->getModuleId();
                 //  EV<<"\n"<<obj2.path[i].s_path[j]<<"== modul id==="<<swt_node2->getModuleId();
                 opt1.push_back(swt_node2->getModuleId());
                      }
                 }
         }

     for(int k=0; k<opt1.size();k++){
         yedek_yol.yedek_arr[k+2]=opt1[k];
        // EV<<"* * * "<<opt1[k];
        EV<<"-"<<yedek_yol.yedek_arr[k+2];
     }
   opt1.clear();

}

/*if(msg->getSenderModuleId() == kdizi[sd]){
    EV<<"if e girdi";

   optimum_yoll[optindex].opty_arr[0]=kid;
    optimum_yoll[optindex].opty_arr[1]=hid;


    start_m = kdizi[sd];
    finish_m = hdizi[sd];

    sd++;



    cTopology swt_;
    swt_.extractByProperty("swt");
    nodenumber = swt_.getNumNodes();
    EV<<"node sayisi ="<<nodenumber;
    for(int k=0; k< nodenumber; k++)
       {
            cTopology ::Node * swt_node = swt_.getNode(k);
            if( swt_.getNode(k)->getModuleId()==start_m)
            {
                start_node = k;
                EV<<"\nswitch = "<<msg->getSenderModuleId()<<"** startnode="<<start_node;
            }
            if(swt_.getNode(k)->getModuleId()==finish_m)
            {
                finish_node = k;
                EV<<"\nswitch = "<<msg->getSenderModuleId()<<"** finishnode="<<finish_node;
            }

       }

    int kl;
    optimum_yol obj;
   obj.dijkstra(obj.G,nodenumber, start_node);

    for(int i=1; i<8; i++)
    {
        for(int j=0; j<obj.path[i].s_path.size();j++){
        kl = obj.path[i].s_path[j];
                break;
    }
      if(kl==finish_node)
            {
          for(int j=0; j<obj.path[i].s_path.size(); j++)
          {
              cTopology ::Node * swt_node1 = swt_.getNode(obj.path[i].s_path[j]);
              swt_node1->getModuleId();
              //EV<<"\n"<<obj.path[i].s_path[j]<<"== modul id==="<<swt_node1->getModuleId();
            opt1.push_back(swt_node1->getModuleId());
                 }
            }
    }

    if(msg->getSenderModuleId()==kdizi[optindex+1])
    {         for(int i = 0; i<opt1.size();i++){
                    optimum_yoll[optindex].opty_arr[i+2] = opt1[i];

    }
    for(int i = 0; i<6;i++){
        EV<<"\ndizi = "<< optimum_yoll[optindex].opty_arr[i];
    }
    optindex++;
    for(int i=0; i<opt1.size();i++){

                    if(opt1[i]==msg->getSenderModuleId())
                    {
                            opt_id = opt1[i-1];
                            EV<<"\nopt id =="<<opt_id;

                    }
    }
    else
{

    for(int s=0; s<2;s++){

            if(optimum_yoll[s].opty_arr[0] == Msg2->getKaynakid() && optimum_yoll[s].opty_arr[1] == Msg2->getHedefid()){
                for(int r=2; r<6 ; r++){
                    if(optimum_yoll[s].opty_arr[r] == msg->getSenderModuleId()){

                    if(msg->getSenderModuleId() == optimum_yoll[s].opty_arr[2]){

                       opt_id = hdizi[0];
                       EV<<"\nswitchhh == "<<msg->getSenderModuleId()<<" opt id =="<<opt_id;
                    }
                    else{
                    opt_id = optimum_yoll[s].opty_arr[r-1];
                    EV<<"\n opt id =="<<opt_id;
                }
            }
                }

        }

    }

}
    */


