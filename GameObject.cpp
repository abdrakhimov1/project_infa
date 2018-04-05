//
// Created by ruby on 22.03.18.
//

#include <vector>
#include <iostream>
#include "Components.cpp"


class Dot{
public:
    Dot(float x, float y){
        crs = std::make_pair(x, y);
    }
    std::pair < float, float > crs;
};

class GameObject{
public:
    std::vector<AbstractComponent*> componentsList;

    template <typename T>
    void addComponent(){
        T *prop = new T;
        componentsList.push_back(prop);
    }

    template <typename T>
    T getComponent(){
        for(int i =0; i < componentsList.size(); i++){
            if (typeid(componentsList[i]).name() == typeid(T).name()){
                T *subClass = dynamic_cast<T* >(componentsList[i]);
                return *subClass;
            }
        }
    }
};








/*
class GameObjectWithCollider : public GameObject{
public:
    GameObjectWithCollider(abstractGameObject *core ) : GameObject(core){}
    ~GameObjectWithCollider(){}
    void init(){
        GameObject::init();
        std::vector<Dot> dots_list;
        std::cout << "Collider" << std::endl;

        void Add_dot(Dot dot, std::vector<Dot> dots_list){
            dots_list.push_back(dot);
        }
        bool Detect(float dotX, float dotY, float X0, float Y0, float X1, float Y1){
            float d = (dotX - X0) * (Y1 - Y0) - (dotY - Y0) * (X1 - X0);
            return d > 0;
        }
    }



};

class GameObjectWithDrawMeFunction : public GameObject{
public:
    GameObjectWithDrawMeFunction(abstractGameObject *core) : GameObject(core){}
    ~GameObjectWithDrawMeFunction(){}
    void DrawMe(){
        //FIXME
    }
    void init(){
        GameObject::init();
        std::cout << "DrawMe" << std::endl;
        int b;
    }
};

*/