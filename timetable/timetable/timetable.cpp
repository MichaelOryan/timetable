// timetable.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <Windows.h>
#include <Mmsystem.h>
#include <string.h>
#include <ctime>
#include <chrono>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string>
#include <vector>

#pragma comment(lib, "Winmm.lib")

using namespace std;

void displayTimeTable(string x,int y) {
	cout << "topic: "<< x << " | " << "Duration: " << y << " min" << endl;
}

//duration included
int inputChecking() {                                      
	int input;

	do {
		cout << "Duration(mins): ";                              
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

//no duration included
int inputChecking2() {                                      
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
		chrono::system_clock::to_time_t(chrono::system_clock::now());

	cout << ctime(&timenow) << endl;

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
			cout << "TOPIC " << x+1 << endl;
			cout << "Input the topic and the duration for learning that topic.\n";
			cout << "Topic: ";
			cin >> topic;
			topicNames.push_back(topic);
			duration = inputChecking();
			topicDurations.push_back(duration);

		}

		cout << endl;

		//display the whole list
		for (int x = 0; x < numofTopics; x++) {                          
			displayTimeTable(topicNames[x], topicDurations[x]);          
		}

		cout << endl;

		//check if list is correct
		/*
		cout << "is the list and their ordering correct?\n1 = yes, 2 = no\n";
		int option;
		for (;;) {                                                      //makes sure the input is either a 1 or a 2
			cin >> option;
			if (option == 1 || option == 2) {
				break;
			}
			else
			{
				if (cin.fail()) {
					cin.clear();
					cin.ignore(10000, '\n');
				}
				cout << "invalid input please try again\n";
				continue;
			}
		}
		*/
		/*
		if (option == 2) {
			cout << "What would you like to do?\n"
				<< "1 -> add more subjects\n"
				<< "2 -> remove subjects\n"
				<< "3 -> change duration\n"
				<< "4 -> nothing is wrong\n";
			
			option = 0;
			for (;;) {
				option = inputChecking();
				if (option < 1 || option>4)
					continue;
				break;
			}
		}
		*/

		//shows current subject
		for (int topics = 0; topics < numofTopics ; topics++) {
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

				if (cin.fail()) {
					cin.clear();
					cin.ignore(10000, '\n');
				}
				cout << "invalid input\n";
			}

			

			//timer
			steady_clock::time_point start = steady_clock::now();
			steady_clock::time_point end = start + minutes(duration);
			for (;;) {
				steady_clock::time_point current = steady_clock::now();
				if (current == end)
					break;
			}
			PlaySound(TEXT("C:\\Users\\siong\\source\\repos\\timetable\\timetable\\times_up.wav"), NULL, SND_FILENAME);

		}

		cout << "congratulations, you have finished your entire schedule. :)";

		cout << ctime(&timenow) << endl;

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
