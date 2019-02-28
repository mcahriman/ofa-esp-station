#pragma once

#include <string>
#include <list>
#include <map>
#include <utility>

using namespace std;

string utils_json_array(std::list<string>);
string utils_json_object(std::list<std::pair<string, string>>);