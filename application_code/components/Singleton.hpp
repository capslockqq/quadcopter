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
      number_of_outputs = 0;
   }

   public:
   int number_of_outputs;

   static SingletonLogging *GetInstance() {
      if (!instance){
        instance = new SingletonLogging;
      }
      return instance;
   }

   vector<string> GetData() {
      return this -> data;
   }

   void SetData(vector<string> arg_data) {
      this -> data = arg_data;
   }
   void count() {
      number_of_outputs++;
   }
};