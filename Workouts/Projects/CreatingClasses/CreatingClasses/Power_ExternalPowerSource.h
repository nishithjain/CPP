#pragma once
class Power_ExternalPowerSource
{
	bool onWhenConnected = false;
	bool offWhenDisconnected = false;
	unsigned short delayOnWhenConnected = 5;
	unsigned int delayOffWhenDisconnected = 1000;
public:
	Power_ExternalPowerSource();
	~Power_ExternalPowerSource();

	bool getOnWhenConnected(void) const { return onWhenConnected; }
	bool getOffWhenDisconnected(void) const { return offWhenDisconnected; }
	unsigned short getDelayOnWhenConnected(void) const { return delayOnWhenConnected; }
	unsigned int getDelayOffWhenDisconnected(void) const { return delayOffWhenDisconnected; }

	void setOnWhenConnected(const bool& onWhenConnected){ this->onWhenConnected = onWhenConnected; }
	void setOffWhenDisconnected(const bool& offWhenDisconnected){ this->offWhenDisconnected = offWhenDisconnected; }
	void setDelayOnWhenConnected(const unsigned short& delayOnWhenConnected) { this->delayOnWhenConnected = delayOnWhenConnected; }
	void setDelayOffWhenDisconnected(const unsigned int& delayOffWhenDisconnected){ this->delayOffWhenDisconnected = delayOffWhenDisconnected; }
};

