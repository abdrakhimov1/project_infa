sf::Vector2f getVectorFromPair(std::pair<float, float> coords) {
    float crx = std::get<0>(coords);
    float cry = std::get<1>(coords);
    sf::Vector2f vector(crx, cry);
    return vector;
}


std::vector<std::pair<float, float>> Coordinates(GameObject object) {
    std::vector<std::pair<float, float>> crs = {};
    std::vector<Dot> dots = object.dots_list;
    for (int i = 0;i < dots.size();i++) {
        float crx = std::get<0>(dots[i].crs);
        float cry = std::get<1>(dots[i].crs);
        std::pair<float, float> x_and_y = std::make_pair(crx, cry);
        crs.push_back(x_and_y);
    }
    return crs;
}


sf::Sprite createSprite(GameObject object) {
    sf::Sprite sprite;
    sf::ConvexShape convex;
    std::vector<Dot> dots = object.dots_list;
    int quantity = object.dots_list.size();
    std::vector<std::pair<float, float>> crs = Coordinates(object);
    convex.setPointCount(quantity);
    for (int i = 0; i < quantity; i++) {
        sf::Vector2f coords = getVectorFromPair(crs[i]);
        convex.setPoint(i, coords);
        i++; }
    sprite.setPosition(/*GameObject.x, GameObject.y*/0,0); //FIXME
    sprite.setColor(sf::Color(7, 55, 221));
    return sprite;
}


void draw(sf::Sprite sprite, GameObject object) {
    sf::RenderWindow& window = Resources::getInstance().getWindow();
    sprite = createSprite(object);
    while (window.isOpen()) {
        window.clear();
        window.draw(sprite);
        window.display();
    }
}