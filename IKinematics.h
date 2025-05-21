#ifndef IKINEMATICS_H__
#define IKINEMATICS_H__
#include <SFML/System/Vector2.hpp>

class IKinematics
{

protected:
	/// <summary>
	/// Force Applied, the magnitude
	/// </summary>
	float mForceMag{ 0.f };
	
	/// <summary>
	/// Keep normalized, stores the direction of the force applied
	/// </summary>
	sf::Vector2f mForceDir{ 0.f,0.f };

	sf::Vector2f mAccel{ 0.f,0.f };

public:

	void callStartOfFrame() { mForceMag = 0.f; }

	void applyForce(float force_, sf::Vector2f dir_)
	{
		auto combined = sf::Vector2f{ mForceMag * mForceDir.x, mForceMag * mForceDir.y } + sf::Vector2f{ force_ * dir_.x, force_ * dir_.y };
		mForceMag = combined.length();
		mForceDir = combined.normalized();
	}

	void tickAccumForce()

};

#endif