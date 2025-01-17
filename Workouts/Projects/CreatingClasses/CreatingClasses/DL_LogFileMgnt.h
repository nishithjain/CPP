#pragma once
class DL_LogFileMgnt
{
	bool enableCreationOfSpecifiedNumOfLogFiles = false; // if false then Overwrite the log file, OverwriteLog file when 30Mb Limit is exceeded
	unsigned int listOfLogFiles = 5;
public:
	DL_LogFileMgnt(void);
	~DL_LogFileMgnt(void);

	bool getEnableCreationOfSpecifiedNumOfLogFiles(void) const { return enableCreationOfSpecifiedNumOfLogFiles; }
	unsigned int getListOfLogFiles(void) const { return listOfLogFiles; }

	void setEnableCreationOfSpecifiedNumOfLogFiles(const bool& enableCreationOfSpecifiedNumOfLogFiles) { this->enableCreationOfSpecifiedNumOfLogFiles = enableCreationOfSpecifiedNumOfLogFiles; }
	void setListOfLogFiles(const int& listOfLogFiles) { this->listOfLogFiles = listOfLogFiles; }
};

