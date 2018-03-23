//
// Created by ruby on 22.03.18.
//

#include "vector.h"

class GameObject;

class Resources
{
private:
    Resources() {}
    Resources( const Resources&);
    Resources& operator=( Resources& );
public:

    vector<GameObject> Objects;
    

    static Resources& getInstance() {
        static Resources  instance;
        return instance;
    }
};


