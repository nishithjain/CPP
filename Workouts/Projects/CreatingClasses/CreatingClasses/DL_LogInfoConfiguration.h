#pragma once
class DL_LogInfoConfiguration
{
	unsigned int embeddedControllerLogLevel = 0;
	unsigned int systemFunctionalityLogLevel = 0;
	unsigned int heaterControlLogicLogLevel = 0;
	bool applyLogLevelConfiguration = false;

public:
	DL_LogInfoConfiguration(void);
	~DL_LogInfoConfiguration(void);

	unsigned int getEmbeddedControllerLogLevel(void) const { return embeddedControllerLogLevel; }
	unsigned int getSystemFunctionalityLogLevel(void) const { return systemFunctionalityLogLevel; }
	unsigned int getHeaterControlLogicLogLevel(void) const { return heaterControlLogicLogLevel; }
	bool getApplyLogLevelConfiguration(void) const { return applyLogLevelConfiguration; }

	void getEmbeddedControllerLogLevel(const int& embeddedControllerLogLevel)  { this->embeddedControllerLogLevel = embeddedControllerLogLevel; }
	void getSystemFunctionalityLogLevel(const int& systemFunctionalityLogLevel) { this->systemFunctionalityLogLevel = systemFunctionalityLogLevel; }
	void getHeaterControlLogicLogLevel(const int& heaterControlLogicLogLevel)  { this->heaterControlLogicLogLevel = heaterControlLogicLogLevel; }
	void getApplyLogLevelConfiguration(const bool& applyLogLevelConfiguration) { this->applyLogLevelConfiguration = applyLogLevelConfiguration; }
};

