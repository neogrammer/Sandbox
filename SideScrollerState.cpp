#include "SideScrollerState.h"

void SideScrollerState::handleInput(float dt_)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Q))
    {
        switchGState(GStateType::SandboxChoice);
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::P))
    {
        switchGState(GStateType::SandboxSideScrollerPlay);

    }
}

void SideScrollerState::handleEvent(const std::optional<sf::Event>& evt_)
{
}

void SideScrollerState::handleCollisions()
{
}

void SideScrollerState::animate()
{
}

void SideScrollerState::update(sf::RenderWindow& tv_, float dt_)
{
   
}

void SideScrollerState::render(sf::RenderWindow& tv_)
{
    sf::Text txt{ Cfg::fonts.get(Cfg::Fonts::SandboxChoiceStateFont) };
    txt.setString("MainState for Crashers");
    txt.setPosition({100.f,100.f});
    txt.setCharacterSize(36U);
    txt.setFillColor(sf::Color::White);

    tv_.draw(txt);


}

void SideScrollerState::tickBegin() {}

void SideScrollerState::tickEnd(float dt_) {}