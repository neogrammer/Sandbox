// BackgroundLayer.h
#pragma once
#include <SFML/Graphics.hpp>
#include "Cfg.h"
class BackgroundLayer {
public:
    BackgroundLayer(Cfg::Textures tex_, float scrollSpeed);

    void update(float dt);
    void draw(sf::RenderWindow& window);
    void setScrollSpeed(float spdX_, float spdY_= 0.f);
    sf::Vector2f getPosition();
    void setPosition(sf::Vector2f pos_);
    sf::Vector2u getTextureSize();
    float getScrollSpeed();
  
private:
    sf::Texture _texture;
    sf::Sprite _sprite;
    float _scrollSpeed;
    float _offset;

    
};