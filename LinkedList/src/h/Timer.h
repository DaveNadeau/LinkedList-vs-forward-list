#pragma once
#include<iostream>
#include<ctime>

class Timer {
private:
	std::clock_t begin;
	float duration{};
	const char* processName{};

public:
	Timer() {};
	~Timer() {};

	void start(const char* pName) {
		processName = pName;	//for printing the name of the section of code being timed
		begin = std::clock();  //starts the "stopwatch"
	}

	void stop() {
		duration = (std::clock() - begin); //stops clock
		std::cout <<processName<<" time span: "<< duration << "ms" << std::endl;  //print time lapse
	}

};