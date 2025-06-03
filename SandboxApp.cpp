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
        mGameRunning = !mCurrGState->isClosing();
      }
    if (!mGameRunning) 
    {
        return; 
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
        {
            auto t = mCurrGState->getPendingType();
            if (t != GStateType::None)
                mCurrGState = gStates[t];
        }
        else        
        {
            mCurrGState->resetPending();
        }
        updateFrame();
        if (!mGameRunning) { continue; }
        render();
    }
    if (mTV.isOpen())
    {
        mTV.close();
    }
    return;
}

