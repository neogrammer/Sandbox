#include "AnimObject.h"
#include "SandboxError.h"



AnimObject::AnimObject(Cfg::Textures texID_, sf::Vector2f pos_, sf::Vector2f vel_, sf::Vector2f off_, sf::Vector2f size_, sf::IntRect rect_)
	: GameObject{texID_, pos_, vel_, off_, size_, rect_}
{
}

AnimObject::~AnimObject()
{
}

AnimObject::AnimObject(const AnimObject& o)
	: GameObject{(GameObject)o}
{
}

AnimObject& AnimObject::operator=(const AnimObject& o)
{
	// copy all to this

	// TODO: insert return statement here
	return *this;
}

AnimObject::AnimObject(AnimObject&& o) noexcept
	: GameObject{std::move((GameObject)o)}
{
}

AnimObject& AnimObject::operator=(AnimObject&& o) noexcept
{
	// move all to this


	// TODO: insert return statement here
	return *this;
}

void AnimObject::render(sf::RenderWindow& tv_)
{

	GameObject::render(tv_);
}

void AnimObject::update(sf::RenderWindow& tv_, float dt_)
{
	animate(dt_);
	updateBase();
}

void AnimObject::setCurrAnim(AnimType animType_)
{
	mCurrAnim = animType_;
}

void AnimObject::setCurrDir(DirType dir_)
{
	mCurrDir = dir_;
}

void AnimObject::setCurrIndex(uint32_t index_)
{
	mCurrIndex = index_;
}

AnimType AnimObject::getCurrAnimType()
{
	return mCurrAnim;
}

sf::IntRect AnimObject::getCurrRect()
{
	if (mCurrAnim == AnimType::UNKNOWN || mCurrDir == DirType::UNKNOWN)
	{
		std::string str("\nanimType_ passed into Animation::getAnimation() is : ");
		str.append("\ndir_ passed into it is : ");
		throw sbx::SandboxError(str);
	}
	else
	{
		if (mCurrIndex <= 0)
		{
			mCurrIndex = 0;
		}
		else if (mCurrIndex >= mAnimMap[mCurrAnim][mCurrDir].rects.size())
		{
			mCurrIndex = (uint32_t)mAnimMap[mCurrAnim][mCurrDir].rects.size() - (uint32_t)1;
		}

		return mAnimMap[mCurrAnim][mCurrDir].rects[mCurrIndex];
	}
}

Animation& AnimObject::getCurrAnim()
{
	if (mCurrAnim == AnimType::UNKNOWN || mCurrDir == DirType::UNKNOWN)
	{
		std::string str("\nmCurrAnim in Animation::getCurrAnim() is : ");
		str.append("\nmCurrDir passed into it is : ");
		throw sbx::SandboxError(str);
	}
	else
	{
		return mAnimMap[mCurrAnim][mCurrDir];
	}
}

Animation& AnimObject::getAnimation(AnimType animType_, DirType dir_)
{
	if (animType_ == AnimType::UNKNOWN || dir_ == DirType::UNKNOWN)
	{
		std::string str("\nanimType_ passed into Animation::getAnimation() is : ");
		str.append("\ndir_ passed into it is : ");
		throw sbx::SandboxError(str);
	}
	else
	{
		return mAnimMap[animType_][dir_];
	}
}

sf::Vector2f AnimObject::getSizeAt(AnimType animType_, DirType dir_, uint32_t index_)
{
	if (animType_ == AnimType::UNKNOWN || dir_ == DirType::UNKNOWN)
	{
		std::string str("\nanimType_ passed into Animation::getSizeAt() is : ");
		str.append("\ndir_ passed into it is : ");
		throw sbx::SandboxError(str);
	}
	else
	{
		if (index_ <= 0)
		{
			throw sbx::SandboxError("Index in getSizeAt() is less than 0!");
		}
		else if (mCurrIndex >= mAnimMap[animType_][dir_].sizes.size())
		{
			throw sbx::SandboxError("Index in getSizeAt() is greater than the max index allowed for that object!");
		}

		return mAnimMap[animType_][dir_].sizes[index_];
	}
}

sf::Vector2f AnimObject::getOffAt(AnimType animType_, DirType dir_, uint32_t index_)
{
	if (animType_ == AnimType::UNKNOWN || dir_ == DirType::UNKNOWN)
	{
		std::string str("\nanimType_ passed into Animation::getOffAt() is : ");
		str.append("\ndir_ passed into it is : ");
		throw sbx::SandboxError(str);
	}
	else
	{
		if (index_ <= 0)
		{
			throw sbx::SandboxError("Index in getOffAt() is less than 0!");
		}
		else if (mCurrIndex >= mAnimMap[animType_][dir_].offsets.size())
		{
			throw sbx::SandboxError("Index in getOffAt() is greater than the max index allowed for that object!");
		}

		return mAnimMap[animType_][dir_].offsets[index_];
	}
}

