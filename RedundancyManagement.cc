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

#include "RedundancyManagement.h"

Define_Module(RedundancyManagement);

void RedundancyManagement::initialize()
{
    // TODO - Generated method body
       // enabled = par("enabled");
        skewMax = par("skewMax");
        lastFrameReceived = simTime();
        nextSeqExpected = 0;
}

void RedundancyManagement::handleMessage(cMessage *msg)
{
    // TODO - Generated method body
    // gereksiz mesajlar� filtreleme

        Source_msg *afdxMsg = check_and_cast<Source_msg *>(msg);
        int currSeqNum = afdxMsg->getSeqNum();


           // seqNum bekledi�imizden daha k���kse �er�eveyi b�rak�n
            //ve son kare yak�n zamanda al�nm��t�r (skewMax zaman�ndan daha �nce)

            if (currSeqNum < nextSeqExpected && simTime() - lastFrameReceived <= skewMax) {

                EV<<"\nredundancy management **** "<<simTime();

                   delete msg;
                   EV << "KOPYA SILINDI \n";

                   return;     // frame dropped. do not update the next expected counter
            }
            else{
                 send(msg,"gate$o",2);

               EV << "MESAJ BIR UST KATMANA GONDERILDI \n";
            }
               lastFrameReceived = simTime();

               //son s�ra numaras�n� saklay�n.
               nextSeqExpected = currSeqNum + 1;
                   if (nextSeqExpected > 255)
                       nextSeqExpected = 1;
}
