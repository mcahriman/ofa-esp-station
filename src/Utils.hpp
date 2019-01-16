#pragma once

#include <Arduino.h>
#include <list>
#include <map>
#include <utility>

String utils_json_array(std::list<String>);
String utils_json_object(std::list<std::pair<String, String>>);