#ifndef __CIRCLE_H__
#define __CIRCLE_H__

#include "shape.h"

class circle : public shape {
   public:
    void PrintName();
};

extern "C" {
shape* maker();
}

#endif