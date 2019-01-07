// timetable.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <ctime>
#include <iostream>
#include <string.h>
#include <chrono>
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <vector>
#include <thread>         // std::this_thread::sleep_for
#include <chrono>         // std::chrono::seconds

#ifdef _WIN32
#include <Windows.h>
#include <Mmsystem.h>
#endif

#pragma comment(lib, "Winmm.lib")

using namespace std;

void displayTimeTable(string x, int y) {
	cout << "topic: " << x << " | " << "Duration: " << y << " min" << endl;
}

//duration included
int inputChecking() {
	int input;
	do {
		cin.clear();
		cin.ignore(10000, '\n');
		cin >> input;
		if (cin.fail())
			cout << "invalid input.Please try again." << endl;
	} while (cin.fail());

	cin.clear();
	cin.ignore(10000, '\n');
	return input;
}

using namespace chrono;
int main()
{
	auto timenow =
		system_clock::to_time_t(system_clock::now());

	//cout << ctime(&timenow) << endl;

	//getting individual topic and its duration
	string topic = "nill";
	int duration = 0;

	//knowing before hand the number of topics one intend to learn
	int numofTopics;

	//storing the topic and the duration of that topic
	vector<string> topicNames;
	vector<int> topicDurations;

	//get the number of topics to learn
	std::cout << "TIMETABLE\n";
	cout << "Number of topics to learn:";
	cin >> numofTopics;

	for (int x = 0; x < numofTopics; x++) {
		cout << "TOPIC " << x + 1 << endl;
		cout << "Input the topic and the duration for learning that topic.\n";
		cout << "Topic: ";
		cin >> topic;
		topicNames.push_back(topic);

		cout << "Duration(mins): ";
		duration = inputChecking();                             //get duration(runs through input checking)
		topicDurations.push_back(duration);

	}

	cout << endl;

	//display the whole list
	for (int x = 0; x < numofTopics; x++) {
		displayTimeTable(topicNames[x], topicDurations[x]);
	}

	cout << endl;


	//shows current subject
	for (int topics = 0; topics < numofTopics; topics++) {
		for (int x = 0; x < numofTopics; x++) {                          //display the whole list
			displayTimeTable(topicNames[x], topicDurations[x]);
		}

		cout << endl;
		cout << "Topic : " << topicNames[topics] << endl;
		cout << "Duration : " << topicDurations[topics] << "min" << endl;
		cout << "press 1 to start.";
		int option = 0;
		for (;;) {
			cin >> option;
			if (option == 1)
				break;
			cout << "invalid input\n";
			cin.clear();
			cin.ignore(10000, '\n');
		}


		cin.clear();
		cin.ignore(10000, '\n');

		//timer
		steady_clock::time_point start = steady_clock::now();
		steady_clock::time_point end = start + minutes(duration);

		for (;;) {
			steady_clock::time_point current = steady_clock::now();
			if (current >= end)
				break;
			this_thread::sleep_for(milliseconds(256));
			cout << "Seconds elapsed: " << (current - start).count() / 1000000000 << '\r' << flush;
		}

		// Can't play sounds on linux
		// also, this should use a relative path
		PlaySound(TEXT("times_up.wav"), NULL, SND_FILENAME);

	}

	cout << "congratulations, you have finished your entire schedule. :)";

	//cout << ctime(&timenow) << endl;

	cout << endl;
}


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
