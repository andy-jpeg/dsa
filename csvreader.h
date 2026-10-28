#ifndef DSA_CSVREADER_H
#define DSA_CSVREADER_H

// my includes:
#include <vector>
#include <string>
#include "gameData.h"

// namespace <3
using namespace std;

/////////////////////// getting data ////////////////////////////// 
// grabbing data from csv and putting it into vectors without extra symbols 
class CSVReader {
public:
	// loading the actual info, returns how many games loaded
	int loadCSV(string fileName, gameData& database);

	// splitting a csv line into columns (commas in quotes dont count)
	vector<string> splitLine(string line);

	//splitting so no extras
	vector<string> split(string text, char delimiter);
};


#endif //DSA_CSVREADER_H
