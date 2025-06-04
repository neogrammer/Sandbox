
// PlayState.cpp
#include "SideScrollerPlayState.h"
#include "Cfg.h"
#include <iostream>
SideScrollerPlayState::SideScrollerPlayState(sf::RenderWindow& tv_) : GameState{ GStateType::SandboxSideScroller, tv_ }, totalXScrolled{} 
{
    
    load(); 
    totalXScrolled.clear();
    totalXScrolled.reserve(4);
    for (int i = 0; i < 4; i++)
        totalXScrolled.emplace_back(float{0.f});
}

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
        

        if ((_backgroundLayers[0].getPosition().x - ((0.25f * 600.f)) * dt_) >= -1.f  * _backgroundLayers[0].getTextureSize().x || (totalXScrolled[0] + ((0.25f * 600.f)) * dt_) < 0.f)
        {
            _backgroundLayers[0].setScrollSpeed(0.2500f * 600.f);
            _backgroundLayers[0].setPosition({ _backgroundLayers[0].getPosition().x - ((0.25f + (3.f * 0.25f)) * 600.f) * dt_  ,0.f });
            totalXScrolled[0] += ((0.25f * 600.f) * dt_);

        }
        else
        {
            if (_backgroundLayers[0].getPosition().x - ((0.25f * 600.f)) * dt_ < -1.f * _backgroundLayers[0].getTextureSize().x)
            {
                auto pos = _backgroundLayers[0].getPosition().x - _backgroundLayers[0].getPosition().x - ((0.25f * 600.f)) * dt_;
                _backgroundLayers[0].setScrollSpeed(0.f);
                _backgroundLayers[0].setPosition({ 0.f - pos  ,0.f });
                totalXScrolled[0] = -pos;

                // uh oh gap on left side of screen!
            }
            else if (totalXScrolled[0] + ((0.25f * 600.f)) * dt_ > 0.f)
            {
                totalXScrolled[0] = (float)_backgroundLayers[0].getTextureSize().x;
                //moved position will be 
                _backgroundLayers[0].setPosition({ _backgroundLayers[0].getPosition().x - _backgroundLayers[0].getTextureSize().x ,0.f });
                _backgroundLayers[0].setScrollSpeed(0.f);
            }
        }

        if ((_backgroundLayers[1].getPosition().x - ((0.5f * 600.f)) * dt_) >= -1.f * _backgroundLayers[1].getTextureSize().x || (totalXScrolled[1] + ((0.5f * 600.f)) * dt_) < 0.f)
        {
            _backgroundLayers[1].setScrollSpeed(0.500f * 600.f);
            _backgroundLayers[1].setPosition({ _backgroundLayers[1].getPosition().x - ((0.25f + (3.f * 0.25f)) * 600.f) * dt_  ,0.f });
            totalXScrolled[1] += ((0.5f * 600.f) * dt_);

        }
        else
        {
            if (_backgroundLayers[1].getPosition().x - ((0.5f * 600.f)) * dt_ < -1.f * _backgroundLayers[1].getTextureSize().x)
            {
                auto pos = _backgroundLayers[1].getPosition().x - _backgroundLayers[1].getPosition().x - ((0.5f * 600.f)) * dt_;
                _backgroundLayers[1].setScrollSpeed(0.f);
                _backgroundLayers[1].setPosition({ 0.f - pos  ,0.f });
                totalXScrolled[1] = -pos;

                // uh oh gap on left side of screen!
            }
            else if (totalXScrolled[1] + ((0.5f * 600.f)) * dt_ > 0.f)
            {
                totalXScrolled[1] = (float)_backgroundLayers[1].getTextureSize().x;
                //moved position will be 
                _backgroundLayers[1].setPosition({ _backgroundLayers[1].getPosition().x - _backgroundLayers[1].getTextureSize().x ,0.f });
                _backgroundLayers[1].setScrollSpeed(0.f);
            }
        }

        if ((_backgroundLayers[2].getPosition().x - ((0.75f * 600.f)) * dt_) >= -1.f * _backgroundLayers[2].getTextureSize().x || (totalXScrolled[2] + ((0.75f * 600.f)) * dt_) < 0.f)
        {
            _backgroundLayers[2].setScrollSpeed(0.7500f * 600.f);
            _backgroundLayers[2].setPosition({ _backgroundLayers[2].getPosition().x - ((0.25f + (3.f * 0.25f)) * 600.f) * dt_  ,0.f });
            totalXScrolled[2] += ((0.75f * 600.f) * dt_);

        }
        else
        {
            if (_backgroundLayers[2].getPosition().x - ((0.75f * 600.f)) * dt_ < -1.f * _backgroundLayers[2].getTextureSize().x)
            {
                auto pos = _backgroundLayers[2].getPosition().x - _backgroundLayers[2].getPosition().x - ((0.75f * 600.f)) * dt_;
                _backgroundLayers[2].setScrollSpeed(0.f);
                _backgroundLayers[2].setPosition({ 0.f - pos  ,0.f });
                totalXScrolled[2] = -pos;

                // uh oh gap on left side of screen!
            }
            else if (totalXScrolled[2] + ((0.75f * 600.f)) * dt_ > 0.f)
            {
                totalXScrolled[2] = (float)_backgroundLayers[2].getTextureSize().x;
                //moved position will be 
                _backgroundLayers[2].setPosition({ _backgroundLayers[2].getPosition().x - _backgroundLayers[2].getTextureSize().x ,0.f });
                _backgroundLayers[2].setScrollSpeed(0.f);
            }
        }

        if ((_backgroundLayers[3].getPosition().x - ((1.f * 600.f)) * dt_) >= -1.f * _backgroundLayers[3].getTextureSize().x || (totalXScrolled[3] + ((1.f * 600.f)) * dt_) < 0.f)
        {
            _backgroundLayers[3].setScrollSpeed(1.00f * 600.f);
            _backgroundLayers[3].setPosition({ _backgroundLayers[3].getPosition().x - ((0.25f + (3.f * 0.25f)) * 600.f) * dt_  ,0.f });
            totalXScrolled[3] += ((1.f * 600.f) * dt_);

        }
        else
        {
            if (_backgroundLayers[3].getPosition().x - ((1.f * 600.f)) * dt_ < -1.f * _backgroundLayers[3].getTextureSize().x)
            {
                auto pos = _backgroundLayers[3].getPosition().x - _backgroundLayers[3].getPosition().x - ((1.f * 600.f)) * dt_;
                _backgroundLayers[3].setScrollSpeed(0.f);
                _backgroundLayers[3].setPosition({ 0.f - pos  ,0.f });
                totalXScrolled[3] = -pos;

                // uh oh gap on left side of screen!
            }
            else if (totalXScrolled[3] + ((1.f * 600.f)) * dt_ > 0.f)
            {
                totalXScrolled[3] = (float)_backgroundLayers[3].getTextureSize().x;
                //moved position will be 
                _backgroundLayers[3].setPosition({ _backgroundLayers[3].getPosition().x - _backgroundLayers[3].getTextureSize().x ,0.f });
                _backgroundLayers[3].setScrollSpeed(0.f);
            }
        }

        std::cout << std::to_string(totalXScrolled[0]) << std::endl;
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left))
    {
        ////////////////////////////////////////////////////////////////////////////
        if ((_backgroundLayers[0].getPosition().x + ((0.25f * 200.f)) * dt_) <= 0.f || (totalXScrolled[0] - ((0.25f * 200.f)) * dt_) > 0.f)
        {
            _backgroundLayers[0].setScrollSpeed(0.2500f * -200.f);
            _backgroundLayers[0].setPosition({ _backgroundLayers[0].getPosition().x + ((0.25f + (3.f * 0.25f)) * 200.f) * dt_  ,0.f });
            totalXScrolled[0] -= ((0.25f * 200.f) * dt_);

        }
        else
        {
            if (_backgroundLayers[0].getPosition().x + ((0.25f * 200.f)) * dt_ > 0.f)
            {
                auto pos = _backgroundLayers[0].getPosition().x + ((0.25f * 200.f)) * dt_;
                _backgroundLayers[0].setScrollSpeed(0.2500f * -200.f);
                _backgroundLayers[0].setPosition({ _backgroundLayers[0].getPosition().x - _backgroundLayers[0].getTextureSize().x  ,0.f });
                totalXScrolled[0] = -pos + _backgroundLayers[0].getTextureSize().x;

                // uh oh gap on left side of screen!
            }
            else if (totalXScrolled[0] - ((0.25f * 200.f)) * dt_ < 0.f)
            {
                totalXScrolled[0] = (float)_backgroundLayers[0].getTextureSize().x;
                //moved position will be 
                _backgroundLayers[0].setPosition({ -1.f * _backgroundLayers[0].getTextureSize().x ,0.f });
                _backgroundLayers[0].setScrollSpeed(0.f);
            }
        }

        //////////////////////////////////////////////////////
        if ((_backgroundLayers[1].getPosition().x + ((0.5f * 200.f)) * dt_) <= 0.f || (totalXScrolled[1] - ((0.5f * 200.f)) * dt_) > 0.f)
        {
            _backgroundLayers[1].setScrollSpeed(0.500f * -200.f);
            _backgroundLayers[1].setPosition({ _backgroundLayers[1].getPosition().x + ((0.25f + (3.f * 0.25f)) * 200.f) * dt_  ,0.f });
            totalXScrolled[1] -= ((0.5f * 200.f) * dt_);

        }
        else
        {
            if (_backgroundLayers[1].getPosition().x + ((0.5f * 200.f)) * dt_ > 0.f)
            {
                auto pos = _backgroundLayers[1].getPosition().x + ((0.5f * 200.f)) * dt_;
                _backgroundLayers[1].setScrollSpeed(0.500f * -200.f);
                _backgroundLayers[1].setPosition({ _backgroundLayers[1].getPosition().x - _backgroundLayers[1].getTextureSize().x  ,0.f });
                totalXScrolled[1] = -pos + _backgroundLayers[1].getTextureSize().x;

                // uh oh gap on left side of screen!
            }
            else if (totalXScrolled[1] - ((0.5f * 200.f)) * dt_ < 0.f)
            {
                totalXScrolled[1] = (float)_backgroundLayers[1].getTextureSize().x;
                //moved position will be 
                _backgroundLayers[1].setPosition({ -1.f * _backgroundLayers[1].getTextureSize().x ,0.f });
                _backgroundLayers[1].setScrollSpeed(0.f);
            }
        }

        if ((_backgroundLayers[2].getPosition().x + ((1.f * 200.f)) * dt_) <= 0.f || (totalXScrolled[3] - ((1.f * 200.f)) * dt_) > 0.f)
        {
            _backgroundLayers[2].setScrollSpeed(1.00f * -200.f);
            _backgroundLayers[2].setPosition({ _backgroundLayers[2].getPosition().x + ((0.25f + (3.f * 0.25f)) * 200.f) * dt_  ,0.f });
            totalXScrolled[2] -= ((1.f * 200.f) * dt_);

        }
        else
        {
            if (_backgroundLayers[2].getPosition().x + ((1.f * 200.f)) * dt_ > 0.f)
            {
                auto pos = _backgroundLayers[2].getPosition().x + ((1.f * 200.f)) * dt_;
                _backgroundLayers[2].setScrollSpeed(1.00f * -200.f);
                _backgroundLayers[2].setPosition({ _backgroundLayers[2].getPosition().x - _backgroundLayers[2].getTextureSize().x  ,0.f });
                totalXScrolled[2] = -pos + _backgroundLayers[2].getTextureSize().x;

                // uh oh gap on left side of screen!
            }
            else if (totalXScrolled[2] - ((1.f * 200.f)) * dt_ < 0.f)
            {
                totalXScrolled[2] = (float)_backgroundLayers[2].getTextureSize().x;
                //moved position will be 2
                _backgroundLayers[2].setPosition({ -1.f * _backgroundLayers[2].getTextureSize().x ,0.f });
                _backgroundLayers[2].setScrollSpeed(0.f);
            }

        }






        if ((_backgroundLayers[3].getPosition().x + ((1.f * 200.f)) * dt_) <= 0.f || (totalXScrolled[3] - ((1.f * 200.f)) * dt_) > 0.f)
        {
            _backgroundLayers[3].setScrollSpeed(1.00f * -200.f);
            _backgroundLayers[3].setPosition({ _backgroundLayers[3].getPosition().x + ((0.25f + (3.f * 0.25f)) * 200.f) * dt_  ,0.f });
            totalXScrolled[3] -= ((1.f * 200.f) * dt_);

        }
        else
        {
            if (_backgroundLayers[3].getPosition().x + ((1.f * 200.f)) * dt_ > 0.f)
            {
                auto pos = _backgroundLayers[3].getPosition().x + ((1.f * 200.f)) * dt_;
                _backgroundLayers[3].setScrollSpeed(1.00f * -200.f);
                _backgroundLayers[3].setPosition({ _backgroundLayers[3].getPosition().x - _backgroundLayers[3].getTextureSize().x  ,0.f });
                totalXScrolled[3] = -pos + _backgroundLayers[3].getTextureSize().x;

                // uh oh gap on left side of screen!
            }


            else if (totalXScrolled[3] - ((1.f * 200.f)) * dt_ < 0.f)
            {
                totalXScrolled[3] = (float)_backgroundLayers[3].getTextureSize().x;
                //moved position will be 
                _backgroundLayers[3].setPosition({ -1.f * _backgroundLayers[3].getTextureSize().x ,0.f });
                _backgroundLayers[3].setScrollSpeed(0.f);
            }
        }

        std::cout << std::to_string(totalXScrolled[0]) << std::endl;

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

