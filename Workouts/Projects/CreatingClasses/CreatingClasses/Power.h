#pragma once
#include "Power_InterfacePowerConfiguration.h"
#include "Power_VehicleIgnitionDetection.h"
#include "Power_ExternalPowerSource.h"

class Power
{

public:
	Power();
	~Power();

	Power_InterfacePowerConfiguration powerConfiguration;
	Power_VehicleIgnitionDetection vehicleIgnitionDetection;
	Power_ExternalPowerSource externalPowerSource;
};