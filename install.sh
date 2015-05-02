#!/bin/bash

sudo cp build/libonewire.so /usr/local/lib
sudo ldconfig

sudo rm -r /usr/include/onewire
sudo mkdir /usr/include/onewire
sudo cp -r *.h /usr/include/onewire
