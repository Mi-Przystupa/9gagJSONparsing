// 9gagJSONparsing.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <json/json.h>
#include "PermutationGenerator.h"
using namespace std;


int _tmain(int argc, _TCHAR* argv[])
{
	std::ifstream ifile("data.json");
	Json::Reader reader;
	Json::Value root;
	if (reader.parse(ifile, root)) {
		// write in a nice readible way
		Json::StyledWriter styledWriter;
		Json::Value gags = root["gags"];

		PermutationGenerator p(gags[0]["title"].toStyledString());
		// End game for this:
		// Split up the title for each entry in data.json
		// for each entry:
			//Split up title into array of string
			//create thread to create map of each possible combination of words
			//In global table, check if word/ phrase used, if so add to it
				//else, create new table entry and make initial entry = 1
		// The hope is that by using multiple threads, I can let the program
		// Deal with the factorial time to form each possible combination of the title
		//words on different threads, then (the bottle neck) will be just adding to this
		//Global table
		// Some potential issues I can see are the following
		//one.) I'm wrong and multi-threading won't help me
		//two.) for a title of n characters there are n! combinations,
		//the memory usage in worse case with k examples is n!k, which is huge
		//Probably a good idea to prune along the way???

		cout << styledWriter.write(gags[0]["title"]) << endl;

	}
	else{
		cout << "failure" << endl;
	}

	//bool parsingSuccessful = reader.parse()
	int x = 0;
	std::cin >> x;
	
	return 0;
}

