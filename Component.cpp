//
// Created by ruby on 23.03.18.
//

class abstractComponent{
public:
    virtual void init() = 0;
    virtual ~abstractComponent(){}



};

class Component : abstractComponent{
public:
    virtual void init(){}

};