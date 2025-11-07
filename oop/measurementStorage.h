#pragma once
#include "measurement.h"
#include <vector>
#include <string>

// Class to store and manage multiple measurements
class MeasurementStorage {
private:
	std::vector<Measurement> measurements;

public:
	// Adds a new measurement to the storage
	void addMeasurement(const Measurement& m);
	// Prints all measurements to the console
	void printAll() const;
	// Prints statistics (min, max, average) for a specific sensor
	void printStatistics(const std::string& sensorName) const;
	// Saves all measurements to a file
	void saveToFile(const std::string& filename) const;
	// Loads measurements from a file
	void loadFromFile(const std::string& filename);
};


