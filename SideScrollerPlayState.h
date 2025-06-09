#pragma once
// PlayState.h
#pragma once
#include <SFML/Graphics.hpp>
#include "BackgroundLayer.h"
#include <vector>
#include "GameSTate.h"
#include "GameObject.h"
class SideScrollerPlayState : public GameState 
{
	GameObject playerObj{ Cfg::Textures::CrashersPlayerSheet, {800.f,1200.f}, {0.f,0.f}, {0.f,0.f}, {228.f,150.f},{{0,0},{228,150}} };
	std::vector<BackgroundLayer> bgLayers;
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
};
