#include <iostream>
#include "onewire.h"

using namespace std;

int main () {

    OneWire onewire = OneWire();

    int devs_amount = onewire.GetDevsAmount();
    string *d = onewire.GetDevs();

    for(int i = 0; i < devs_amount; ++i) cout << onewire.Read(d[i]) << endl;


    //cout << onewire.Read() << endl;

    return 0;
}
