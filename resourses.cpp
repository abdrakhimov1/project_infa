//
// Created by ruby on 22.03.18.
//

#include <vector>
//#include <SFML/Graphics.h>


class Resources
{
private:
    Resources() {}
    Resources( const Resources&);

public:

    std::vector<GameObject> Objects;
    sf::RenderWindow window = new sf::RenderWindow;
    float CurrentFrameTime;
    float LastFrameTime;

    void addObject(GameObject object){
        this -> Objects.push_back(object);
    }

    static Resources& getInstance() {
        static Resources  instance;
        return instance;
    }
};

