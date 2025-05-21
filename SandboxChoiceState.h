#ifndef SANDBOXCHOICESTATE_H__
#define SANDBOXCHOICESTATE_H__
#include "GameState.h"
#include "Star.h"
#include "Cfg.h"
#include "GameObject.h"
class SandboxChoiceState : public GameState
{
	float Random(float a, float b)
	{
		return (b - a) * (float(rand()) / float(RAND_MAX)) + a;
	}

	const int starsMax = 1000;

	std::vector<std::unique_ptr<Star>> stars{};
	sf::Vector2f origin;

	sf::Text mainText;

	std::unique_ptr<GameObject> ship;
	
	

public:
	SandboxChoiceState(sf::RenderWindow& tv_) : GameState{ GStateType::SandboxChoice, tv_ } 
		, mainText{Cfg::fonts.get(Cfg::Fonts::SandboxChoiceStateFont)}
		, ship{}
	{
		stars.clear();
		stars.reserve(starsMax);

		for (int i = 0; i < starsMax; i++)
		{
			auto& star = *stars.emplace_back(std::make_unique<Star>());
			star.id = i;
		}

		for (auto& star : stars)
		{

			star->angle = Random(0.f, 2.0f * 3.14159f);
			star->speed = Random(10.f, 100.f);
			star->distance = Random(20.f, 800.f);
			float lum = Random(0.3f, 1.f);
			star->col = sf::Color((uint8_t)(lum * 255.f), (uint8_t)(lum * 255.f), (uint8_t)(lum * 255.f), 255);
		}

		origin = { 1600.f / 2.f, 900.f / 2.f };

		mainText.setCharacterSize(72U);
		mainText.setFillColor(sf::Color::Blue);
		mainText.setOutlineColor(sf::Color::White);
		mainText.setOutlineThickness(3);
		mainText.setPosition({40.f, 20.f});

		ship = std::make_unique<GameObject>(Cfg::Textures::Ship, sf::Vector2f{ 100.f,100.f }, sf::Vector2f{ 0.f,0.f }, sf::Vector2f{ 0.f,0.f }, sf::Vector2f{ 96.f,96.f }, sf::IntRect{ {0,0},{96,96} });
		ship->setOrigin({ 48.f,48.f });


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