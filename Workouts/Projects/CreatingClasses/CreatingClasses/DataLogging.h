#pragma once
#include "DL_LogFileMgnt.h"
#include "DL_LogInfoConfiguration.h"
#include "DL_AccelerometerDataLogging.h"


class DataLogging
{
	bool enableDataLogging = false;
	unsigned long logFileSize;
	bool createFile = false;

public:
	DataLogging(void);
	~DataLogging(void);

	DL_LogFileMgnt LogFileManagement;
	DL_LogInfoConfiguration LogInfoConf;
	DL_AccelerometerDataLogging AccelerometerDataLog;

	bool getenableDataLogging(void) const { return enableDataLogging; }
	unsigned long getLogFileSize(void) const { return logFileSize; }
	bool getCreateFile(void) const { return createFile; }

	void setEnableDataLogging(const bool& enableDataLogging) { this->enableDataLogging = enableDataLogging; }
	void setLogFileSize(const int& logFileSize) { this->logFileSize = logFileSize; }
	void setCreateFile(const bool& createFile) { this->createFile = createFile; }
};

