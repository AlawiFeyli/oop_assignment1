# oop_assignment1

# GitHub repo: https://github.com/AlawiFeyli/oop_assignment1

# Project Description:
This project is an individual assignment in object-oriented programming (OOP) using C++. The program simulates a simple IoT-like system with multiple sensors that generate measurement data, store it, analyze statistics, and handle file input/output through a terminal-based menu interface.

# Features:
Management of multiple sensors with different units and value ranges
Simulation of sensor readings via a read() method
Structured storage of measurement data using a Measurement struct
Per-sensor statistics: count, average, min/max, standard deviation
Timestamps generated using the system clock
File handling: 
Save/load measurements in text format
Interactive terminal menu for user control

# File Structure:
oop_assignment1/
├── main.cpp
├── sensor.h / sensor.cpp
├── measurement.h
├── measurementStorage.h / measurementStorage.cpp
├── README.md
├── .gitignore
