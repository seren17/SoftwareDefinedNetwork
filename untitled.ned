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

//
// TODO auto-generated type
//
module endsystem1
{
    parameters:
        @kaynak;
        @display("i=device/device;bgb=372,227");

    gates:
        inout gate[];
    submodules:
        kaynak: Kaynak {
            @display("p=74,97");
        }
        mac: Mac {
            @display("p=302,80");
        }
        mac1: Mac {
            @display("p=303,155");
        }
    connections:
        kaynak.gate++ <--> { @display("ls=#FF6317,3"); } <--> mac.gate++;
        kaynak.gate++ <--> { @display("ls=#FF6317,3"); } <--> mac1.gate++;
        mac.gate++ <--> { @display("ls=#FF6317,3"); } <--> gate++;
        mac1.gate++ <--> { @display("ls=#FF6317,3"); } <--> gate++;
}
module endSystem2
{
    parameters:
        @hedef;
        @display("i=device/device;bgb=618,264");
    gates:
        inout gate[];

    submodules:
        mac: Mac {
            @display("p=68,82");
        }
        mac1: Mac {
            @display("p=67,186");
        }
        integrityChecking: IntegrityChecking {
            @display("p=233,83");
        }
        integrityChecking1: IntegrityChecking {
            @display("p=232,186");
        }
        redundancyManagement: RedundancyManagement {
            @display("p=376,131");
        }
        hedef: Hedef {
            @display("p=524,132;i=block/tx");
        }
    connections:
        mac.gate++ <--> { @display("ls=#FF6317,3"); } <--> gate++;
        mac.gate++ <--> { @display("ls=#FF6317,3"); } <--> integrityChecking.gate++;
        integrityChecking.gate++ <--> { @display("ls=#FF6317,3"); } <--> redundancyManagement.gate++;
        mac1.gate++ <--> { @display("ls=#FF6317,3"); } <--> gate++;
        mac1.gate++ <--> { @display("ls=#FF6317,3"); } <--> integrityChecking1.gate++;
        integrityChecking1.gate++ <--> { @display("ls=#FF6317,3"); } <--> redundancyManagement.gate++;
        redundancyManagement.gate++ <--> { @display("ls=#FF6317,3"); } <--> hedef.gate++;
}
network Untitled
{
    @display("bgb=796.668,615.822;i=background/green,red");
    submodules:
        controllerr: Controllerr {
            @display("p=378.24,49.644;i=,#004080;t=CONTROLLER,,black;tt=sss");
        }
        switch: Switch {
            @display("p=186.756,303.77402;i=,#FF8040");
        }
        switch1: Switch {
            @display("p=228.126,475.164;i=,#FF8040");
        }
        switch2: Switch {
            @display("p=408.97202,304.956;i=,#FF8040");
        }
        switch3: Switch {
            @display("p=537.81,476.346;i=,#FF8040");
        }
        switch4: Switch {
            @display("p=606.366,303.77402;i=,#FF8040");
        }
        switch5: Switch {
            @display("p=52.008,229.308;i=,#FF8040");
        }
        switch6: Switch {
            @display("p=731.658,236.40001;i=,#FF8040");
        }
        endsystem1: endsystem1 {
            @display("p=59.100002,403.062;i=,#008080;is=l");
        }
        endSystem2: endSystem2 {
            @display("p=738.75,408.97202;i=,#008080;is=l");
        }
        switch7: Switch {
            @display("p=150.114,115.836;i=,#FF8040");
        }
        switch8: Switch {
            @display("p=379.422,573.27;i=,#FF8040");
        }
        switch9: Switch {
            @display("p=617.004,125.292;i=,#FF8040");
        }
    connections:
        switch.gate++ <--> { @display("ls=cyan,3"); } <--> controllerr.gate++;
        switch1.gate++ <--> { @display("ls=cyan,3"); } <--> controllerr.gate++;
        switch2.gate++ <--> { @display("ls=cyan,3"); } <--> controllerr.gate++;
        switch3.gate++ <--> { @display("ls=cyan,3"); } <--> controllerr.gate++;
        switch4.gate++ <--> { @display("ls=cyan,3"); } <--> controllerr.gate++;
        switch5.gate++ <--> { @display("ls=cyan,3"); } <--> controllerr.gate++;
        switch6.gate++ <--> { @display("ls=cyan,3"); } <--> controllerr.gate++;
        switch.gate++ <--> { @display("ls=navy,3"); } <--> switch2.gate++;
        switch2.gate++ <--> { @display("ls=navy,3"); } <--> switch4.gate++;
        switch.gate++ <--> { @display("ls=navy,3"); } <--> switch5.gate++;
        switch.gate++ <--> { @display("ls=navy,3"); } <--> switch1.gate++;
        switch1.gate++ <--> { @display("ls=navy,3"); } <--> switch5.gate++;
        endsystem1.gate++ <--> { @display("ls=#FF6317,3"); } <--> switch.gate++;
        endsystem1.gate++ <--> { @display("ls=#FF6317,3"); } <--> switch1.gate++;
        switch4.gate++ <--> { @display("ls=#FF6317,3"); } <--> endSystem2.gate++;
        switch3.gate++ <--> { @display("ls=#FF6317,3"); } <--> endSystem2.gate++;
        switch3.gate++ <--> { @display("ls=navy,3"); } <--> switch6.gate++;
        switch6.gate++ <--> { @display("ls=navy,3"); } <--> switch4.gate++;
        switch7.gate++ <--> { @display("ls=cyan,3"); } <--> controllerr.gate++;
        switch8.gate++ <--> { @display("ls=cyan,3"); } <--> controllerr.gate++;
        switch7.gate++ <--> { @display("ls=navy,3"); } <--> switch5.gate++;
        switch1.gate++ <--> { @display("ls=navy,3"); } <--> switch8.gate++;
        switch8.gate++ <--> { @display("ls=navy,3"); } <--> switch3.gate++;
        switch9.gate++ <--> { @display("ls=cyan,3"); } <--> controllerr.gate++;
        switch7.gate++ <--> { @display("ls=navy,3"); } <--> switch9.gate++;
        switch9.gate++ <--> { @display("ls=navy,3"); } <--> switch6.gate++;
        switch7.gate++ <--> { @display("ls=navy,3"); } <--> switch8.gate++;
        switch9.gate++ <--> { @display("ls=navy,3"); } <--> switch8.gate++;
        switch7.gate++ <--> { @display("ls=navy,3"); } <--> switch2.gate++;
        switch9.gate++ <--> { @display("ls=navy,3"); } <--> switch2.gate++;
}

simple Mac
{
    @display("i=block/rxtx");

    gates:

        inout gate[];
}
simple IntegrityChecking
{
    @display("i=block/filter");
    gates:
        inout gate[];

}
simple RedundancyManagement
{
    @display("i=block/join;bgb=365,159");
    bool enabled = default(true);  // whether redundacy checking is enabled/disabled.
    double skewMax @unit(s) = default(20ms);
    gates:
        inout gate[];

}
simple TrafficSink
{
    parameters:
        @display("i=block/routing");
    gates:
        inout gate[];
}
