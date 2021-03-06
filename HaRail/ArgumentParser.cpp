﻿/* Copyright (C) 2015 haha01haha01

* This Source Code Form is subject to the terms of the Mozilla Public
* License, v. 2.0. If a copy of the MPL was not distributed with this
* file, You can obtain one at http://mozilla.org/MPL/2.0/. */

#include "ArgumentParser.h"

namespace HaRail {
	void ArgumentParser::showHelp()
	{
		cout << "HaRail - Because Israel Railways Suck Dick (TM)" << endl
			<< endl
			<< "Usage: HaRail [options] start_station start_time dest_station" << endl
			<< "  options:" << endl
			<< "    -l\t\tList stations (ignores all other args)" << endl
			<< "    -t\t\tUse test data source (for debugging)" << endl
			<< "    -d <date>\t Specify custom date. If this option is not present, today will be used." << endl
			<< endl
			<< "  examples:" << endl
			<< "    Find route from Modiin to Binyamina, today, starting at 10 o'clock:" << endl
			<< "      HaRail 300 10:00:00 2800" << endl
			<< "    Find the same route, at 22.05.13:" << endl
			<< "      HaRail -d 220513 300 10:00:00 2800" << endl;
	}

	void ArgumentParser::parseArguments()
	{
		for (int i = 1; i < argc; i++) {
			string arg_str(argv[i]);
			if (arg_str == "-l") {
				args_map.emplace("list_stations", "");
			}
			else if (arg_str == "-t") {
				args_map.emplace("test_source", string(argv[++i]));
			}
			else if (arg_str == "-d") {
				args_map.emplace("date", string(argv[++i]));
			}
			else {
				if (!isArgumentExists("start_station")) {
					args_map.emplace("start_station", string(argv[i]));
				}
				else if (!isArgumentExists("start_time")) {
					args_map.emplace("start_time", string(argv[i]));
				}
				else if (!isArgumentExists("dest_station")) {
					args_map.emplace("dest_station", string(argv[i]));
				}
			}
		}
	}
}
