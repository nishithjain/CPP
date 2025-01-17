#pragma once

enum class SerialPort
{
	Port1,
	Port2,
};

class SB_BlankScreenBased
{

	bool blankScreen_GasPedalState = false;
	SerialPort serialPortToUse = SerialPort::Port1;
	bool enableMotionDetetion = false;
	unsigned short sensitivity = 50;

public:
	SB_BlankScreenBased();
	~SB_BlankScreenBased();

	bool getBlankScreen_GasPedalState(void) const { return blankScreen_GasPedalState; }
	SerialPort getSerialPortToUse(void) const { return serialPortToUse; }
	bool getEnableMotionDetetion(void) const { return enableMotionDetetion; }
	unsigned short getSensitivity(void) const { return sensitivity; }

	void setBlankScreen_GasPedalState(const bool& blankScreen_GasPedalState){ this->blankScreen_GasPedalState = blankScreen_GasPedalState; }
	void setSerialPortToUse(const SerialPort& serialPortToUse) { this->serialPortToUse = serialPortToUse; }
	void setEnableMotionDetetion(const bool& enableMotionDetetion) { this->enableMotionDetetion = enableMotionDetetion; }
	void setSensitivity(const int& sensitivity)  { this->sensitivity = sensitivity; }

	void apply_SerialPortToUse(void);
};