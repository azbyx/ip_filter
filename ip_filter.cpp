#include <cassert>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <regex>

#include <algorithm>
#include <experimental/iterator>
#include <iterator>

#include <fstream>//remove

// ("",  '.') -> [""]
// ("11", '.') -> ["11"]
// ("..", '.') -> ["", "", ""]
// ("11.", '.') -> ["11", ""]
// (".11", '.') -> ["", "11"]
// ("11.22", '.') -> ["11", "22"]


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

int main(int argc, char const *argv[])
{
    if(argc > 0 && argv[1])
        std::cout << "";
    try
    {
        std::ifstream in_file;//need_remove
        in_file.open("D:\\ip_filter\\ip_filter.tsv");//need_remove

        std::vector<std::vector<int> > ip_pool;
        std::regex ipv4_regex("((25[0-5]|2[0-4]\\d|[01]?\\d\\d?)\\.){3}(25[0-5]|2[0-4]\\d|[1]?\\d\\d?)");
        std::smatch match;

        for(std::string line; std::getline(in_file, line); )//std::cin
        {
            std::vector<std::string> v = split(line);
            //my validate
            if(regex_match(v.at(0), match, ipv4_regex))
            {
                std::vector<int> vec_ip = split_ip(v.at(0));
                ip_pool.push_back(vec_ip);
            }
        }

        in_file.close();//need_remove
        // TODO reverse lexicographically sort
        std::sort(ip_pool.begin(),
                  ip_pool.end(),
                  std::greater<std::vector<int>>());
                  /*[](auto& v1, auto& v2)
                  {

                      return !std::lexicographical_compare(v1.begin(), v1.end(), v2.begin(), v2.end());
                  });*/

        auto printer = [](const auto& cont)
        {
            /*for(auto ip_part = ip.cbegin(); ip_part != ip.cend(); ++ip_part)
            {
                if (ip_part != ip.cbegin())
                    std::cout << ".";

                std::cout << *ip_part;
            }*/
            std::copy(std::begin(cont), std::end(cont), std::experimental::make_ostream_joiner(std::cout, "."));
            std::cout << std::endl;
        };

        for(const auto& ip : ip_pool)
            printer(ip);

        // 222.173.235.246
        // 222.130.177.64
        // 222.82.198.61
        // ...
        // 1.70.44.170
        // 1.29.168.152
        // 1.1.234.8

        // TODO filter by first byte and output
        // ip = filter(1)
        for(const auto& ip : ip_pool)
            if(ip.at(0) == 1)
                printer(ip);

        // 1.231.69.33
        // 1.87.203.225
        // 1.70.44.170
        // 1.29.168.152
        // 1.1.234.8

        // TODO filter by first and second bytes and output
        // ip = filter(46, 70)

        for(const auto& ip : ip_pool)
            if(ip.at(0) == 46 && ip.at(1) == 70)
                printer(ip);

        // 46.70.225.39
        // 46.70.147.26
        // 46.70.113.73
        // 46.70.29.76

        // TODO filter by any byte and output
        // ip = filter_any(46)

        for(const auto& ip : ip_pool)
            if(ip.at(0) == 46 || ip.at(1) == 46|| ip.at(2) == 46|| ip.at(3) == 46)
                printer(ip);

        // 186.204.34.46
        // 186.46.222.194
        // 185.46.87.231
        // 185.46.86.132
        // 185.46.86.131
        // 185.46.86.131
        // 185.46.86.22
        // 185.46.85.204
        // 185.46.85.78
        // 68.46.218.208
        // 46.251.197.23
        // 46.223.254.56
        // 46.223.254.56
        // 46.182.19.219
        // 46.161.63.66
        // 46.161.61.51
        // 46.161.60.92
        // 46.161.60.35
        // 46.161.58.202
        // 46.161.56.241
        // 46.161.56.203
        // 46.161.56.174
        // 46.161.56.106
        // 46.161.56.106
        // 46.101.163.119
        // 46.101.127.145
        // 46.70.225.39
        // 46.70.147.26
        // 46.70.113.73
        // 46.70.29.76
        // 46.55.46.98
        // 46.49.43.85
        // 39.46.86.85
        // 5.189.203.46
    }
    catch(const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
