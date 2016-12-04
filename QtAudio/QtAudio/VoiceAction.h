#pragma once

#include <vector>
#include <string>

using namespace std;

class VoiceAction
{
public:
	VoiceAction(string name, string path, string words);
	string command();
	string getName();
	string getPath();
	std::vector<string> getWords();
private:
	string name;
	string pathToFile;
	bool exe;
	std::vector<string> associateWords;
};

