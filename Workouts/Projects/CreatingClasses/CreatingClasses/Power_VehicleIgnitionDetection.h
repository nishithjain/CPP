#pragma once
class Power_VehicleIgnitionDetection
{
	bool enableVehicleIgnitionDetection = false;
	bool useIgnitionOFFPowerPlan = false;
	bool onWhenIgnitionIsON = false;
	bool offWhenIgnitionIsOFF = false;
	unsigned short delayVehicleIgnitionDetection = 1;

public:
	Power_VehicleIgnitionDetection();
	~Power_VehicleIgnitionDetection();

	bool getEnableVehicleIgnitionDetection(void) const { return enableVehicleIgnitionDetection; }
	bool getUseIgnitionOFFPowerPlan(void) const { return useIgnitionOFFPowerPlan; }
	bool getOnWhenIgnitionIsON(void) const { return onWhenIgnitionIsON; }
	bool getOffWhenIgnitionIsOFF(void) const { return offWhenIgnitionIsOFF; }
	unsigned short getDelayVehicleIgnitionDetection(void) const { return delayVehicleIgnitionDetection; }

	void setEnableVehicleIgnitionDetection(const bool& enableVehicleIgnitionDetection) { this->enableVehicleIgnitionDetection = enableVehicleIgnitionDetection; }
	void setUseIgnitionOFFPowerPlan(const bool& useIgnitionOFFPowerPlan) { this->useIgnitionOFFPowerPlan = useIgnitionOFFPowerPlan; }
	void setOnWhenIgnitionIsON(const bool& onWhenIgnitionIsON) { this->onWhenIgnitionIsON = onWhenIgnitionIsON; }
	void setOffWhenIgnitionIsOFF(const bool& offWhenIgnitionIsOFF){ this->offWhenIgnitionIsOFF = offWhenIgnitionIsOFF; }
	void setDelayVehicleIgnitionDetection(const unsigned short& delayVehicleIgnitionDetection){ this->delayVehicleIgnitionDetection = delayVehicleIgnitionDetection; }
};