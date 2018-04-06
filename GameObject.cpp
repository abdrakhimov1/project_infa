//
// Created by ruby on 22.03.18.
//

#include "Dot.h"
#include "GameObject.h"

template <typename T>
void GameObject::addComponent(){
        T *prop = new T;
        componentsList.push_back(prop);
    }

template <typename T>
T& GameObject::getComponent(){
        for(int i =0; i < componentsList.size(); i++){
            if(strcmp(componentsList[i] -> typeID, typeid(T).name()) == 0) {
                T *subClass = dynamic_cast<T*>(componentsList[i]);
                return *subClass;
            }
        }
}


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