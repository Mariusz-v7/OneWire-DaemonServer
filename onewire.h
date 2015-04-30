#include <string>
#include <fstream>

#define     ONEWIRE_BAD_CRC         -100000

class OneWire {
private:
    std::string *devs;
    int devices_amount;
public:
    OneWire();
    ~OneWire();
    void ScanBus();
    int GetDevsAmount();
    std::string *GetDevs();
    float Read(std::string dev_id);

};
