
// PlayState.cpp
#include "SideScrollerPlayState.h"
#include "Cfg.h"

SideScrollerPlayState::SideScrollerPlayState(sf::RenderWindow& tv_) : GameState{ GStateType::SandboxSideScroller, tv_ } { load(); }

SideScrollerPlayState::~SideScrollerPlayState() {}

void SideScrollerPlayState::load() {
    // Load different layers with varying scroll speeds
    _backgroundLayers.emplace_back(Cfg::Textures::Crash_Intro_0, 20.0f);
    _backgroundLayers.emplace_back(Cfg::Textures::Crash_Intro_1, 20.0f);
    _backgroundLayers.emplace_back(Cfg::Textures::Crash_Intro_2, 20.0f);
    _backgroundLayers.emplace_back(Cfg::Textures::Crash_Intro_3, 20.0f);

    // Add more layers as needed
}

void SideScrollerPlayState::update(sf::RenderWindow& window, float dt) {
    for (auto& layer : _backgroundLayers) {
        layer.update(dt);
    }
}

void SideScrollerPlayState::render(sf::RenderWindow& window) {
    for (auto& layer : _backgroundLayers) {
        layer.draw(window);
    }

    //sf::Text txt{ Cfg::fonts.get(Cfg::Fonts::SandboxChoiceStateFont) };
    //txt.setString("PlayState for Crashers");
    //txt.setPosition({ 100.f,100.f });
    //txt.setCharacterSize(36U);
    //txt.setFillColor(sf::Color::White);

    //window.draw(txt);

}


void SideScrollerPlayState::handleCollisions()
{
}

void SideScrollerPlayState::animate()
{
}

void SideScrollerPlayState::handleInput(float dt_)
{
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

