#include "GameObject.h"
#include "SandboxError.h"

void GameObject::setPos(sf::Vector2f pos_)
{
	mPos = pos_;
}

void GameObject::setOff(sf::Vector2f off_)
{
	mOff = off_;
}

void GameObject::setSize(sf::Vector2f size_)
{
	mSize = size_;
}

void GameObject::setRect(sf::IntRect rect_)
{
	mRect = rect_;
}

void GameObject::setVel(sf::Vector2f vel_)
{
	mVel = vel_;
}

void GameObject::setTexID(Cfg::Textures texID_)
{
	mTexID = texID_;
}

void GameObject::render(sf::RenderWindow& tv_)
{
	if (mVisible && mAlive)
	{
		if (mTexID == Cfg::Textures::UNKNOWN)
		{
			sf::RectangleShape shp{ {64.f, 64.f} };

			if (mSize == sf::Vector2f{ 0.f,0.0f })
				shp.setSize({ 64.f,64.f });
			else
				shp.setSize(mSize);
				
			shp.setFillColor(sf::Color::Green);
			shp.setPosition(mPos - mOff);
			
			tv_.draw(shp);
		}
		else
		{
			setPosition(mPos - mOff);
			setTextureRect(mRect);
			setTexture(Cfg::textures.get(mTexID));

			tv_.draw(*this);
		}
	}
}

void GameObject::update(sf::RenderWindow& tv_, float dt_)
{
}

GameObject::GameObject(Cfg::Textures texID_, sf::Vector2f pos_, sf::Vector2f vel_, sf::Vector2f off_, sf::Vector2f size_, sf::IntRect rect_)
	: sf::Sprite{Cfg::textures.get(texID_)}
	, mTexID{texID_}, mPos{pos_}
	, mVel{vel_}, mOff{off_}
	, mSize{size_}, mRect{rect_}
{
}

	
GameObject::~GameObject()
{
}

GameObject::GameObject(const GameObject& o)
	: sf::Sprite{Cfg::textures.get(o.mTexID)}
	, mTexID{o.mTexID}
	, mPos{o.mPos}
	, mVel{o.mVel}, mOff{o.mOff}
	, mSize{o.mSize}, mRect{o.mRect}
{
	// copy o's fields into this->fields
}

GameObject& GameObject::operator=(const GameObject& o)
{
	// copy o's fields into this->fields
	mTexID = o.mTexID;
	mPos = o.mPos;
	mVel = o.mVel;
	mOff = o.mOff;
	mSize = o.mSize;
	mRect = o.mRect;

	// TODO: insert return statement here
	return *this;
}

GameObject::GameObject(GameObject&& o) noexcept
	: sf::Sprite{ Cfg::textures.get(o.mTexID) }
	, mTexID{std::move(o.mTexID)}
	, mPos{ std::move(o.mPos) }
	, mVel{ std::move(o.mVel) }, mOff{ std::move(o.mOff) }
	, mSize{ std::move(o.mSize) }, mRect{ std::move(o.mRect) }
{
	// move o's fields into this->fields

}

GameObject& GameObject::operator=(GameObject&& o) noexcept
{
	// move o's fields into this->fields
	mTexID = std::move(o.mTexID);
	mPos = std::move(o.mPos);
	mVel = std::move(o.mVel);
	mOff = std::move(o.mOff);
	mSize = std::move(o.mSize);
	mRect = std::move(o.mRect);

	// TODO: insert return statement here
	return *this;
}

bool GameObject::isVisible()
{
	return mVisible;
}

bool GameObject::isAlive()
{
	return mAlive;
}

sf::Vector2f GameObject::getPos()
{
	return mPos;
}

sf::Vector2f GameObject::getOff()
{
	return mOff;
}

sf::Vector2f GameObject::getVel()
{
	return mVel;
}

Cfg::Textures GameObject::getTexID()
{
	return mTexID;
}

sf::IntRect GameObject::getRect()
{
	return mRect;
}

sf::Vector2f GameObject::getSize()
{
	return mSize;
}
