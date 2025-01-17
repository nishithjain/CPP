#pragma once
#include "SB_BlankScreenBased.h"
#include "SB_DisableUsrInput.h"
#include "SB_WaitForScreenTiming.h"

class ScreenBlanking
{
	bool enableScreenBlanking = false;
	unsigned short automaticallyReEnable = 5;

public:
	ScreenBlanking();
	~ScreenBlanking();

	SB_DisableUsrInput screenBlankingDisableUsrInput;
	SB_BlankScreenBased blankScreenBasedConfiguration;
	SB_WaitForScreenTiming waitForScreenTiming;

	bool getEnableScreenBlanking(void) const  { return enableScreenBlanking; }
	unsigned short getAutomaticallyReEnable(void) const { return automaticallyReEnable; }

	void setEnableScreenBlanking(const bool& enableScreenBlanking) { this->enableScreenBlanking = enableScreenBlanking; }
	void setAutomaticallyReEnable(const int& automaticallyReEnable) { this->automaticallyReEnable = automaticallyReEnable; }
};