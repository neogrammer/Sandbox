#ifndef GAMESTATE_H__
#define GAMESTATE_H__
#include "GStateType.h"
#include <optional>
#include <SFML/Graphics.hpp>

class GameState
{
	GStateType mType;

	GStateType mPendingType;
protected:
	sf::View mainView;
	sf::View guiView;



public:
	GameState(GStateType type_, sf::RenderWindow& tv_) : mType{ type_ }, mPendingType{ type_ }, mainView{ tv_.getDefaultView() }, guiView{ tv_.getDefaultView() } {}
	virtual ~GameState() {}

	GStateType getType() { return mType; }
	bool isPendingSwitch() { return (mPendingType != mType); }
	GStateType getPendingType()
	{
		auto type = mPendingType;
		mPendingType = mType;
		return type;
	}
	void switchGState(GStateType type_)
	{
		mPendingType = type_;
	}

	virtual void handleInput(float dt_) = 0;
	virtual void handleEvent(const std::optional<sf::Event>& evt_) = 0;
	virtual void update(sf::RenderWindow& tv_, float dt_) = 0;
	virtual void handleCollisions() = 0;
	virtual void animate() = 0;
	virtual void render(sf::RenderWindow& tv_) = 0;

	virtual void tickBegin()=0;
	virtual void tickEnd(float dt_)=0;
};

#endif