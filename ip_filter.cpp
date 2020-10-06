#include <string>
#include <vector>
#include <regex>
#include "ip_filter.h"

std::vector<std::string> split(const std::string &str)
{
    std::vector<std::string> r;
    char d = '\t';
    std::string::size_type start = 0;
    std::string::size_type stop = str.find_first_of(d);
    while(stop != std::string::npos)
    {
        r.push_back(str.substr(start, stop - start));

        start = stop + 1;
        stop = str.find_first_of(d, start);
    }

    r.push_back(str.substr(start));

    return r;
}
std::vector<int> split_ip(const std::string &str)
{
    std::vector<int> r;

    std::string::size_type start = 0;
    std::string::size_type stop = str.find_first_of('.');
    while(stop != std::string::npos)
    {
        r.push_back(stoi(str.substr(start, stop - start)));

        start = stop + 1;
        stop = str.find_first_of('.', start);
    }

    r.push_back(stoi(str.substr(start)));

    return r;
}

<<<<<<< HEAD
ipv4_validate::ipv4_validate(std::string in_str) : ipv4_regex(in_str) {}
=======
ipv4_validate::ipv4_validate(std::string in_str)
                : ipv4_regex(in_str) {}
>>>>>>> ce9d3b210a5d9d45bf63a8117b2216532b57facf

bool ipv4_validate::operator()(const std::string& is_valid)
{
    return regex_match(is_valid, match, ipv4_regex);
}
