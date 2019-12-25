#pragma once
#ifndef _COMPONENT_
#define _COMPONENT_
#include <string.h>
#ifdef PC
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <fstream>
#include <tuple>
using namespace std;
#endif

enum ComponentType {
    output = 0,
    input,
    component,
    parameter,
};
class Component {
public:
    Component(){};
    Component(Component *parent, const char* name, const char* id, ComponentType component_type=component);
    virtual ~Component(){};
    virtual ComponentType type(){ return ComponentType::component; }

    Component *GetParent();
    const char* GetName();
    const char* GetID();
    const char* GetUniqueId();
    const char* GetUniqueName();
    #ifdef PC
    std::string str_id = "";
    std::string str_name = "";
    static auto get_all_unique_ids_as_map();
    #endif

private:
    
    const char *_name;
    const char *_id;
    char _id_buffer[100];
    char _name_buffer[500];
    #ifdef PC
        inline static std::map<std::string, Component*> _unique_ids;
    #endif

    Component *_parent;
};

enum param_type {
   FLOAT,
   DOUBLE,
   INT,
   BOOL,
};



template <class T>
class Parameter : public Component {
public:
    Parameter(Component *parent, const char *name, const char *id, int value);
    Parameter(Component *parent, const char *name, const char *id, float value);
    Parameter(Component *parent, const char *name, const char *id, double value);
    Parameter(Component *parent, const char *name, const char *id, bool value);
    virtual ~Parameter(){}
    ComponentType type(){ return ComponentType::parameter; }
    void SetValue(T val);
    T GetValue();
private:
    T _value;
};


class ParameterWrite {
private:
   static ParameterWrite *instance;
   // Private constructor so that no objects can be created.
   ParameterWrite();

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
      map<int, tuple<float, float> > simlation_param_write;
      vector<string> param_ids;

   #endif
   static ParameterWrite *GetInstance();

   void AddParamToArray(int *param, param_type type);

   int get_number_of_param();
   #ifdef PC
   vector<string> get_param_ids();
   map<int, tuple<Parameter<float>*, float, float> > simulation_float_params;
   map<int, tuple<Parameter<double>*, float, double> > simulation_double_params;
   map<int, tuple<Parameter<int>*, float, int> > simulation_int_params;
   map<int, tuple<Parameter<bool>*, float, bool> > simulation_bool_params;
   int* get_float_param_ptr_by_id(string id_to_find);
   int* get_double_param_ptr_by_id(string id_to_find);
   int* get_int_param_ptr_by_id(string id_to_find);
   int* get_bool_param_ptr_by_id(string id_to_find);
   #endif
 
};


template <class T>
Parameter<T>::Parameter(Component *parent, const char *name, const char *id, int value) :
Component(parent, name, id, ComponentType::parameter)
{
    ParameterWrite *s = ParameterWrite::GetInstance();
    int* ptr_to_obj = (int*)this;
    s->AddParamToArray(ptr_to_obj, param_type::INT);
    _value = value; 
}
template <class T>
Parameter<T>::Parameter(Component *parent, const char *name, const char *id, float value) :
Component(parent, name, id, ComponentType::parameter)
{
    ParameterWrite *s = ParameterWrite::GetInstance();
    int* ptr_to_obj = (int*)this;
    s->AddParamToArray(ptr_to_obj, param_type::FLOAT);
    _value = value; 
}
template <class T>
Parameter<T>::Parameter(Component *parent, const char *name, const char *id, double value) :
Component(parent, name, id, ComponentType::parameter)
{
    ParameterWrite *s = ParameterWrite::GetInstance();
    int* ptr_to_obj = (int*)this;
    s->AddParamToArray(ptr_to_obj, param_type::DOUBLE);
    _value = value; 
}
template <class T>
Parameter<T>::Parameter(Component *parent, const char *name, const char *id, bool value) :
Component(parent, name, id, ComponentType::parameter)
{
    ParameterWrite *s = ParameterWrite::GetInstance();
    int* ptr_to_obj = (int*)this;
    s->AddParamToArray(ptr_to_obj, param_type::BOOL);
    _value = value; 
}
template <class T>
void Parameter<T>::SetValue(T value) {
    _value = value;
}
template <class T>
T Parameter<T>::GetValue() {
    return _value;
}


