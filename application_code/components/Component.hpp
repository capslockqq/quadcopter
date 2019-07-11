#pragma once

class Component {
public:
    Component(){};
    Component(Component *parent, const char *name, const char *id) : 
    _name(name)
    ,_id(id)
    ,_parent(parent)
    {

    }
    virtual ~Component(){};
    Component *GetParent() {
        return _parent;
    }
    const char* GetName() {
        return _name;
    }
    const char* GetID() {
        return _id;
    }
private:
    const char *_name;
    const char *_id;
    Component *_parent;
};
