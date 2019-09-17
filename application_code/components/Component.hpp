#pragma once
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
    #ifdef PC
    std::string str_id = "";
    std::string str_name = "";
    #endif
private:
    
    const char *_name;
    const char *_id;
    Component *_parent;
};

inline Component::Component(Component *parent, const char *name, const char *id, ComponentType component_type) : 
    _name(name)
    ,_parent(parent)
    {
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
        _id = id;
        str_id = "";
        Component *current = this;
        while(current) {
            str_id += current->GetID();
            str_name += current->GetName();
            current = (current->GetParent() != current) ? current->GetParent() : 0;
            if (current) {
                str_id += "-";
                str_name += "<-";
            }
        }
        std::ofstream id_file;
        id_file.open("id_file.txt", std::ios_base::app);
        id_file << component_type_str;
        id_file << str_id;
        id_file << ":--:";
        id_file << str_name;
        id_file << '\n';
        id_file.close();
        #else
        _id = id;
        #endif
    }