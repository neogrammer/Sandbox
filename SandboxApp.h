#ifndef SANDBOXAPP_H__
#define SANDBOXAPP_H__
#include <SFML/Graphics.hpp>
#include <string>
#include "Player.h"
#include "Star.h"
#include <random>
#include "SandboxChoiceState.h"
#include "SideScrollerState.h"


class SandboxApp
{
	
	// test variables for sandboxing will go here
	
	

	const float MaxElapsed{ (1.f / 60.f) * 5.f };
	const float FPS60{ (1.f / 60.f) };

private:

	sf::RenderWindow mTV;
	std::shared_ptr<GameState> mCurrGState;
	sf::Time mElapsed{ sf::Time::Zero };
	sf::Clock mTimer{};
	std::string mTitle;
	bool mGameRunning{ true };
	std::unordered_map<GStateType, std::shared_ptr<GameState>> gStates;

	void updateFrame();
	void updateWorld(float dt_);
	void render();
public:
	SandboxApp(uint32_t width_ = 1600, uint32_t height_ = 900, std::string title_ = "Sandbox") : mTV{ sf::VideoMode{{width_,height_},32U} , title_, sf::State::Windowed }, mTitle{ title_ } 
	 , gStates{}
		, mCurrGState{}
	{
		gStates.emplace(std::pair{ GStateType::SandboxChoice, std::make_shared<SandboxChoiceState>(mTV) });
		gStates.emplace(std::pair{ GStateType::SandboxSideScroller, std::make_shared<SideScrollerState>(mTV) });

		mCurrGState = gStates[GStateType::SandboxChoice];
		
	}
	void run();

	
};

#endif