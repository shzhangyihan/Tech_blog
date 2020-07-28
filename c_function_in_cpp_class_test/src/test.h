#ifndef __TEST_H__
#define __TEST_H__

class test {
   public:
    void inc();
    test(int id);

   private:
    int id;
    typedef int (*func_ptr_t)(void);
    func_ptr_t count_fn;
};

#endif