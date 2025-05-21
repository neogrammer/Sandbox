#include "SideScrollerState.h"

void SideScrollerState::handleInput(float dt_)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Q))
    {
        switchGState(GStateType::SandboxChoice);
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


}

void SideScrollerState::tickBegin() {}

void SideScrollerState::tickEnd(float dt_) {}