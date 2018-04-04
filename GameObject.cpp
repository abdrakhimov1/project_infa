//
// Created by ruby on 22.03.18.
//

#include <vector>
#include <iostream>

class Dot{
public:
    Dot(float x, float y){
        crs = std::make_pair(x, y);
    }
    std::pair < float, float > crs;
};

class abstractGameObject{
public:
    virtual ~abstractGameObject(){}
    virtual void init() = 0;
};

class SimpleGameObject : public abstractGameObject{
public:
    ~SimpleGameObject(){

    }
    void init(){

    }
};


class GameObject : public abstractGameObject{
public:
    GameObject(abstractGameObject *inner){
        m_wrappee = inner;
    }
    ~GameObject(){
        delete m_wrappee;
    }
    virtual void init(){
        m_wrappee -> init();
    }
    private:
    abstractGameObject *m_wrappee;
};

class GameObjectWithRigidBody : public GameObject{
public:
    GameObjectWithRigidBody(abstractGameObject *core) : GameObject(core){}
    ~GameObjectWithRigidBody(){}
    void init(){
        GameObject::init();
        }
    std::pair< float , float > speed;
};

class GameObjectWithCollider : public GameObject{
public:
    GameObjectWithCollider(abstractGameObject *core ) : GameObject(core){}
    ~GameObjectWithCollider(){}
    void init(){
        GameObject::init();
    }

    std::vector<Dot> dots_list;
    void Add_dot(Dot dot, std::vector<Dot> dots_list){
        dots_list.push_back(dot);
    }
    bool Detect(float dotX, float dotY, float X0, float Y0, float X1, float Y1){
        float d = (dotX - X0) * (Y1 - Y0) - (dotY - Y0) * (X1 - X0);
        return d > 0;
    }

};

class GameObjectWithDrawMeFunction : public GameObject{
public:
    GameObjectWithDrawMeFunction(abstractGameObject *core) : GameObject(core){}
    ~GameObjectWithDrawMeFunction(){}
    void init(){
        GameObject::init();
    }

    void DrawMe(){
        //FIXME
    }
};