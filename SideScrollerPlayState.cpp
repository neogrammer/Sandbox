
// PlayState.cpp
#include "SideScrollerPlayState.h"
#include "Cfg.h"
#include <iostream>
SideScrollerPlayState::SideScrollerPlayState(sf::RenderWindow& tv_) : GameState{ GStateType::SandboxSideScroller, tv_ }
, bgLayers{}
{
    bgLayers.clear();
    bgLayers.emplace_back(BackgroundLayer{ tv_, Cfg::Textures::Crash_Intro_0 , .10f});
    bgLayers.emplace_back(BackgroundLayer{ tv_, Cfg::Textures::Crash_Intro_1, 0.24f });
    bgLayers.emplace_back(BackgroundLayer{ tv_, Cfg::Textures::Crash_Intro_2, 0.70f });
    bgLayers.emplace_back(BackgroundLayer{ tv_, Cfg::Textures::Crash_Intro_3 , 1.f});


    playerObj.setPos({ 800.f, 600.f });
}

SideScrollerPlayState::~SideScrollerPlayState() {}

void SideScrollerPlayState::load() {
   

    // Add more layers as needed
}

void SideScrollerPlayState::update(sf::RenderWindow& window, float dt) {
  
}

void SideScrollerPlayState::render(sf::RenderWindow& window) 
{

    bgLayers[0].draw(window);
    bgLayers[1].draw(window);
    bgLayers[2].draw(window);
    bgLayers[3].draw(window);

   // draw the player
    playerObj.render(window);
}


void SideScrollerPlayState::handleCollisions()
{
}

void SideScrollerPlayState::animate()
{
}

void SideScrollerPlayState::handleInput(float dt_)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right))
    {
        
        bgLayers[0].move({ 300.f,0.f }, dt_);
        bgLayers[1].move({ 300.f,0.f }, dt_);
        bgLayers[2].move({ 300.f,0.f }, dt_);
        bgLayers[3].move({ 300.f,0.f }, dt_);

    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left))
    {
        bgLayers[0].move({ -300.f,0.f }, dt_);
        bgLayers[1].move({ -300.f,0.f }, dt_);
        bgLayers[2].move({ -300.f,0.f }, dt_);
        bgLayers[3].move({ -300.f,0.f }, dt_);

     }
    else if (!sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left) && !sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right))
    {
        bgLayers[0].move({ 0.f,0.f }, dt_);
        bgLayers[1].move({ 0.f,0.f }, dt_);
        bgLayers[2].move({ 0.f,0.f }, dt_);
        bgLayers[3].move({ 0.f,0.f }, dt_);

    }
}

void SideScrollerPlayState::handleEvent(const std::optional<sf::Event>& evt_)
{
}

void SideScrollerPlayState::tickBegin()
{
}
void SideScrollerPlayState::tickEnd(float dt_)
{
}

