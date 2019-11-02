#pragma once
#include <string.h>
#ifdef PC
#include <iostream>
#include <string>
#include <algorithm>
#include <stdio.h>
#include <fstream>
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
    #endif
private:
    
    const char *_name;
    const char *_id;
    char _id_buffer[100];
    char _name_buffer[500];
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
            strcat(_id_buffer, ">");
            strcat(_name_buffer, "<-");
            strcat(_id_buffer, current->GetID());
            strcat(_name_buffer, current->GetName());
            current = (current->GetParent() != current) ? current->GetParent() : 0;
        }
        #ifdef PC
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