#include <iostream>
#include <iterator> // solution 1_1
#include <vector>   //
#include <string_view>  // solution 4
#include <regex>   // solution 9
//#include <boost/algorithm/string.hpp> // solution 2
/**
 * SO, HOW DO I SPLIT MY STRING? ( https://www.fluentcpp.com/2017/04/21/how-to-split-a-string-in-c/ )
 *
 * If you have access to boost( https://www.boost.org/ ), then by all means do Solution 2.
 * Or you can consider rolling out your own algorithm that, like boost, split strings based on find_if.
 *
 * If you don’t want to do this, you can do Solution 1.1 which is standard, unless you need a specific delimiter or
 * you’ve been proven this is a bottleneck, in which case Solution 1.3 is for you.
 *
 * And when you have access to ranges (C++20, maybe, https://www.fluentcpp.com/2017/01/12/ranges-stl-to-the-next-level/),
 * Solution 3 should be the way to go.
 */
using namespace std;

std::vector<std::string> solution1_1(const std::string& text) { // Using iterators
    // + uses standard components only,
    // + works on any stream, not just strings.
    // - it can’t split on anything else than white-spaces, which can be an issue, like for parsing a CSV,
    // - it can be improved in terms of performance (but until your profiling hasn’t proved this is your bottleneck, this is not a real issue),
    std::istringstream iss(text);
    return std::vector<std::string>(std::istream_iterator<std::string>{iss},
                                    std::istream_iterator<std::string>());
}

std::vector<std::string> solution1_3(const std::string& text, char delimiter) { // stepping away from the iterators
    // + works on any delimiter
    // + the delimiter can be specified at runtime
    // + easy to re-use
    // - not standard,
    std::istringstream tokenStream(text);
    std::string token;
    std::vector<std::string> tokens;
    while (std::getline(tokenStream, token, delimiter))
    {
        tokens.push_back(token);
    }
    return tokens;
}

std::vector<std::string> solution2(const std::string& text, char delimiter) { // Using boost::split
    // This solution is superior to the previous ones (unless you need it to work on any stream)
    // + allows any delimiter, even several different ones
    // + 60% faster than solution 1.1
    // - does not work on any stream
    // - needs access to boost
    // - the interface does not output its results via its return type
    std::vector<std::string> results;
//    boost::split(results, text, [](char c){return c == delimiter;});
    return results;
}

/*std::vector<std::string> solution3(const std::string& text, char regexDelimiter) { // Using ranges
    return text | view::split(regexDelimiter) | ranges::to<std::vector<std::string>>();
}*/

template<typename S = string_view>
inline auto solution4(string_view str, bool trim = true, string_view delimit = ",") { // Using string_view
    // provided by jft through his comment on the fluentcpp page : http://coliru.stacked-crooked.com/a/b5c7c95695b9d426
    // deemed to be 2-3 times faster than solution 1.3
    // requires C++ 17
    vector<S> vsv;
    for (size_t l = 0, d = 0; d != string_view::npos; l = d + 1) {
        auto st = str.data() + l;
        auto ln = (((d = str.find_first_of(delimit, l)) != string_view::npos) ? d : str.size()) - l;

        if (trim) {
            for (; (ln > 0) && isspace(*st); ++st, --ln);
            for (auto se = st + ln - 1; (ln > 0) && isspace(*se); --se, --ln);
        }
        vsv.emplace_back(st, ln);
    }
    return vsv;
}

std::vector<std::string> solution9(const std::string& text, const string& regexDelimiter = "[ ,.]+") { // Using regex, very slow
    // -  very slow compared to other solutions, to proscribe
    std::regex delimiter (regexDelimiter);
    std::sregex_token_iterator token(text.cbegin(), text.cend(), delimiter, -1);
    std::sregex_token_iterator end;
    std::vector<std::string> results;
    for(; token != end; ++token){
        results.push_back(*token);
    }
    return results;
}
template <typename T>
void displayVector(const std::vector<T> vector) {
    for (const auto& it : vector) {
        cout << it << " ; ";
    }
    cout << endl;
}

int main() {

    displayVector(solution1_1("Let me split this into words"));

    displayVector(solution1_3("01111111111111111111111111111111", '1'));

    displayVector(solution1_3("Let me split this into words", ' '));

    displayVector(solution9("Let me split this into words", "[e]+"));

    displayVector(solution4("Let me split this into words", true, " "));

    return 0;
}
