#ifndef PLAYER_H__
#define PLAYER_H__
#include "AnimObject.h"
class Player : public AnimObject
{
public:
	using AnimObject::AnimObject;
	virtual ~Player() override;
};

#endif