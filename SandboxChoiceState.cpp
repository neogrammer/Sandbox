#include "SandboxChoiceState.h"

void SandboxChoiceState::handleInput(float dt_)
{
<<<<<<< HEAD
=======

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::P))
    {
        switchGState(GStateType::SandboxSideScroller);
    }
    static bool turning{ false };
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space))
    {
        auto vec = sf::Vector2f{ (56000.f / ship->getMass()) * cosf(ship->getRotation().asRadians()), (56000.f / ship->getMass()) * (sinf(ship->getRotation().asRadians())) };
        if (vec != sf::Vector2f{ 0.f,0.f })
        {
            vec = vec.normalized();
        }
        turning = false;

        ship->applyForce(56000.f, vec);
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left))
    {
        ship->rotate(sf::degrees(-200.f * dt_));
        if (ship->getRotation() >= sf::degrees(360.f))
        {
            ship->setRotation(sf::degrees(0.f));
        }
        turning = true;

    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right))
    {
        ship->rotate(sf::degrees(200.f * dt_));
        if (ship->getRotation() < sf::degrees(0.f))
        {
            ship->setRotation(sf::degrees(359.999f));
        }
        turning = true;

    }

    if (!sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S) && !sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space))
    {
        auto vec1 = sf::Vector2f{ (56000.f / ship->getMass()) * cosf(ship->getRotation().asRadians()), (56000.f / ship->getMass()) * (sinf(ship->getRotation().asRadians())) };
        auto vec = vec1;
        if (vec != sf::Vector2f{ 0.f,0.f })
        {
            vec = vec.normalized();
        }
        float ang = ship->getRotation().asRadians();
        sf::Vector2f output;
        output = {cosf(ang),sinf(ang)};
        if (turning)
            ship->setVel( ship->getVel() * 0.94f);
        else
            ship->setVel(ship->getVel() * 0.99f);

        //std::max(fabsf(output.x),0.97f)), ship->getVel().y* (std::max(fabsf(output.y),0.97f)) });   //, ship->getVel().y * .97f * vec.y });

      //  ship->setVel({ ship->getVel().x * std::max(fabsf(output.x),0.97f) ), ship->getVel().y * (std::max(fabsf(output.y),0.97f) ) });   //, ship->getVel().y * .97f * vec.y });


        //if (ship->getPos().x > ship->getPrevPos().x && ship->getPos().y > ship->getPrevPos().y)
        //{
        //    if ((ship->getPos().y - ship->getPrevPos().y) / (((ship->getPos().x - ship->getPrevPos().x) == 0.f) ? 1.f : ship->getPos().x - ship->getPrevPos().x) < 1.f)
        //    {
        //        //favor x
        //        ship->setVel({ ship->getVel().x * .99f , ship->getVel().y * .97f });
        //    }
        //    else
        //    {
        //        //favor y
        //        ship->setVel({ ship->getVel().x * .99f, ship->getVel().y * .97f });

        //    }
        //}
        //else if (ship->getPos().x < ship->getPrevPos().x && ship->getPos().y < ship->getPrevPos().y)
        //if (fabsf((ship->getPos().y - ship->getPrevPos().y)) / ((fabsf(ship->getPos().x - ship->getPrevPos().x) == 0.f) ? 1.f : fabsf(ship->getPos().x - ship->getPrevPos().x)) < 1.f)
        //{
        //    // favor x
        //    ship->setVel({ ship->getVel().x * .99f, ship->getVel().y * .97f });
        //}
        //else
        //{
        //    // favor y
        //    ship->setVel({ ship->getVel().x * .99f, ship->getVel().y * .97f });
        //}
        //else  if (ship->getPos().x > ship->getPrevPos().x && ship->getPos().y < ship->getPrevPos().y)
        //{
        //    if (fabsf(ship->getPos().y - ship->getPrevPos().y) / (((ship->getPos().x - ship->getPrevPos().x) == 0.f) ? 1.f : ship->getPos().x - ship->getPrevPos().x) < 1.f)
        //    {
        //        //favor x
        //        ship->setVel({ ship->getVel().x * .99f, ship->getVel().y * .97f });
        //    }
        //    else
        //    {
        //        //favor y
        //        ship->setVel({ ship->getVel().x * .99f, ship->getVel().y * .97f });

        //    }
        //}
        //else if (ship->getPos().x < ship->getPrevPos().x && ship->getPos().y > ship->getPrevPos().y)
        //    if ((ship->getPos().y - ship->getPrevPos().y) / ((fabsf(ship->getPos().x - ship->getPrevPos().x) == 0.f) ? 1.f : fabsf(ship->getPos().x - ship->getPrevPos().x)) < 1.f)
        //    {
        //        // favor x
        //        ship->setVel({ ship->getVel().x * .99f, ship->getVel().y * .97f });
        //    }
        //    else
        //    {
        //        // favor y
        //        ship->setVel({ ship->getVel().x * .99f, ship->getVel().y * .97f });
        //    }

        if (fabsf(ship->getVel().x) < 10.f)
            ship->setVel({ 0.f, ship->getVel().y });
        if (fabsf(ship->getVel().y) < 10.f)
            ship->setVel({ ship->getVel().x, 0.f });

    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
    {
        auto vec = sf::Vector2f{ (56000.f / ship->getMass()) * cosf(ship->getRotation().asRadians()),  (56000.f / ship->getMass()) * (sinf(ship->getRotation().asRadians())) };
        if (vec != sf::Vector2f{ 0.f,0.f })
        {
            vec = vec.normalized();
        }
        turning = false;
        ship->applyForce(-56000.f, vec);
    }


>>>>>>> 0ba6844c3be707589ae6566a3b3a07ac223dac39
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

<<<<<<< HEAD
void SandboxChoiceState::tickEnd(float dt_) 
{
   //ship->tickEnd(dt_);
=======
void SandboxChoiceState::tickEnd(float dt_) {
    ship->tickEnd(dt_);
    if (ship->getPos().x < -ship->getSize().x)
        ship->setPos({ 1600.f+ship->getSize().x,ship->getPos().y});
    if (ship->getPos().y < -ship->getSize().y)
        ship->setPos({ship->getPos().x, 900.f + ship->getSize().y });
    if (ship->getPos().x > 1600.f + ship->getSize().x)
        ship->setPos({ 0.f - ship->getSize().x,ship->getPos().y });
    if (ship->getPos().y > 900.f + ship->getSize().y)
        ship->setPos({ ship->getPos().x, 0.f - ship->getSize().y });


>>>>>>> 0ba6844c3be707589ae6566a3b3a07ac223dac39
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