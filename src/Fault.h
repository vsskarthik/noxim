#ifndef _FAULT_H__
#define _FAULT_H__

#include <vector>
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

class Fault{
private:
  vector<int> faults;


public:

  Fault(){}
  void injectFault(int num_of_dirs);
  ~Fault(){
    faults={};
  }
  vector<int> getFaults(){
    return faults;
  }

void print();
};
#endif
