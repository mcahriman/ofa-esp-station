/**
 * some trivial jsoning
 */

#include "Utils.hpp"


#define JSON_GLUE ","
#define JSON_KV_SEPARATOR ":"
#define JSON_OBJECT_BEGIN "{"
#define JSON_OBJECT_END "}"
#define JSON_ARRAY_BEGIN "["
#define JSON_ARRAY_END "]"
#define JSON_QUOTE "\""

inline String utils_json_quote(String str)
{
    String ret = "";
    ret += JSON_QUOTE + str + JSON_QUOTE;
    return ret;
}

inline String utils_json_quote_conditional(String str)
{
    if (str.startsWith(JSON_OBJECT_BEGIN) || str.startsWith(JSON_ARRAY_BEGIN))
    {
        return str;
    }
    else
        return utils_json_quote(str);
}

String utils_json_array(std::list<String> parts)
{
    String ret = JSON_ARRAY_BEGIN;
    for (auto iter = parts.begin(); iter != parts.end(); ++iter)
    {
        if (iter != parts.begin()) {
            ret += JSON_GLUE;
        }
        ret += utils_json_quote_conditional(*iter);
    }
    ret+= JSON_ARRAY_END;
    return ret;
}

String utils_json_object(std::list<std::pair<String, String>> dict)
{
    String ret = JSON_OBJECT_BEGIN;
    for (auto iter = dict.begin(); iter != dict.end(); ++iter)
    {
        if (iter != dict.begin())
            ret += JSON_GLUE;
        ret += utils_json_quote(iter->first) + JSON_KV_SEPARATOR + utils_json_quote_conditional(iter->second);
    }
    ret += JSON_OBJECT_END;
    return ret;
}
