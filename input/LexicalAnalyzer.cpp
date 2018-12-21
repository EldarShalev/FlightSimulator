//
// Created by Eldar on 12/20/2018.
//

#include "LexicalAnalyzer.h"

/**
 *
 * @param str whole line of command.
 * @return vector of strings, each declares a word.
 */
vector<string> LexicalAnalyzer::analyze(string input) {
    match_results<std::string::const_iterator> what;
    std::string::const_iterator start = input.begin();
    vector<string> result;
    regex_search(start, input.cend(), what, keywords);
    if (!what[0].matched) {
        if (input != "\r") {
            result.push_back(input);
        }
        return result;
    }

    for (int j = 1; j < what.size(); ++j) {
        if (what[j] != "") {
            if (what[j] != input) {
                vector<string> jres = analyze(Utils::trim(what[j]));
                result.insert(result.end(), jres.begin(), jres.end());
            } else if (find(result.begin(), result.end(), input) != result.end()) {
                // do nothing, I hate C++
            } else if (input != "\r") {
                result.push_back(input);
            }
        }
    }
    return result;
}

LexicalAnalyzer::LexicalAnalyzer() {
    keywords = "(.*)(openDataServer|connect|var|bind|=|heading|while|if|sleep|print|==|>=|<=|<|>|!=|&&|\\|\\||-|\\+|\\*|\\/|\\(|\\)|\\\r)(.*)";
}
