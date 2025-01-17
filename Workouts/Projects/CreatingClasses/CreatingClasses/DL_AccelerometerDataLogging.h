#pragma once
class DL_AccelerometerDataLogging
{
	bool enableAccelerometerDataLogging = false;
	bool enableRawAccelerometerDataLogging = false;
	bool enableX_AxisRawAccelerometerDataLogging = false;
	bool enableY_AxisRawAccelerometerDataLogging = false;
	bool enableZ_AxisRawAccelerometerDataLogging = false;

public:
	DL_AccelerometerDataLogging(void);
	~DL_AccelerometerDataLogging(void);

	bool getEnableAccelerometerDataLogging(void) const { return enableAccelerometerDataLogging; }
	bool getEnableRawAccelerometerDataLogging(void) const { return enableRawAccelerometerDataLogging; }
	bool getEnableX_AxisRawAccelerometerDataLogging(void) const { return enableX_AxisRawAccelerometerDataLogging; }
	bool getEnableY_AxisRawAccelerometerDataLogging(void) const { return enableY_AxisRawAccelerometerDataLogging; }
	bool getEnableZ_AxisRawAccelerometerDataLogging(void) const { return enableZ_AxisRawAccelerometerDataLogging; }

	void setEnableAccelerometerDataLogging(const bool& enableAccelerometerDataLogging) { this->enableAccelerometerDataLogging = enableAccelerometerDataLogging; }
	void setEnableRawAccelerometerDataLogging(const bool& enableRawAccelerometerDataLogging) { this->enableRawAccelerometerDataLogging = enableRawAccelerometerDataLogging; }
	void setEnableX_AxisRawAccelerometerDataLogging(const bool& enableX_AxisRawAccelerometerDataLogging) { this->enableX_AxisRawAccelerometerDataLogging = enableX_AxisRawAccelerometerDataLogging; }
	void setEnableY_AxisRawAccelerometerDataLogging(const bool& enableY_AxisRawAccelerometerDataLogging) { this->enableY_AxisRawAccelerometerDataLogging = enableY_AxisRawAccelerometerDataLogging; }
	void setEnableZ_AxisRawAccelerometerDataLogging(const bool& enableZ_AxisRawAccelerometerDataLogging) { this->enableY_AxisRawAccelerometerDataLogging = enableZ_AxisRawAccelerometerDataLogging; }

};

