#include "DualOutputDevice.h"

DualOutputDevice::DualOutputDevice(GPIO g, GPIO p) {
  _g = g;
  _g.setMode(1);
  _p = p;
  _p.setMode(1);
}


bool DualOutputDevice::isReady() {
  return _g.isReady() && _p.isReady();
}