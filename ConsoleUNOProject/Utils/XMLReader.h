#pragma once

#include <string>
#include <vector>
#include "../Components/GameSettings.h"
#include <unordered_map>

class XMLReader {
public:
    explicit XMLReader(const std::string& filename);

    std::vector<std::string> getCharacterNames();
    std::unordered_map<std::string, std::string> GetCharacterData();

    GameSettings loadGameSettings();
    void saveGameSettings(const GameSettings& settings);

private:
    std::string filename_;
};


