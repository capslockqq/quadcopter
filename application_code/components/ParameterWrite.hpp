#pragma once
#ifdef PC
#include <iostream>
#include <string>
#include <map>
using namespace std;
#endif
enum param_type {
   FLOAT,
   DOUBLE,
   INT,
   BOOL,
};

class ParameterWrite {
private:
   static ParameterWrite *instance;
   // Private constructor so that no objects can be created.
   ParameterWrite() {
      number_of_parameters = 0;
      float_index          = 0;
      int_index            = 0;
      double_index         = 0;
      bool_index           = 0;
   }

   public:
   int number_of_parameters;
   int* float_params[50];
   int float_index;
   int* int_params[50];
   int int_index;
   int* double_params[50];
   int double_index;
   int* bool_params[50];
   int bool_index;
   #ifdef PC
      map<string, tuple<float, float> > simlation_param_write;
      vector<string> param_ids;

   #endif
   static ParameterWrite *GetInstance() {
      if (!instance){
        instance = new ParameterWrite;
      }
      return instance;
   }

   void AddParamToArray(int *param, param_type type) {
      if (type == param_type::FLOAT)         float_params[float_index++] = param;
      else if (type == param_type::DOUBLE)   double_params[double_index++] = param;
      else if (type == param_type::INT)      int_params[int_index++] = param;      
      else if (type == param_type::BOOL)     bool_params[bool_index++] = param;
      count();
   }

   void count() {
      number_of_parameters++;
   }
   int get_number_of_param() {
      return number_of_parameters;
   }

   vector<string> get_param_ids() {
      return param_ids;
   }
 
};