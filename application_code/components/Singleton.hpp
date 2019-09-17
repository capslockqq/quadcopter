#pragma once
#include <iostream>
#include <vector>
using namespace std;
class SingletonLogging {
private:
   static SingletonLogging *instance;
   vector<string> data;
 
   // Private constructor so that no objects can be created.
   SingletonLogging() {
   }

   public:
   static SingletonLogging *GetInstance() {
      if (!instance){
        instance = new SingletonLogging;
      }
      return instance;
   }

   vector<string> GetData() {
      return this -> data;
   }

   void SetData(vector<string> data) {
      this -> data = data;
   }
};