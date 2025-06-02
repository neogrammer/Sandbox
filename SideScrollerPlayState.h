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
    void update(sf::RenderWindow& window, float dt) override;
   
	void handleInput(float dt_) override;
	void handleEvent(const std::optional<sf::Event>& evt_) override;
	void handleCollisions() override;
	void animate() override;
	void render(sf::RenderWindow& tv_) override;

	void tickBegin() override;
	void tickEnd(float dt_) override;

private:
    std::vector<BackgroundLayer> _backgroundLayers;
};
