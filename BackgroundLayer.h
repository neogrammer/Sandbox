// BackgroundLayer.h
#pragma once
#include <SFML/Graphics.hpp>

class BackgroundLayer {
public:
    BackgroundLayer(const std::string& filename, float scrollSpeed);

    void update(float dt);
    void draw(sf::RenderWindow& window);

private:
    sf::Texture _texture;
    sf::Sprite _sprite;
    float _scrollSpeed;
    float _offset;
};