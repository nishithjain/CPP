#pragma once
class Power_InterfacePowerConfiguration
{
	// Interface Power Configuration
	bool enablePowerOnUSBPort_1 = false;
	bool enablePowerOnUSBPort_2 = false;
	bool enablePowerOnSerialPort_1 = false;
	bool enablePowerOnSerialPort_2 = false;
	bool enableUSBPlusPower = false;
public:
	Power_InterfacePowerConfiguration();
	~Power_InterfacePowerConfiguration();

	bool getEnablePowerOnUSBPort_1(void) const { return enablePowerOnUSBPort_1; }
	bool getEnablePowerOnUSBPort_2(void) const { return enablePowerOnUSBPort_2; }
	bool getEnablePowerOnSerialPort_1(void) const { return enablePowerOnSerialPort_1; }
	bool getEnablePowerOnSerialPort_2(void) const { return enablePowerOnSerialPort_2; }
	bool getEnableUSBPlusPower(void) const { return enableUSBPlusPower; }

	void setEnablePowerOnUSBPort_1(const bool& enablePowerOnUSBPort_1)	{ this->enablePowerOnUSBPort_1 = enablePowerOnUSBPort_1; }
	void setEnablePowerOnUSBPort_2(const bool& enablePowerOnUSBPort_2) { this->enablePowerOnUSBPort_2 = enablePowerOnUSBPort_2; }
	void setEnablePowerOnSerialPort_1(const bool& enablePowerOnSerialPort_1) { this->enablePowerOnSerialPort_1 = enablePowerOnSerialPort_1; };
	void setEnablePowerOnSerialPort_2(const bool& enablePowerOnSerialPort_2) { this->enablePowerOnSerialPort_2 = enablePowerOnSerialPort_2; }
	void setEnableUSBPlusPower(const bool& enableUSBPlusPower) { this->enableUSBPlusPower = enableUSBPlusPower; }
};
