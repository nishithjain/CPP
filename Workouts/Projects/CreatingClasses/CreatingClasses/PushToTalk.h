#pragma once
class PushToTalk
{
	bool enablePTT = false;	
	bool internalPTTSpeaker = true; // false means External (PTT) is ON
	bool usePTTExpressPowerPlan = false;

public:
	PushToTalk();
	~PushToTalk();

	bool getEnablePTT(void) const { return enablePTT; }
	bool getInternalPTTSpeaker(void) const { return internalPTTSpeaker; }
	bool getUsePTTExpressPowerPlan(void) const { return usePTTExpressPowerPlan; }

	void setEnablePTT(const bool& enablePTT) { this->enablePTT = enablePTT; }
	void setInternalPTTSpeaker(const bool& internalPTTSpeaker) { this->internalPTTSpeaker = internalPTTSpeaker; }
	void setUsePTTExpressPowerPlan(const bool& usePTTExpressPowerPlan) { this->usePTTExpressPowerPlan = usePTTExpressPowerPlan; }
};