sf::IntRect AnimObject::getRectAt(AnimType animType_, DirType dir_, uint32_t index_)
{
	if (animType_ == AnimType::UNKNOWN || dir_ == DirType::UNKNOWN)
	{
		std::string str("\nanimType_ passed into Animation::getRectAt() is : ");
		str.append("\ndir_ passed into it is : ");
		throw sbx::SandboxError(str);
	}
	else
	{
		if (index_ <= 0)
		{
			throw sbx::SandboxError("Index in getRectAt() is less than 0!");
		}
		else if (mCurrIndex >= mAnimMap[animType_][dir_].rects.size())
		{
			throw sbx::SandboxError("Index in getRectAt() is greater than the max index allowed for that object!");
		}

		return mAnimMap[animType_][dir_].rects[index_];
	}
}

Cfg::Textures AnimObject::getTexAt(AnimType animType_, DirType dir_)
{
	if (animType_ == AnimType::UNKNOWN || dir_ == DirType::UNKNOWN)
	{
		std::string str("\nanimType_ passed into Animation::getTexAt() is : ");
		str.append("\ndir_ passed into it is : ");
		throw sbx::SandboxError(str);
	}
	else
	{
		return mAnimMap[animType_][dir_].texID;
	}
}

DirType AnimObject::getCurrDir()
{
	return mCurrDir;
}

uint32_t AnimObject::getCurrIndex()
{
	return mCurrIndex;
}




void AnimObject::updateOff()
{
	if (mCurrAnim == AnimType::UNKNOWN || mCurrDir == DirType::UNKNOWN || mCurrIndex < 0)
	{
		return;
	}
	else
	{
		if (mCurrIndex >= mAnimMap[mCurrAnim][mCurrDir].offsets.size())
		{
			return;
		}
		else
		{
			setOff(mAnimMap[mCurrAnim][mCurrDir].offsets[mCurrIndex]);
		}
	}

}
void AnimObject::updateRect()
{
	if (mCurrAnim == AnimType::UNKNOWN || mCurrDir == DirType::UNKNOWN || mCurrIndex < 0)
	{
		return;
	}
	else
	{
		if (mCurrIndex >= mAnimMap[mCurrAnim][mCurrDir].rects.size())
		{
			return;
		}
		else
		{
			setRect(mAnimMap[mCurrAnim][mCurrDir].rects[mCurrIndex]);
		}
	}
}
void AnimObject::updateSize()
{
	if (mCurrAnim == AnimType::UNKNOWN || mCurrDir == DirType::UNKNOWN || mCurrIndex < 0)
	{
		return;
	}
	else
	{
		if (mCurrIndex >= mAnimMap[mCurrAnim][mCurrDir].sizes.size())
		{
			return;
		}
		else
		{
			setSize(mAnimMap[mCurrAnim][mCurrDir].sizes[mCurrIndex]);
		}
	}
}
void AnimObject::updateTex()
{
	if (mCurrAnim == AnimType::UNKNOWN || mCurrDir == DirType::UNKNOWN)
	{
		return;
	}
	else
	{
		setTexID(mAnimMap[mCurrAnim][mCurrDir].texID);	
	}
}
void AnimObject::updateBase()
{
	updateOff();
	updateRect();
	updateSize();
	updateTex();
}

void AnimObject::animate(float dt_)
{
	if (mCurrAnim == AnimType::UNKNOWN || mCurrDir == DirType::UNKNOWN)
	{
		return;
	}
	
	frameTimeElapsed += dt_;

	if (frameTimeElapsed >= mAnimMap[mCurrAnim][mCurrDir].frameDelay[mCurrIndex])
	{
		frameTimeElapsed = 0.f;

		mCurrIndex++;

		if (loopWaiting)
		{
			if (mAnimMap[mCurrAnim][mCurrDir].loopWaits)
			{
				loopWaitElapsed += dt_;
				if (loopWaitElapsed >= mAnimMap[mCurrAnim][mCurrDir].loopDelay)
				{
					mCurrIndex = 0;
					loopWaitElapsed = 0.f;
					loopWaiting = false;
				}

			}
			else
			{
				loopWaiting = false;
			}
		}

		if (mCurrIndex >= mAnimMap[mCurrAnim][mCurrDir].rects.size())
		{
			if (mAnimMap[mCurrAnim][mCurrDir].loops)
			{
				if (loopWaitElapsed < mAnimMap[mCurrAnim][mCurrDir].loopDelay)
				{
					mCurrIndex = (uint32_t)mAnimMap[mCurrAnim][mCurrDir].rects.size() - (uint32_t)1;
					loopWaiting = true;
				}
				else
				{
					mCurrIndex = 0;
					loopWaitElapsed = 0.f;
					loopWaiting = false;
				}
			}
			else
			{
				loopWaiting = false;
				loopWaitElapsed = 0.f;
				mCurrIndex = (uint32_t)mAnimMap[mCurrAnim][mCurrDir].rects.size() - (uint32_t)1;
			}
		}

	}
}