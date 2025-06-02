#include "Scripted.h"
#include "SandboxError.h"

void Scripted::addScript(Script&& scr_)
{
	if (mScripts.size() == 0)
	{
		mCurrScript = &mScripts.emplace_back(scr_.getType());
		mCurrIndex = 0;
	}
	else
	{
		int tempIndex{ -1 };
		for (int i = 0; i < mScripts.size(); i++)
		{
			if (&mScripts[i] == mCurrScript)
			{
				tempIndex = i;
				break;
			}
		}
		if (tempIndex == -1)
		{
			sbx::SandboxError("CurrScript does not point to anything in the scripts vector!");
		}
		else
		{	
			mScripts.emplace_back(Script(scr_.getType()));
			mCurrIndex = tempIndex;
			mCurrScript = &mScripts[mCurrIndex];
		}
	}
	if (mCurrIndex == -1)
	{
		sbx::SandboxError("The current script index in Scripted class is -1 for some odd reason, which makes no sense so im crashing your shit");
	}
}

void Scripted::setScriptToNext()
{
	if (++mCurrIndex >= mScripts.size() && mScripts.size() > 0)
	{
		// loop around
		mCurrIndex = 0;
	}
	
	mCurrScript = &mScripts[mCurrIndex];

}

void Scripted::setScriptToPrevious()
{
	if (--mCurrIndex < 0 && mScripts.size() > 0)
	{
		// loop around
		mCurrIndex = (int)(mScripts.size() - 1);
	}
	else
	{
		if (mScripts.empty())
			sbx::SandboxError("Trying to set script to previous script, without any scripts to work with whatsoever.  fix that.");
		if (mCurrIndex >= mScripts.size())
			sbx::SandboxError("Mismatch in currindex expected from scripts, and currindex trying to reach, outside the vector space");
	}

	mCurrScript = &mScripts[mCurrIndex];

}

void Scripted::setScriptToIndex(int index_)
{
	if (index_ > 0 && mScripts.size() > 0 && index_ < mScripts.size())
	{
		mCurrScript = &mScripts[index_];
		mCurrIndex = index_;
	}
}

void Scripted::setScriptToType(ScriptType type_)
{
	int tempIndex{ -1 };
	for (int i = 0; i < mScripts.size(); i++)
	{
		if (mScripts[i].getType() == type_)
		{
			tempIndex = i;
			break;
		}
	}
	if (tempIndex == -1) return;
	else
	{
		mCurrIndex = tempIndex;
		mCurrScript = &mScripts[mCurrIndex];
	}

}


