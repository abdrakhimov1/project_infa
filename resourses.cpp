//
// Created by ruby on 22.03.18.
//

#include <vector>
#include "GameObject.cpp"
#include <SFML/Graphics.h>


class Resources
{
private:
    Resources() {}
    Resources( const Resources&);

public:

    std::vector<GameObject> Objects;
    sf::RenderWindow window = new sf::RenderWindow;


    void addObject(GameObject){
        this -> Objects.push_back(GameObject);
    }

    static Resources& getInstance() {
        static Resources  instance;
        return instance;
    }
};
