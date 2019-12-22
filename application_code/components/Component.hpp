#pragma once
#ifndef _COMPONENT_
#define _COMPONENT_
#include <string.h>
#ifdef PC
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <fstream>
#include <map>
#include "ParameterWrite.hpp"
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

    Component *GetParent() {
        return _parent;
    }
    const char* GetName() {
        return _name;
    }
    const char* GetID() {
        return _id;
    }
    const char* GetUniqueId() {
        return _id_buffer;
    }
    const char* GetUniqueName() {
        return _name_buffer;
    }
    #ifdef PC
    std::string str_id = "";
    std::string str_name = "";
    static auto get_all_unique_ids_as_map() {
        return _unique_ids;
    }
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
    #endif