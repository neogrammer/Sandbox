#include "StarShooterState.h"

void StarShooterState::handleInput(float dt_)
{

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Q))
    {
        switchGState(GStateType::SandboxChoice);
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space))
    {
        auto vec = sf::Vector2f{ (56000.f / ship->getMass()) * cosf(ship->getRotation().asRadians()), (56000.f / ship->getMass()) * (sinf(ship->getRotation().asRadians())) };
        if (vec != sf::Vector2f{ 0.f,0.f })
        {
            vec = vec.normalized();
        }

        ship->applyForce(56000.f, vec);
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left))
    {
        ship->rotate(sf::degrees(-200.f * dt_));
        if (ship->getRotation() >= sf::degrees(360.f))
        {
            ship->setRotation(sf::degrees(0.f));
                
        }
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right))
    {
        ship->rotate(sf::degrees(200.f * dt_));
        if (ship->getRotation() < sf::degrees(0.f))
        {
            ship->setRotation(sf::degrees(359.999f));

        }

    }

    if (!sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S) && !sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space))
    {
        ship->setVel(ship->getVel() * .985f);
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
        
        ship->applyForce(-56000.f, vec);
    }


    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Enter))
    {
        int i = 0;
    }
}

void StarShooterState::handleEvent(const std::optional<sf::Event>& evt_)
{
}

void StarShooterState::handleCollisions()
{
}

void StarShooterState::animate()
{
}

void StarShooterState::update(sf::RenderWindow& tv_, float dt_)
{
    // update current scene non-culled objects by dt_
    for (auto& star : stars)
    {
        star->distance += star->speed * dt_ * (star->distance / 800.f);
        //auto pos = star->distance + (star->speed * dt_);
        //star->distance = pos; 
       //star->angle += (10.f * dt_);
        if (star->distance > 800.f)
        {
            star->angle = Random(0.f, 2.0f * 3.14159f);
            //star->speed = Random(10.f,100.f);
            star->distance = Random(1.f, 100.f);
            float lum = Random(0.3f, 1.f);
            star->col = sf::Color((uint8_t)(lum * 255.f), (uint8_t)(lum * 255.f), (uint8_t)(lum * 255.f), 255);
        }
    }

    
}

void StarShooterState::tickBegin() {
    ship->tickBegin();
}

void StarShooterState::tickEnd(float dt_) {
    ship->tickEnd(dt_);
}


void StarShooterState::render(sf::RenderWindow & tv_)
{


    for (auto& star : stars)
    {
        sf::CircleShape shp{ 1.f };
        shp.setFillColor(sf::Color(((uint8_t)(star->col.r * (star->distance / 800.f)) % 255), ((uint8_t)(star->col.r * (star->distance / 800.f)) % 255), ((uint8_t)(star->col.r * (star->distance / 800.f)) % 255), 255));

        auto yAmt = sinf(star->angle) * star->distance;
        auto xAmt = cosf(star->angle) * star->distance;
        shp.setPosition({ origin.x + xAmt, origin.y + yAmt });

        tv_.draw(shp);
    }


    ship->render(tv_);

  /*  std::string str = "(x: ";
    char buffer[6];
    _itoa_s((int)ship->getVel().x, &buffer[0], 5, 10);
    str.append(std::string(buffer));
    str.append(", y: ");
    char buffer2[6];
    _itoa_s((int)ship->getVel().y, &buffer2[0], 5, 10);
    str.append(buffer2);
    str.append(")");
    mainText.setString(str);*/

    tv_.draw(mainText);

}