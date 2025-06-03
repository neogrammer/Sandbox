#ifndef SIDESCROLLERSTATE_H__
#define SIDESCROLLERSTATE_H__
#include "GameState.h"
#include "Cfg.h"
class SideScrollerState : public GameState
{

	sf::Sprite bg;
	


public:
	SideScrollerState(sf::RenderWindow& tv_) : GameState{ GStateType::SandboxSideScroller, tv_ }
		, bg{Cfg::textures.get(Cfg::Textures::CrashersBG)}
	{
		
	}
	~SideScrollerState() override final {}

	void handleInput(float dt_) override final;
	void handleEvent(const std::optional<sf::Event>& evt_) override final;
	void update(sf::RenderWindow& tv_, float dt_) override final;
	void handleCollisions() override final;
	void animate() override final;
	void render(sf::RenderWindow& tv_) override final;

	void tickBegin() override;
	void tickEnd(float dt_) override;
};

#endif