#include "Script.h"

Script::Script(ScriptType type_)
	: mType{type_}
{
}

ScriptType Script::getType()
{
	return mType;
}

void Script::setScriptType(ScriptType type_)
{
	mType = type_;
}
