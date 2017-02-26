#pragma once

#include "json.h"
namespace mq
{

class jparser
{
public:
    static json parse(const std::string& s, std::string& err) noexcept;
    static json parse(const std::string& s) noexcept;
private:
    jparser(const std::string& s);
    json parse_value_nonrecur();

    json parse_value();
    json parse_boolean();
    std::string parse_string();
    json parse_object();
    json parse_null();
    json parse_array();
    json parse_number();

    std::string parse_utf16_escape_sequence();
    void skip_space();
    const char* s;
    const char* p;
};

}