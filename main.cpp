#include <iostream>
#include <tins/tins.h>
#include <unistd.h>
#include <vector>
#include <cstdlib>
using namespace Tins;
using namespace std;


int main() {
    //Sniffer("ens32").sniff_loop(callback);
    RadioTap radiotap;


    vector<string> nameList;

    nameList.push_back("Hong Seung Bin Do Homework1!!!");
    nameList.push_back("Hong Seung Bin Do Homework!1!!");
    nameList.push_back("Hong Seung Bin Do Homework!!1!");
    nameList.push_back("Hong Seung Bin Do Homework!!!1");
    nameList.push_back("Hong Seung Bin Do Homework11!!");
    nameList.push_back("Hong Seung Bin Do Homework1!1!");
    nameList.push_back("Hong Seung Bin Do Homework1!!1");
    nameList.push_back("Hong Seung Bin Do Homework!11!");
    nameList.push_back("Hong Seung Bin Do Homework!1!1");
    nameList.push_back("Hong Seung Bin Do Homework!!11");
    nameList.push_back("Hong Seung Bin Do Homework111!");
    nameList.push_back("Hong Seung Bin Do Homework11!1");
    nameList.push_back("Hong Seung Bin Do Homework1!11");
    nameList.push_back("Hong Seung Bin Do Homework!111");
    nameList.push_back("Hong Seung Bin Do Homework1111");




    PacketSender sender;
    NetworkInterface iface("wlan3");
    //EthernetII pkt = EthernetII() / IP() / TCP() / RawPDU("foo");
    RadioTap radio;
    char mac[30];
    //radio.inner_pdu(beacon);
    while(1){
        for(auto i:nameList){
            Dot11Beacon beacon;

            beacon.ssid(i);
            beacon.addr1(Dot11::BROADCAST);
            sprintf(mac,"00:01:02:03:04:%.2d",rand()%50);
            beacon.addr2(mac);
            beacon.addr3(beacon.addr2());

            beacon.ds_parameter_set(8);
            beacon.supported_rates({ 1.0f, 5.5f, 11.0f });

            beacon.rsn_information(RSNInformation::wpa2_psk());
            radio.inner_pdu(beacon);
            try {
                sender.send(radio,iface);
            } catch (exception a) {
                cout << "error" << endl;
            }
            usleep(1000);
        }


    }

    return 0;

}
