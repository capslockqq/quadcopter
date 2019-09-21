#pragma once
#ifdef PC
#include <iostream>
#include <list>
#include <tuple>

using namespace std;
class OutputObserver {
private:
   static OutputObserver *instance;
   std::list<std::tuple<int*, std::string>> component;
//    list<int*> component;
 
   // Private constructor so that no objects can be created.
   OutputObserver();

public:
   static OutputObserver *GetInstance();

   std::list<std::tuple<int*, std::string>> GetUpdate();

   void Add_Output(int* compo, std::string type);
};

inline std::list<std::tuple<int*, std::string>> OutputObserver::GetUpdate()
{
    return component;
}

inline OutputObserver::OutputObserver() {
   
}

inline OutputObserver * OutputObserver::GetInstance()
{
    if (!instance){
        instance = new OutputObserver;
    }
    return instance;
}

inline void OutputObserver::Add_Output(int *compo, std::string type){
    component.push_back(std::tuple<int*, std::string>(compo, type));
}
#endif





