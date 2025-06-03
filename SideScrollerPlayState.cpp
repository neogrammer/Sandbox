
// PlayState.cpp
#include "SideScrollerPlayState.h"
#include "Cfg.h"
#include <iostream>
SideScrollerPlayState::SideScrollerPlayState(sf::RenderWindow& tv_) : GameState{ GStateType::SandboxSideScroller, tv_ } { load(); }

SideScrollerPlayState::~SideScrollerPlayState() {}

void SideScrollerPlayState::load() {
    // Load different layers with varying scroll speeds
    _backgroundLayers.emplace_back(Cfg::Textures::Crash_Intro_0, 0.f);
    _backgroundLayers.emplace_back(Cfg::Textures::Crash_Intro_1, 0.0f);
    _backgroundLayers.emplace_back(Cfg::Textures::Crash_Intro_2, 0.0f);
    _backgroundLayers.emplace_back(Cfg::Textures::Crash_Intro_3, 0.0f);

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

   /* sf::Text txt{ Cfg::fonts.get(Cfg::Fonts::SandboxChoiceStateFont) };
    txt.setString("PlayState for Crashers");
    txt.setPosition({ 100.f,100.f });
    txt.setCharacterSize(36U);
    txt.setFillColor(sf::Color::White);

    window.draw(txt);*/

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
        

        _backgroundLayers[0].setScrollSpeed(0.25f * 200.f);
        _backgroundLayers[1].setScrollSpeed(0.50f * 200.f);
        _backgroundLayers[2].setScrollSpeed(0.75f * 200.f);
        _backgroundLayers[3].setScrollSpeed(1.00f * 200.f);

        totalXScrolled += 200.f * dt_;
        std::cout << std::to_string(totalXScrolled) << std::endl;
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left))
    {
        if (_backgroundLayers[3].getPosition().x + 200.f * dt_ <= 0.f || totalXScrolled - 200.f * dt_ > 0.f)
        {
            _backgroundLayers[3].setScrollSpeed(1.00f * -200.f);
        }
        else
        {
            if (totalXScrolled > 0.f)
            {

                _backgroundLayers[3].setPosition({ -1.f * _backgroundLayers[3].getTextureSize().x ,0.f });
                _backgroundLayers[3].setScrollSpeed(1.f * -200.f);

            }
            else
            {
                totalXScrolled = 0.f;
                _backgroundLayers[3].setPosition({ 0.f,0.f });
                _backgroundLayers[3].setScrollSpeed(0.f);

            }
           
        }
        if (_backgroundLayers[2].getPosition().x + 150.f * dt_ <= 0.f || totalXScrolled - 200.f * dt_ > 0.f)
        {
            _backgroundLayers[2].setScrollSpeed(0.75f * -200.f);
        }
        else
        {
            if (totalXScrolled > 0.f)
            {

                _backgroundLayers[2].setPosition({ -1.f * _backgroundLayers[2].getTextureSize().x ,0.f });
                _backgroundLayers[2].setScrollSpeed(0.75f * -200.f);

            }
            else
            {
                totalXScrolled = 0.f;
                _backgroundLayers[2].setPosition({ 0.f,0.f });
                _backgroundLayers[2].setScrollSpeed(0.f);

            }
            
        }

        if (_backgroundLayers[1].getPosition().x + 100.f * dt_ <= 0.f || totalXScrolled -200.f * dt_ > 0.f)
        {
            _backgroundLayers[1].setScrollSpeed(.50f * -200.f);
        }
        else
        {
            if (totalXScrolled > 0.f)
            {

                _backgroundLayers[1].setPosition({ -1.f * _backgroundLayers[1].getTextureSize().x ,0.f });
                _backgroundLayers[1].setScrollSpeed(0.5f * -200.f);

            }
            else
            {
                totalXScrolled = 0.f;
                _backgroundLayers[1].setPosition({ 0.f,0.f });
                _backgroundLayers[1].setScrollSpeed(0.f);

            }
        }

        if (_backgroundLayers[0].getPosition().x + 50.f * dt_ <= 0 || totalXScrolled - 200.f * dt_ > 0.f)
        {
            _backgroundLayers[0].setScrollSpeed(0.25f * -200.f);
        }
        else
        {
            if (totalXScrolled > 0.f)
            {

                _backgroundLayers[0].setPosition({ -1.f * _backgroundLayers[0].getTextureSize().x ,0.f });
                _backgroundLayers[0].setScrollSpeed(0.25f * -200.f);

            }
            else
            {
                totalXScrolled = 0.f;
                _backgroundLayers[0].setPosition({ 0.f,0.f });
                _backgroundLayers[0].setScrollSpeed(0.f);

            }
        }


        totalXScrolled -= 200.f * dt_;
        if (totalXScrolled < 0.f)
        {
            totalXScrolled = 0.f;
        }
        std::cout << std::to_string(totalXScrolled) << std::endl;

            //_backgroundLayers[0].setScrollSpeed(0.25f * -200.f);
            //_backgroundLayers[1].setScrollSpeed(0.50f * -200.f);
           // _backgroundLayers[2].setScrollSpeed(0.75f * -200.f);
           // _backgroundLayers[3].setScrollSpeed(1.00f * -200
     }
    else if (!sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left) && !sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right))
    {

        _backgroundLayers[0].setScrollSpeed(0.f);
        _backgroundLayers[1].setScrollSpeed(0.f);
        _backgroundLayers[2].setScrollSpeed(0.f);
        _backgroundLayers[3].setScrollSpeed(0.f);

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

