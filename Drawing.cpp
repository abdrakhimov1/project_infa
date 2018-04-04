#define resources Resources::getInstance()

class Window {
private:
    sf::RenderWindow window;
    // vector <str> images = {"something"};
public:
    Window(int length, int width,const std::string name = "GAME") {
        //Objects = Resources.Objects;
        sf::VideoMode mode = sf::VideoMode(length, width);
        window = resources.window;
    }

    sf::Sprite createSprite(GameObject object) {
        sf::Sprite sprite;
        sf::ConvexShape convex;
        std::vector<Dot> dots = GameObject.dots_list;
        int qnt = GameObject.dots_list.size();
        std::vector<std::pair> crs = Coordinates(object);
        convex.setPointCount(qnt); int i = 0;
        do {
        convex.setPoint(i, crs[i]);
        i++; }
        while (i < qnt-1);
        sprite.setPosition(/*GameObject.x, GameObject.y*/0,0); //FIXME
        sprite.setColor(sf::Color(7, 55, 221));
        return sprite;
    }
};


std::vector<std::pair> Coordinates(GameObject object) {
    std::vector<std::pair<float, float>> crs = {};
    std::vector<Dot> dots = GameObject.dots_list;
    for (int i = 0;i < dots.size();i++) {
          float crx = std::get<0>(dots[i].crs); float crx1 = std::get<0>(dots[i+1].crs); crx = crx1-crx;
          float cry = std::get<1>(dots[i].crs); float cry1 = std::get<1>(dots[i+1].crs); cry = cry1-cry;
          std::pair<float, float> x$y = std::make_pair(crx, cry);
          crs.push_back(x$y);
    }
    return crs;
}

void draw(sf::Sprite sprite, GameObject object) {
    Window window = Window(1280, 920);
    sprite = Window.createSprite(object);
    while (window.isOpen()) {
        window.clear();
        window.draw(sprite);
        window.display();
    }
}