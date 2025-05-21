#ifndef GAMEOBJECT_H__
#define GAMEOBJECT_H__
#include <SFML/Graphics.hpp>
#include "Cfg.h"
#include <iostream>
class GameObject : public sf::Sprite
{
	float maxVel{ 400.f };
	float minVel{ -400.f };

	Cfg::Textures mTexID;

	sf::Vector2f mPos;
	sf::Vector2f mVel{ 0.f,0.f };

	sf::Vector2f mOff;
	sf::Vector2f mSize;
	sf::IntRect mRect;

	bool mVisible{ true };
	bool mAlive{ true };

	//void draw(sf::RenderTarget& target, sf::RenderStates states) const override final;

protected:

	/// <summary>
	/// Force Applied, the magnitude
	/// </summary>
	float mForceMag{ 0.f };

	float mMass{ 70.f };

	/// <summary>
	/// Keep normalized, stores the direction of the force applied
	/// </summary>
	sf::Vector2f mForceDir{ 1.f,0.f };

	sf::Vector2f mAccel{ 0.f,0.f };

	sf::Vector2f mPrevPos{0.f,0.f};
	sf::Vector2f mPrevVel{0.f,0.f};


	void setOff(sf::Vector2f off_);
	void setSize(sf::Vector2f size_);
	void setRect(sf::IntRect rect_);
	void setTexID(Cfg::Textures tex_);

public:
	float getMass() { return mMass; }

	void tickBegin() { mForceMag = 0.f; }

	void applyForce(float force_, sf::Vector2f dir_)
	{
		auto combined = sf::Vector2f{ mForceMag * mForceDir.x, mForceMag * mForceDir.y } + sf::Vector2f{ force_ * dir_.x, force_ * dir_.y };
		if (combined.x == 0.f && combined.y == 0.f)
		{
			//mForceMag = 0.f;
		}
		else
		{
			mForceMag = combined.length();

			mForceDir = combined.normalized();
		}
	}

	void tickEnd(float dt_)
	{
		mAccel = { (mForceMag / mMass) * mForceDir.x, (mForceMag / mMass) * mForceDir.y };
		sf::Vector2f tmpVel = { mVel.x + (mAccel.x * dt_), mVel.y + (mAccel.y * dt_) };
		// keep in range
		if (tmpVel.x > maxVel)
		{
			tmpVel.x = maxVel;
		}
		if (tmpVel.y > maxVel)
		{
			tmpVel.y = maxVel;
		}


		if (tmpVel.x < minVel)
		{
			tmpVel.x = minVel;
		}
		if (tmpVel.y < minVel)
		{
			tmpVel.y = minVel;
		}

		//if (fabsf(mVel.x) < 0.001f) mVel.x = 0.0f;
		//if (fabsf(mVel.y) < 0.001f) mVel.y = 0.0f;
		


		sf::Vector2f pt = { mPos.x + ((tmpVel.x * dt_) + (0.5f * mAccel.x * (dt_ * dt_))), mPos.y + ((tmpVel.y * dt_) + (0.5f * mAccel.y * (dt_ * dt_))) };
		mPrevPos = mPos;
		mPos = pt;
		mPrevVel = mVel;
		mVel = tmpVel;

		
		std::cout << "\npos:" << mPos.x << "," << mPos.y;

		std::cout << "\nvel:" << mVel.x << "," << mVel.y;

		std::cout << "\nacc:" << mAccel.x << "," << mAccel.y << std::endl;


		
		//setPos(mPos);

		//this->setPosition(mPos - mOff);

	}

	void setPos(sf::Vector2f pos_);
	void setVel(sf::Vector2f vel_);

	virtual void render(sf::RenderWindow& tv_);
	virtual void update(sf::RenderWindow& tv_, float dt_);

public:
	GameObject(Cfg::Textures texID_ = Cfg::Textures::UNKNOWN, sf::Vector2f pos_ = { 0.f,0.f }, sf::Vector2f vel_ = { 0.f,0.f }, sf::Vector2f off_ = { 0.f,0.f }, sf::Vector2f size_ = { 0.f,0.f }, sf::IntRect rect_ = { {0,0},{0,0} });
	virtual ~GameObject();
	GameObject(const GameObject& o);
	GameObject& operator=(const GameObject& o);
	GameObject(GameObject&& o) noexcept;
	GameObject& operator=(GameObject&& o) noexcept;

public:
	bool isVisible();
	bool isAlive();
	virtual sf::Vector2f getPos();
	virtual sf::Vector2f getOff();
	virtual sf::Vector2f getVel();
	virtual Cfg::Textures getTexID();
	virtual sf::IntRect getRect();
	virtual sf::Vector2f getSize();


};

#endif