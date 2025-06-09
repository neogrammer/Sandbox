
// BackgroundLayer.cpp
#include "BackgroundLayer.h"
#include "SandboxError.h"


void BackgroundLayer::checkBoundary()
{
	if (movingLeft)
	{
		if (layerView.getCenter().x - 800.f < -1.f * mainSpr.getTexture().getSize().x)
		{
			auto gap = ((-1.f * mainSpr.getTexture().getSize().x) - (layerView.getCenter().x - 800.f));
			layerView.setCenter({ 800.f - gap, 450.f });
		}
	}
	else if (movingRight)
	{
		if (layerView.getCenter().x + 800.f >= mainSpr.getTexture().getSize().x)
		{
			auto gap = ((layerView.getCenter().x + 800.f) - (mainSpr.getTexture().getSize().x));
			layerView.setCenter({ -800.f + gap, 450.f });
		}
	}
}

BackgroundLayer::BackgroundLayer(sf::RenderWindow& window_, Cfg::Textures tex_, float scrollModifier_)
	: mainSpr{ Cfg::textures.get(tex_) }, secondarySpr{Cfg::textures.get(tex_)}
	, layerView{ window_.getDefaultView() }
	, scrollModifier{scrollModifier_}
{
	mainSpr.setPosition({ 0.f,0.f });
	secondarySpr.setPosition({ -1.f * mainSpr.getTexture().getSize().x, 0.f });
	layerView.setCenter({ 800.f, 450.f });
}

void BackgroundLayer::update(float dt)
{
	
}



void BackgroundLayer::draw(sf::RenderWindow& window) 
{
	checkBoundary();

	window.setView(layerView);
	window.draw(secondarySpr);
	window.draw(mainSpr);
}

void BackgroundLayer::move(sf::Vector2f disp_, float dt_)
{
	if (disp_.x > 0.f)
	{
		movingRight = true;
		movingLeft = false;
	}
	else if (disp_.x < 0.f)
	{
		movingLeft = true;
		movingRight = false;
	}
	else
	{
		movingLeft = false;
		movingRight = false;
	}
	layerView.move((disp_ * scrollModifier) * dt_);
}


