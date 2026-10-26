#include "heap.h"
#include "gameInfo.h"

/////////////////////// getting data ////////////////////////////// 
// grabbing data from csv and putting it into vectors without extra symbols 
class CSVReader {
public:
	// loading the actual info
	void loadCSV(string fileName, gameData& database);

	//splitting so no extras
	vector<string> split(string text, char delimiter);
};