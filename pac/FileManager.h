#pragma once
#include <string>
#include <iostream>
#include <vector>

#include <fstream>
using namespace std;

class FileManager
{
	string fileName;
	ofstream  file;
	vector<string> stagingChanges;
public:
	void commit(string newCommit) {
		stagingChanges.push_back(newCommit);
	}
	bool write() {
		try{
			if (!file.is_open()) {
				file.open(fileName);
			}
		for (int i = 0; i < stagingChanges.size(); i++)
		{
			file << stagingChanges[i];
		}
		file << "\n";
		}
		catch(...){
			stagingChanges.clear();
			return false;
		}
		stagingChanges.clear();
		return true;
	}
	void setBoard_stepFileName(int i,string FileEncode) {
		string fileName = "../pacman_";
		fileName = fileName + std::to_string(i + 1);
		fileName = fileName + FileEncode;
		file.open(fileName);
	}
	~FileManager() {
		file.close();
	}
	
};

