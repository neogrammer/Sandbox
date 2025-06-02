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

	std::array<sf::Vector2f, 3> eyeLaserPos = {  };
	
	sf::RectangleShape eyeLaser{ {1200.f, 3.f} };

	bool canPressAgain{ true };
	bool canPressUpAgain{ true };
	bool canPressDownAgain{ true };

	enum class FaceType
	{
		Untriggered,
		Triggered
	};

	sf::Sprite face;
	FaceType currFaceIdx;
	int currOpt{ 0 };
	float OPT0Y{ 180 }, OPT1Y{ 380 }, OPT2Y{ 580 };
	sf::Color OPT0C{ sf::Color::White }, OPT1C{ sf::Color::White }, OPT2C{ sf::Color::White };

public:
	SandboxChoiceState(sf::RenderWindow& tv_) : GameState{ GStateType::SandboxChoice, tv_ } 
		, header{Cfg::fonts.get(Cfg::Fonts::SandboxChoiceStateFont)}
		, options{ {{Cfg::fonts.get(Cfg::Fonts::SandboxChoiceStateFont)}, {Cfg::fonts.get(Cfg::Fonts::SandboxChoiceStateFont)}, {Cfg::fonts.get(Cfg::Fonts::SandboxChoiceStateFont)} }  }
		, underlineRect{ {24.f * 23.f, 4.f + 56.f} }
		, face{Cfg::textures.get(Cfg::Textures::MyFaceUntriggered)}
		, currFaceIdx{FaceType::Untriggered}
	{
		eyeLaserPos[0] = { 453.f, 223.f };
		eyeLaserPos[1] = { 453.f, 423.f },
		eyeLaserPos[2] = { 453.f, 623.f };

	

		
		eyeLaser.setFillColor(sf::Color::Yellow);

		header.setFillColor(sf::Color::White);
		header.setOutlineColor(sf::Color::Black);
		header.setOutlineThickness(5U);
		header.setCharacterSize(48U);
		header.setPosition({ 802.f, 50.f });
		header.setString("Select Program to Run");
		
		underlineRect.setOutlineColor(sf::Color::Black);
		underlineRect.setFillColor(sf::Color::Transparent);

		underlineRect.setPosition({ header.getPosition().x, header.getPosition().y }); // +56.f
//	});
		underlineRect.setOutlineColor(sf::Color::Transparent);

		options[0].setString("Star Shooter");
		options[1].setString("Crasher Scroller");
		options[2].setString("Exit");

		options[0].setPosition({902.f, 200.f});
		options[1].setPosition({ 902.f, 400.f });
		options[2].setPosition({ 902.f, 600.f });


		for (auto& opt : options)
		{
			opt.setFillColor(sf::Color::White);
			opt.setOutlineColor(sf::Color::Black);
			opt.setOutlineThickness(1U);
			opt.setCharacterSize(36U);
			
		}

		OPT0C = sf::Color::White;
		OPT1C = sf::Color::White;
		OPT2C = sf::Color::White;


		switch (currOpt)
		{
		case 0:
			OPT0C = sf::Color::Yellow;
			face.setPosition({ 800.f, OPT0Y });
			break;
		case 1:
			OPT1C = sf::Color::Yellow;
			face.setPosition({ 800.f, OPT1Y });
			break;
		case 2:
			OPT2C = sf::Color::Yellow;
			face.setPosition({ 800.f, OPT2Y });
			break;
		default:
			break;
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