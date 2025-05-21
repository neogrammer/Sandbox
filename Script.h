#ifndef SCRIPT_H__
#define SCRIPT_H__

#include "ScriptType.h"	

class Script
{
	ScriptType mType;
public:
	Script(ScriptType type_ = ScriptType::UNKNOWN);

	ScriptType getType();
	void setScriptType(ScriptType type_);
};

#endif