#ifndef SANDBOXCHOICESTATE_H__
#define SANDBOXCHOICESTATE_H__
#include "GameState.h"
#include "Star.h"
#include "Cfg.h"
#include "GameObject.h"
class SandboxChoiceState : public GameState
{

	sf::Text header;
	std::array<sf::Text, 3> options;
	sf::RectangleShape underlineRect;
	
	



public:
	SandboxChoiceState(sf::RenderWindow& tv_) : GameState{ GStateType::SandboxChoice, tv_ } 
		, header{Cfg::fonts.get(Cfg::Fonts::SandboxChoiceStateFont)}
		, options{ {{Cfg::fonts.get(Cfg::Fonts::SandboxChoiceStateFont)}, {Cfg::fonts.get(Cfg::Fonts::SandboxChoiceStateFont)}, {Cfg::fonts.get(Cfg::Fonts::SandboxChoiceStateFont)} }  }
		, underlineRect{ {24.f * 23.f, 4.f} }
	{
		header.setFillColor(sf::Color::White);
		header.setOutlineColor(sf::Color::Black);
		header.setOutlineThickness(2U);
		header.setCharacterSize(48U);
		header.setPosition({ 802.f, 50.f });
		header.setString("Select Program to Run");
		
		underlineRect.setFillColor(sf::Color::Yellow);
		underlineRect.setPosition({ header.getPosition().x, header.getPosition().y + 56.f });
		underlineRect.setOutlineColor(sf::Color::Transparent);

		options[0].setString("Star Shooter");
		options[1].setString("Crasher Scroller");
		options[2].setString("Exit");

		options[0].setPosition({802.f, 200.f});
		options[1].setPosition({ 802.f, 400.f });
		options[2].setPosition({ 802.f, 600.f });


		for (auto& opt : options)
		{
			opt.setFillColor(sf::Color::White);
			opt.setOutlineColor(sf::Color::Black);
			opt.setOutlineThickness(2U);
			opt.setCharacterSize(48U);
			
		}

	}
	~SandboxChoiceState() override final {}

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