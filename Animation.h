#ifndef ANIMATION_H__
#define ANIMATION_H__

struct Animation
{
	std::vector<sf::IntRect> rects{};
	std::vector<sf::Vector2f> offsets{};
	std::vector<sf::Vector2f> sizes{};
	std::vector<float> frameDelay{};
	float loopDelay{ 0.f };
	Cfg::Textures texID{ Cfg::Textures::UNKNOWN };
	bool playing{ true };
	bool reversed{ false };
	bool loops{ true };
	bool loopWaits{ false };
};


#endif