inline Component::Component(Component *parent, const char *name, const char *id, ComponentType component_type) : 
    _name(name)
    ,_id(id)
    ,_parent(parent)
    {
   
        
        Component *current = this;
        strcpy(_id_buffer, current->GetID()); //This is the first time it enters here
        strcpy(_name_buffer, current->GetName()); //This is the first time it enters here  
        current = (current->GetParent() != current) ? current->GetParent() : 0;
        
        while(current) {
            strcat(_id_buffer, "-");
            strcat(_name_buffer, "<-");
            strcat(_id_buffer, current->GetID());
            strcat(_name_buffer, current->GetName());
            current = (current->GetParent() != current) ? current->GetParent() : 0;
        }
        #ifdef PC
        //Checking for unique IDs in code
        if (_unique_ids.count(_id_buffer) > 0) {
            std::cout << "ID: " << _id_buffer << " is already existing, with name: " << _name_buffer << std::endl;
        }
        //No Ids with that name exists
        else {
            _unique_ids[_id_buffer] = this;
        }
        std::string component_type_str = "";
        if (component_type== output) {
            component_type_str = "output: ";
        }
        else if (component_type== input) {
            component_type_str = "input: ";
        }
        else if (component_type== component) {
            component_type_str = "component: ";
        }
        else if (component_type == parameter) {
            component_type_str = "parameter: ";
            #ifdef PC
            ParameterWrite* instance = ParameterWrite::GetInstance();
            instance->param_ids.push_back(this->GetUniqueId());
            #endif 
        }
        std::ofstream id_file;
        id_file.open("id_file.txt", std::ios_base::app);
        id_file << component_type_str;
        id_file << _id_buffer;
        id_file << ":--:";
        id_file << _name_buffer;
        id_file << '\n';
        id_file.close();

        #endif
    }

inline Component* Component::GetParent() 
{
    return _parent;
}

inline const char* Component::GetName() {
    return _name;
}

inline const char* Component::GetID() {
    return _id;
}

inline const char* Component::GetUniqueId() {
    return _id_buffer;
}

inline const char* Component::GetUniqueName()  {
    return _name_buffer;
}

inline auto Component::get_all_unique_ids_as_map()  {
    return _unique_ids;
}

inline ParameterWrite::ParameterWrite() {
   number_of_parameters = 0;
   float_index          = 0;
   int_index            = 0;
   double_index         = 0;
   bool_index           = 0;
}

inline ParameterWrite* ParameterWrite::GetInstance() {
   if (!instance){
      instance = new ParameterWrite;
   }
   return instance;
}

inline void ParameterWrite::AddParamToArray(int *param, param_type type) {
   if (type == param_type::FLOAT)         float_params[float_index++] = param;
   else if (type == param_type::DOUBLE)   double_params[double_index++] = param;
   else if (type == param_type::INT)      int_params[int_index++] = param;      
   else if (type == param_type::BOOL)     bool_params[bool_index++] = param;
   number_of_parameters++;
}

inline int ParameterWrite::get_number_of_param() {
   return number_of_parameters;
}

inline vector<string> ParameterWrite::get_param_ids() {
   return param_ids;
}


inline int* ParameterWrite::get_float_param_ptr_by_id(string id_to_find) {
   for (int i = 0; i < float_index; i++) {
        Component *param_combo = (Component*)float_params[i];
        if (param_combo->GetUniqueId() == id_to_find){
            std::cout << "Name: " << param_combo->GetUniqueId() << std::endl;
            return float_params[i];
        }
   }
   return 0;
}
inline int* ParameterWrite::get_double_param_ptr_by_id(string id_to_find) {
   for (int i = 0; i < double_index; i++) {
        Component *param_combo = (Component*)double_params[i];
        if (param_combo->GetUniqueId() == id_to_find){
            std::cout << "Name: " << param_combo->GetUniqueId() << std::endl;
            return double_params[i];
        }
   }
   return 0;
}
inline int* ParameterWrite::get_int_param_ptr_by_id(string id_to_find) {
   for (int i = 0; i < int_index; i++) {
        Component *param_combo = (Component*)int_params[i];
        if (param_combo->GetUniqueId() == id_to_find){
            std::cout << "Name: " << param_combo->GetUniqueId() << std::endl;
            return int_params[i];
        }
   }
   return 0;
}
inline int* ParameterWrite::get_bool_param_ptr_by_id(string id_to_find) {
    for (int i = 0; i < bool_index; i++) {
        Component *param_combo = (Component*)bool_params[i];
        if (param_combo->GetUniqueId() == id_to_find){
            std::cout << "Name: " << param_combo->GetUniqueId() << std::endl;
            return bool_params[i];
        }
   }
   return 0;
}
#endif