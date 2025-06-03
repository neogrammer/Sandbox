// BackgroundLayer.h
#pragma once
#include <SFML/Graphics.hpp>
#include "Cfg.h"
class BackgroundLayer {
public:
    BackgroundLayer(Cfg::Textures tex_, float scrollSpeed);

    void update(float dt);
    void draw(sf::RenderWindow& window);

private:
    sf::Texture _texture;
    sf::Sprite _sprite;
    float _scrollSpeed;
    float _offset;
};