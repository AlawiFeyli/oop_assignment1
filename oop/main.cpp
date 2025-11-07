#include <iostream>
#include <limits>
#include <chrono>
#include <ctime>
#include <fstream>
#include <sstream>
#include <iomanip>
#include "sensor.h"
#include "measurement.h"
#include "measurementStorage.h"

// Function to get current timestamp as string
std::string getCurrentTimestamp() {
	auto now = std::chrono::system_clock::now();
	std::time_t now_c = std::chrono::system_clock::to_time_t(now);

	std::tm tm_struct;
	localtime_s(&tm_struct, &now_c);
	std::stringstream ss;
	ss << std::put_time(&tm_struct, "%Y-%m-%d %H:%M");
	return ss.str();
}

// Menu display function
void showMenu() {
	std::cout << "\n--- MENU ---\n";
	std::cout << "1. Add Measurement\n";
	std::cout << "2. Show statistics for a Sensor\n";
	std::cout << "3. Show all Measurements\n";
	std::cout << "4. Save Measurements to File\n";
	std::cout << "5. Load Measurements from File\n";
	std::cout << "6. Exit\n";
	std::cout << "Choose an option: ";
}


int main() {
	// Create sensors and storage
	Sensor tempSensor("t1", "*C", 18.0, 24.0);
	Sensor humiditySensor("h1", "%", 30.0, 60.0);
	MeasurementStorage storage;

	int choice;
	do {
		showMenu();
		std::cin >> choice;

		if (std::cin.fail()) {
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Invalid input. Please enter a number between 1 and 6.\n";
			continue;
		}

		switch (choice) {
		case 1: {
			storage.addMeasurement({ tempSensor.getName(), tempSensor.getUnit(), tempSensor.read(), getCurrentTimestamp() });
			storage.addMeasurement({ humiditySensor.getName(), humiditySensor.getUnit(), humiditySensor.read(), getCurrentTimestamp() });
			std::cout << "Measurements added.\n";
			break;
		}
		case 2: {
			std::string sensor;
			std::cout << "t = Temperature sensor\n" << "h = Humidity sensor\n" << "Enter sensor (t/h1-3): ";
			std::cin.ignore();
			std::getline(std::cin, sensor);
			storage.printStatistics(sensor);
			break;
		}
		case 3:
			storage.printAll();
			break;

		case 4:
			storage.saveToFile("data.txt");
			break;

		case 5:
			storage.loadFromFile("data.txt");
			break;

		case 6:
			std::cout << "Exiting program.\n";
			break;
		defualt:
			std::cout << "Invalid choice. Please select a number between 1 and 6.\n";
		}
	} while (choice != 6);

	return 0;
}