#include "SandboxChoiceState.h"

void SandboxChoiceState::handleInput(float dt_)
{
    bool enterPressed = false;
    
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Enter))
        {
            enterPressed = true;
          
                currFaceIdx = FaceType::Triggered;
                face.setTexture(Cfg::textures.get(Cfg::Textures::MyFaceTriggered));
            
            //switchGState(GStateType::SandboxStarShooter);
        }
        else
        {
            currFaceIdx = FaceType::Untriggered;
            face.setTexture(Cfg::textures.get(Cfg::Textures::MyFaceUntriggered));
        }

        if (enterPressed)
        {
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space))
            {
                if (currOpt == 0)
                    switchGState(GStateType::SandboxStarShooter);
                else if (currOpt == 1)
                    switchGState(GStateType::SandboxSideScroller);
                

            }
        }
    



    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up))
    {

        if (canPressUpAgain)
        {
            canPressUpAgain = false;
            if (currOpt == 1)
            {
                currOpt = 0;
            }
            else  if (currOpt == 2)
            {
                currOpt = 1;
            }
        }
    }
    else
    {
        canPressUpAgain = true;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down))
    {
        if (canPressDownAgain)
        {
            canPressDownAgain = false;
            if (currOpt == 1)
            {
                currOpt = 2;
            }
            else  if (currOpt == 0)
            {
                currOpt = 1;
            }
        }
    }
    else
    {
        canPressDownAgain = true;
    }
}

void SandboxChoiceState::handleEvent(const std::optional<sf::Event>& evt_)
{

        if (const auto* keyPressed = evt_->getIf<sf::Event::KeyReleased>())
        {
            if (keyPressed->scancode == sf::Keyboard::Scancode::Enter)
            {
                if (currOpt == 2)
                {
                    closing = true;
                }

            }
        }
}

void SandboxChoiceState::handleCollisions()
{
}

void SandboxChoiceState::animate()
{
}

void SandboxChoiceState::update(sf::RenderWindow& tv_, float dt_)
{
    OPT0C = sf::Color::White;
    OPT1C = sf::Color::White;
    OPT2C = sf::Color::White;


    switch (currOpt)
    {
    case 0:
        OPT0C = sf::Color::Yellow;
        face.setPosition({ 400.f, OPT0Y });
        break;
    case 1:
        OPT1C = sf::Color::Yellow;
        face.setPosition({ 400.f, OPT1Y });
        break;
    case 2:
        OPT2C = sf::Color::Yellow;
        face.setPosition({ 400.f, OPT2Y });
        break;
    default:
        break;
    }

    options[0].setFillColor(OPT0C);
    options[1].setFillColor(OPT1C);
    options[2].setFillColor(OPT2C);

    eyeLaser.setPosition(eyeLaserPos[currOpt]);


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
    tv_.draw(face);

    if (currFaceIdx == FaceType::Triggered)
    {
        eyeLaser.setFillColor(sf::Color::Yellow);
        eyeLaser.setOutlineColor(sf::Color::Green);
        eyeLaser.setOutlineThickness(1U);
       
        
    }
    else
    {
        eyeLaser.setFillColor(sf::Color::Transparent);
        eyeLaser.setOutlineColor(sf::Color::Transparent);


    }

    tv_.draw(eyeLaser);

}