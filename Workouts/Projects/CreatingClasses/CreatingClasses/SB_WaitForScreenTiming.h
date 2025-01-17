#pragma once
class SB_WaitForScreenTiming
{
	unsigned int WaitForMsBeforeScreenIsOFF = 500;
	unsigned int WaitForMsToTurnScreenON = 500;

public:
	SB_WaitForScreenTiming();
	~SB_WaitForScreenTiming();

	unsigned int getWaitForMsBeforeScreenIsOFF(void) const { return WaitForMsBeforeScreenIsOFF; }
	unsigned int getWaitForMsToTurnScreenON(void) const { return WaitForMsToTurnScreenON; }
	
	void setWaitForMsBeforeScreenIsOFF(const int& WaitForMsBeforeScreenIsOFF) { this->WaitForMsBeforeScreenIsOFF = WaitForMsBeforeScreenIsOFF; }
	void setWaitForMsToTurnScreenON(const int& WaitForMsToTurnScreenON) { this->WaitForMsToTurnScreenON = WaitForMsToTurnScreenON; }
};

