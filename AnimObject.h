#ifndef ANIMOBJECT_H__
#define ANIMOBJECT_H__
#include "GameObject.h"
#include <vector>
#include <map>
#include "DirType.h"
#include "AnimType.h"
#include "Animation.h"

class AnimObject : public GameObject
{
	
	
	
	AnimType mCurrAnim{ AnimType::UNKNOWN };
	DirType mCurrDir{ DirType::UNKNOWN };
	uint32_t mCurrIndex{ 0u };

	std::map<AnimType, std::map<DirType, Animation> > mAnimMap;


	void updateOff();
	void updateRect();
	void updateSize();
	void updateTex();
	void updateBase();

	float frameTimeElapsed{ 0.f };
	float loopWaitElapsed{ 0.f };

	bool loopWaiting{ false };

protected:
	
	void animate(float dt_);

public:
	AnimObject(Cfg::Textures texID_ = Cfg::Textures::UNKNOWN, sf::Vector2f pos_ = { 0.f,0.f }, sf::Vector2f vel_ = { 0.f,0.f }, sf::Vector2f off_ = { 0.f,0.f }, sf::Vector2f size_ = { 0.f,0.f }, sf::IntRect rect_ = { {0,0},{0,0} });
	virtual ~AnimObject() override;
	AnimObject(const AnimObject& o);
	AnimObject& operator=(const AnimObject& o);
	AnimObject(AnimObject&& o) noexcept;
	AnimObject& operator=(AnimObject&& o) noexcept;

	virtual void render(sf::RenderWindow& tv_) override;
	virtual void update(sf::RenderWindow& tv_, float dt_) override;

public:

	void setCurrAnim(AnimType animType_);
	void setCurrDir(DirType dir_);
	void setCurrIndex(uint32_t index_);

	AnimType getCurrAnimType();
	DirType getCurrDir();
	uint32_t getCurrIndex();

	sf::IntRect getCurrRect();
	Animation& getCurrAnim();
	Animation& getAnimation(AnimType animType_, DirType dir_);

	sf::Vector2f getSizeAt(AnimType animType_, DirType dir_, uint32_t index_);
	sf::Vector2f getOffAt(AnimType animType_, DirType dir_, uint32_t index_);
	sf::IntRect getRectAt(AnimType animType_, DirType dir_, uint32_t index_);
	Cfg::Textures getTexAt(AnimType animType_, DirType dir_);


};

#endif