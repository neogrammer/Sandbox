#pragma once
// PlayState.h
#pragma once
#include <SFML/Graphics.hpp>
#include "BackgroundLayer.h"
#include <vector>
#include "GameSTate.h"

class SideScrollerPlayState : public GameState {
public:
    SideScrollerPlayState(sf::RenderWindow& tv_);
    ~SideScrollerPlayState();

    void load();
    void update(float dt);
    void draw(sf::RenderWindow& window);

private:
    std::vector<BackgroundLayer> _backgroundLayers;
};
