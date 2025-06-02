#include "SandboxChoiceState.h"

void SandboxChoiceState::handleInput(float dt_)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Enter))
    {
        switchGState(GStateType::SandboxStarShooter);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space))
    {
        switchGState(GStateType::SandboxSideScroller);
    }
}

void SandboxChoiceState::handleEvent(const std::optional<sf::Event>& evt_)
{
}

void SandboxChoiceState::handleCollisions()
{
}

void SandboxChoiceState::animate()
{
}

void SandboxChoiceState::update(sf::RenderWindow& tv_, float dt_)
{
}

void SandboxChoiceState::tickBegin()
{
   // ship->tickBegin();
}

void SandboxChoiceState::tickEnd(float dt_) 
{
   //ship->tickEnd(dt_);
}


void SandboxChoiceState::render(sf::RenderWindow & tv_)
{
    sf::Sprite spr{ Cfg::textures.get(Cfg::Textures::ChoiceStateBG) };
    spr.setScale({ 2.7f,2.9f });
    tv_.draw(spr);
    tv_.draw(header);
    tv_.draw(underlineRect);

    for (auto& opt : options)
    {
        tv_.draw(opt);
    }
}