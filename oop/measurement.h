#pragma once
#include <string>

// Structure to hold a measurement from a sensor
struct Measurement {
	std::string sensorName;
	std::string unit;
	double value;
	std::string timestamp;
};
