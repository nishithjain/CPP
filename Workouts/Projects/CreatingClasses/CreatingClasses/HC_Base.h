#pragma once
#include "Nullable.h"
#include "HC_BaseConfiguration.h"

enum class RadioButtonColor
{
	OperationalGreen,
	NotOperationalRed,
};

class HC_Base
{
	bool startTest = false;
	RadioButtonColor statusIndicator = RadioButtonColor::NotOperationalRed;
	Nullable<short> temperature;
public:
	HC_BaseConfiguration touchPanelConfiguration;
	
	HC_Base();
	virtual ~HC_Base();
};

