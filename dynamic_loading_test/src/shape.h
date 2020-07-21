#ifndef __SHAPE_H__
#define __SHAPE_H__

class shape {
   public:
    virtual void PrintName();
};

class square : public shape {
   public:
    void PrintName();
};

#endif