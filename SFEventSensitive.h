#ifndef SFEVENTSENSITIVE_H__
#define SFEVENTSENSITIVE_H__

#include <optional>
#include <SFML/Window/Event.hpp>

class SFEventSensitive
{
public:
	virtual void handleEvent(std::optional<sf::Event>& evt_) = 0;
};

#endif