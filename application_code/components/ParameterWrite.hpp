#pragma once
#include "Parameter.hpp"
class ParameterWrite {
private:
   static ParameterWrite *instance;
   // Private constructor so that no objects can be created.
   ParameterWrite() {
      number_of_parameters = 0;
   }

   public:
   int number_of_parameters;

   static ParameterWrite *GetInstance() {
      if (!instance){
        instance = new ParameterWrite;
      }
      return instance;
   }
   void count() {
      number_of_parameters++;
   }
   int get_number_of_param() {
      return number_of_parameters;
   }
};