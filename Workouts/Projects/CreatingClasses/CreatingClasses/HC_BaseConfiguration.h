#pragma once
class HC_BaseConfiguration
{
	short heaterOFFThreshold = 20;
	short heaterONThreshold = 10;
	unsigned short sensorUpperThreshold = 20;
	unsigned short sensorLowerThreshold = 10;
	unsigned short startOverheatTimerAt = 50;
	unsigned short overheatHysteresis = 5;
	unsigned short detectOverheatAfter = 10;
	unsigned short keepHeaterONFor = 60;
	unsigned short keepHeaterOFFFor = 5;

public:

	const short& getHeaterOFFThreshold(void) const { return heaterOFFThreshold; }
	const short& getHeaterONThreshold(void) const { return heaterONThreshold; }
	const unsigned short& getSensorUpperThreshold(void) const { return sensorUpperThreshold; }
	const unsigned short& getSensorLowerThreshold(void) const { return sensorLowerThreshold; }
	const unsigned short& getStartOverheatTimerAt(void) const { return startOverheatTimerAt; }
	const unsigned short& getOverheatHysteresis(void) const { return overheatHysteresis; }
	const unsigned short& getDetectOverheatAfter(void) const { return detectOverheatAfter; }
	const unsigned short& getKeepHeaterONFor(void) const { return keepHeaterONFor; }
	const unsigned short& getKeepHeaterOFFFor(void) const { return keepHeaterOFFFor; }

	void setHeaterOFFThreshold(const short& heaterOFFThreshold) { this->heaterOFFThreshold = heaterOFFThreshold; }
	void setHeaterONThreshold(const short& heaterONThreshold)  { this->heaterONThreshold = heaterONThreshold; }
	void setSensorUpperThreshold(const unsigned short& sensorUpperThreshold)  { this->sensorUpperThreshold = sensorUpperThreshold; }
	void setSensorLowerThreshold(const unsigned short& sensorLowerThreshold)  { this->sensorLowerThreshold = sensorLowerThreshold; }
	void setStartOverheatTimerAt(const unsigned short& startOverheatTimerAt)  { this->startOverheatTimerAt = startOverheatTimerAt; }
	void setOverheatHysteresis(const unsigned short& overheatHysteresis)  { this->overheatHysteresis = overheatHysteresis; }
	void setDetectOverheatAfter(const unsigned short& detectOverheatAfter)  { this->detectOverheatAfter = detectOverheatAfter; }
	void setKeepHeaterONFor(const unsigned short& keepHeaterONFor)  { this->keepHeaterONFor = keepHeaterONFor; }
	void setKeepHeaterOFFFor(const unsigned short& keepHeaterOFFFor)  { this->keepHeaterOFFFor = keepHeaterOFFFor; }

	void Apply(void);
	void setToDefault(void);

	HC_BaseConfiguration();
	~HC_BaseConfiguration();
};

