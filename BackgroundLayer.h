// BackgroundLayer.h
#pragma once
#include <SFML/Graphics.hpp>
#include "Cfg.h"
class BackgroundLayer 
{

    sf::Sprite mainSpr;
    sf::Sprite secondarySpr;

    sf::View layerView;

    float scrollModifier{ 1.f };

    bool movingRight{ false };
    bool movingLeft{ false };
    
    void checkBoundary();


public:
    BackgroundLayer(sf::RenderWindow& window_, Cfg::Textures tex_, float scrollModifier_);

    void update(float dt_);
    void draw(sf::RenderWindow& window_);
  
    void move(sf::Vector2f disp_, float dt_);

    
};