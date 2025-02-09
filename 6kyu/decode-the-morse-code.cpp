#include <sstream>
#include <string>
#include <unordered_map>
#include <vector>

std::string decodeMorse(const std::string& morse_code) {
    std::unordered_map<std::string_view, std::string_view> codes
        = {{".-", "A"},    {"-...", "B"}, {"-.-.", "C"},        {"-..", "D"},
           {".", "E"},     {"..-.", "F"}, {"--.", "G"},         {"....", "H"},
           {"..", "I"},    {".---", "J"}, {"-.-", "K"},         {".-..", "L"},
           {"--", "M"},    {"-.", "N"},   {"---", "O"},         {".--.", "P"},
           {"--.-", "Q"},  {".-.", "R"},  {"...", "S"},         {"-", "T"},
           {"..-", "U"},   {"...-", "V"}, {".--", "W"},         {"-..-", "X"},
           {"-.--", "Y"},  {"--..", "Z"}, {"...---...", "SOS"}, {"-.-.--", "!"},
           {".-.-.-", "."}};

    std::vector<std::string> words;
    size_t start = 0;
    size_t end;
    const std::string_view words_delimiter = "   ";

    while ((end = morse_code.find(words_delimiter, start)) != std::string::npos
    ) {
        words.push_back(morse_code.substr(start, end - start));
        start = end + words_delimiter.length();
    }
    words.push_back(morse_code.substr(start)); // Last

    std::string result;

    for (std::string& word : words) {
        std::stringstream ss(word);
        std::string morse_char;
        while (ss >> morse_char)
            result += codes[morse_char];

        result.push_back(' ');
    }

    // Remove leading spaces
    result.erase(
        result.begin(),
        std::find_if(
            result.begin(),
            result.end(),
            [](char ch) { return std::isspace(ch) == 0; }
        )
    );

    // Remove trailing spaces
    result.erase(
        std::find_if(
            result.rbegin(),
            result.rend(),
            [](char ch) { return std::isspace(ch) == 0; }
        ).base(),
        result.end()
    );

    return result;
}
