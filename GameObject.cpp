//
// Created by ruby on 22.03.18.
//

#include <vector>
#include <iostream>
#include <cstring>
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
    T& getComponent(){
        for(int i =0; i < componentsList.size(); i++){
            if(strcmp(componentsList[i] -> typeID, typeid(T).name()) == 0) {
                T *subClass = dynamic_cast<T*>(componentsList[i]);
                return *subClass;
            }
        }
    }
};

/*


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