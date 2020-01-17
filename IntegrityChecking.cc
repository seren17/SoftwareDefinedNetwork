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

#include "IntegrityChecking.h"

Define_Module(IntegrityChecking);

void IntegrityChecking::initialize()
{
    // TODO - Generated method body
    expectedSeqNum = 0; // Bu, sýfýrlama iþleminden sonra ilk frame in alýnmasýna izin verir.
}

void IntegrityChecking::handleMessage(cMessage *msg)
{
    // TODO - Generated method body
    Source_msg *afdxMsg = check_and_cast<Source_msg *>(msg);

            int currSeqNum = afdxMsg->getSeqNum();


            if (expectedSeqNum == 0 || currSeqNum == 0 || currSeqNum == expectedSeqNum || currSeqNum == expectedSeqNum + 1)
            {
                send(msg,"gate$o",1);
            }

            else {
               // EV << "sira numarasi ile frame " << currSeqNum << "dropped(dustu). Beklenen: " << expectedSeqNum;
                delete msg;
            }

            // son sýra numarasýný sakla
            expectedSeqNum = currSeqNum + 1;
            if (expectedSeqNum > 255)
                expectedSeqNum = 1;
}
