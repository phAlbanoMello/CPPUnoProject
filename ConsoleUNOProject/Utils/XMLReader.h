#pragma once

#include <string>
#include <vector>

class XMLReader {
public:
    explicit XMLReader(const std::string& filename);

    std::vector<std::string> getCharacterNames();

private:
    std::string filename_;
};


