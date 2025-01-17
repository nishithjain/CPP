#pragma once
#include "Nullable.h"

enum class Minutes : unsigned char
{
	zero,
	One,
	Two,
	Three,
	Four,
	Five,
};

class HC_Settings
{
	Minutes maintainHeatingInSleepModeFor = Minutes::One;
	Nullable<short> internalTemperature;
	Nullable<short> ambientTemperature;
	bool displayTemperatureInCelsius = true; // False means Fahrenheit = true 

public:
	HC_Settings();
	~HC_Settings();

	auto getMaintainHeatingInSleepModeFor(void) const -> const Minutes&
	{ return maintainHeatingInSleepModeFor; }
	auto getInternalTemperature(void) const -> const Nullable<short>
	{ return internalTemperature; }
	auto getAmbientTemperature(void) const -> const Nullable<short> 
	{ return ambientTemperature; }
	auto getDisplayTemperatureInCelsius(void) const -> const bool& 
	{ return displayTemperatureInCelsius; }

	auto getMaintainHeatingInSleepModeFor(const Minutes& maintainHeatingInSleepModeFor) -> void
	{ this->maintainHeatingInSleepModeFor = maintainHeatingInSleepModeFor; }
	auto getInternalTemperature(const Nullable<short>& internalTemperature) -> void
	{ this->internalTemperature = internalTemperature; }
	auto getAmbientTemperature(const Nullable<short>& ambientTemperature) -> void
	{ this->ambientTemperature = ambientTemperature; }
	auto getDisplayTemperatureInCelsius(const bool&) -> void
	{ this->displayTemperatureInCelsius = displayTemperatureInCelsius; }
};