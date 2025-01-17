#pragma once

enum class SetVibrationLevel
{
	setNull,
	setDefaultLow,
	setDefaultHigh,
};

enum class SelectWaveform
{
	waveformNumber11,
	waveformNumber25,
};

class HepaticsFeedback
{
	bool enableHepaticsFeedback = false;
	bool enableDedicated = true;
	bool enableDebug = false;
	unsigned short vibrationLevel = 18;
	SetVibrationLevel vibrationLevelParameter = SetVibrationLevel::setNull;
	SelectWaveform waveformSelected = SelectWaveform::waveformNumber25;

public:
	HepaticsFeedback();
	~HepaticsFeedback();

	const bool& getEnableHepaticsFeedback(void) const { return enableHepaticsFeedback; }
	const bool& getEnableDedicated(void) const { return enableDedicated; }
	const bool& getEnableDebug(void) const { return enableDebug; }
	const unsigned short& getVibrationLevel(void) const { return vibrationLevel; }
	const SetVibrationLevel& getVibrationLevelParameter(void) const { return vibrationLevelParameter; }
	const SelectWaveform& getWaveformSelected(void) const { return waveformSelected; }

	void setEnableHepaticsFeedback(const bool& enableHepaticsFeedback) { this->enableHepaticsFeedback = enableHepaticsFeedback; }
	void setEnableDedicated(const bool& enableDedicated) { this->enableDedicated = enableDedicated; }
	void setEnableDebug(const bool& enableDebug) { this->enableDebug = enableDebug; }
	void setVibrationLevel(unsigned short& vibrationLevel) { this->vibrationLevel = vibrationLevel; }
	void setVibrationLevelParameter(const SetVibrationLevel& vibrationLevelParameter) { this->vibrationLevelParameter = vibrationLevelParameter; }
	void setWaveformSelected(const SelectWaveform& waveformSelected) { this->waveformSelected = waveformSelected; }

	void applyHepaticsFeedbackSettings(void);
};

