#include "SandboxApp.h"

void SandboxApp::updateFrame()
{
    while (const std::optional event = mTV.pollEvent())
    {
        if (event->is<sf::Event::Closed>())
        {
            mTV.close();
        }
        else if (const auto* keyPressed = event->getIf<sf::Event::KeyPressed>())
        {
            if (keyPressed->scancode == sf::Keyboard::Scancode::Escape)
                mTV.close();
        }
        // for each currentObjects -> dynamic_cast<Interface SFEventSensitive> -> currObj.processEvent(sf::Event);
        mCurrGState->handleEvent(event);
    }
    mCurrGState->tickBegin();
    float dt = mTimer.restart().asSeconds();

    mCurrGState->handleInput(dt);
    mCurrGState->update(mTV, dt);
    mCurrGState->handleCollisions();
    mCurrGState->animate();

    mCurrGState->tickEnd(dt);

}

void SandboxApp::updateWorld(float dt_)
{
    //// update current scene non-culled objects by dt_
    //for (auto& star : stars)
    //{
    //    star->distance += star->speed * dt_ * (star->distance / 800.f);
    //    //auto pos = star->distance + (star->speed * dt_);
    //    //star->distance = pos; 
    //   //star->angle += (10.f * dt_);
    //    if (star->distance > 800.f)
    //    {
    //        star->angle = Random(0.f, 2.0f * 3.14159f);
    //        //star->speed = Random(10.f,100.f);
    //        star->distance = Random(1.f, 100.f);
    //        float lum = Random(0.3f, 1.f);
    //        star->col = sf::Color((uint8_t)(lum * 255.f), (uint8_t)(lum * 255.f), (uint8_t)(lum * 255.f), 255);
    //    }
    //}
   
}

void SandboxApp::render()
{
    mTV.clear(sf::Color(0,0,0,255));

    mCurrGState->render(mTV);

    
    mTV.display();
}

void SandboxApp::run()
{
    while (mTV.isOpen() && mGameRunning)
    {
        if (mCurrGState->isPendingSwitch())
            mCurrGState = gStates[mCurrGState->getPendingType()];
        updateFrame();
        render();
    }
    if (mTV.isOpen())
    {
        mTV.close();
    }
    return;
}

