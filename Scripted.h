#ifndef SCRIPTED_H__
#define SCRIPTED_H__
#include <vector>
#include "Script.h"


class Scripted
{
	std::vector<Script> mScripts;

	// non-owning, when adding new scripts, get currScript index and then add, then set currScript back to that index, in case the structure moves;
	Script* mCurrScript;
	int mCurrIndex{ -1 };

public:
	virtual void executeScript() = 0;
	void addScript(Script&& scr_);
	void setScriptToNext();
	void setScriptToPrevious();
	void setScriptToIndex(int index_);
	void setScriptToType(ScriptType type_);
};

#endif