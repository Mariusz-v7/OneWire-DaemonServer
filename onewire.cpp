#include "onewire.h"

using namespace std;

OneWire::OneWire() {
    devs = NULL;
    devices_amount = 0;
}

void OneWire::ScanBus() {
    ofstream scan_file;
    scan_file.open ("/sys/bus/w1/devices/w1_bus_master1/w1_master_search");
    scan_file << "1";
    scan_file.close();
}

int OneWire::GetDevsAmount() {
    ifstream devs_amount_file;
    string line;

    devs_amount_file.open("/sys/bus/w1/devices/w1_bus_master1/w1_master_slave_count");
    if (devs_amount_file.is_open()) {
        if (getline(devs_amount_file, line)) devices_amount = stoi(line);
    }
    devs_amount_file.close();

    return devices_amount;
}

string *OneWire::GetDevs() {
    if (devices_amount == 0) return NULL;

    if (devs != NULL) delete[] devs;
    devs = new string[devices_amount];

    ifstream devs_ids_file;
    string line;
    unsigned int i = 0;

    devs_ids_file.open("/sys/bus/w1/devices/w1_bus_master1/w1_master_slaves");
    if (devs_ids_file.is_open()) {
        while (getline(devs_ids_file, line)) {
            devs[i++] = line;
        }
    }
    devs_ids_file.close();

    return devs;
}


float OneWire::Read(string dev_id) {
    int val;
    ifstream file;
    string line;
    
    file.open("/sys/bus/w1/devices/"+dev_id+"/w1_slave");
    if (file.is_open()) {
        //check for CRC
        getline(file, line);
        size_t found = line.find("YES");
        if (found == string::npos) return ONEWIRE_BAD_CRC;
        //read the temperature
        if (getline(file, line)) {
            size_t pos = line.find("t="); //find position of the temperature value in the output line
            line = line.erase(0, pos + 2); //cut the string to get clear temperature value
            val = stoi(line); // convert from string to int
        }
    }
    file.close();

    return val/1000.0;
}

OneWire::~OneWire() {
    if (devs != NULL) delete[] devs;
}
