#include "XMLReader.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <conio.h>

XMLReader::XMLReader(const std::string& filename) : filename_(filename) {}

std::vector<std::string> XMLReader::getCharacterNames() {
    std::vector<std::string> characterNames;

    // Open the XML file
    std::ifstream xmlFile(filename_);
    if (!xmlFile.is_open()) {
        std::cerr << "Error opening XML file." << std::endl;
        return characterNames;
    }

    // Read the XML content into a string
    std::stringstream buffer;
    buffer << xmlFile.rdbuf();
    std::string xmlContent = buffer.str();

    // Find and extract character names
    size_t currentPosition = 0;
    const std::string characterTagStart = "<character>";
    const std::string characterTagEnd = "</character>";
    const size_t characterTagStartLength = characterTagStart.length();

    while ((currentPosition = xmlContent.find(characterTagStart, currentPosition)) != std::string::npos) {
        size_t endPos = xmlContent.find(characterTagEnd, currentPosition);
        if (endPos != std::string::npos) {
            // Extract character name
            const size_t nameStartPos = currentPosition + characterTagStartLength;
            std::string characterName = xmlContent.substr(nameStartPos, endPos - nameStartPos);

            // Add character name to the vector
            characterNames.push_back(characterName);

            // Move to the next position after the current character tag
            currentPosition = endPos + characterTagEnd.length();
        }
    }

    return characterNames;
}

GameSettings XMLReader::loadGameSettings() {
    GameSettings settings;

    std::ifstream xmlFile(filename_);
    if (!xmlFile.is_open()) {
        std::cerr << "Error opening XML file." << std::endl;
        return settings;
    }

    std::stringstream buffer;
    buffer << xmlFile.rdbuf();
    std::string xmlContent = buffer.str();
    
    //Getting the number of players
    size_t startPos = xmlContent.find("<NumberOfPlayers>");
    size_t endPos = xmlContent.find("</NumberOfPlayers>");
    const size_t numberOfPlayersTagStart = 17;

    if (startPos != std::string::npos && endPos != std::string::npos) {
        std::string playersStr = xmlContent.substr(startPos + numberOfPlayersTagStart, endPos - startPos - numberOfPlayersTagStart);
        settings.NumberOfPlayers = std::stoi(playersStr);
    }

    return settings;
}

void XMLReader::saveGameSettings(const GameSettings& settings) {
    std::ofstream xmlFile(filename_);
    if (!xmlFile.is_open()) {
        std::cerr << "Error opening XML file for writing." << std::endl;
        return;
    }

    // Write the XML content
    xmlFile << "<GameSettings>" << std::endl;
    xmlFile << "    <NumberOfPlayers>" << settings.NumberOfPlayers << "</NumberOfPlayers>" << std::endl;
    xmlFile << "</GameSettings>" << std::endl;

    xmlFile.close();
}

// Function to parse XML content and extract character names and stand power descriptions
std::unordered_map<std::string, std::string> XMLReader::GetCharacterData() {
    std::unordered_map<std::string, std::string> characterStandMap;

    std::ifstream xmlFile(filename_);
    if (!xmlFile.is_open()) {
        std::cerr << "Error opening XML file." << std::endl;
        return characterStandMap;
    }

    // Read the XML content into a string
    std::stringstream buffer;
    buffer << xmlFile.rdbuf();
    std::string xmlContent = buffer.str();

    // Find and extract character names and stand power descriptions
    size_t currentPosition = 0;
    const std::string characterTagStart = "<Character>";
    const std::string characterTagEnd = "</Character>";

    while ((currentPosition = xmlContent.find(characterTagStart, currentPosition)) != std::string::npos) {
        size_t endPos = xmlContent.find(characterTagEnd, currentPosition);
        if (endPos != std::string::npos) {
            // Extract character data
            std::string characterData = xmlContent.substr(currentPosition, endPos - currentPosition + characterTagEnd.length());

            // Extract character name
            size_t nameStartPos = characterData.find("<Name>") + 6; // Length of "<Name>"
            size_t nameEndPos = characterData.find("</Name>");
            std::string characterName = characterData.substr(nameStartPos, nameEndPos - nameStartPos);

            // Extract stand power description
            size_t standStartPos = characterData.find("<StandPowerDescription>") + 24; // Length of "<StandPowerDescription>"
            size_t standEndPos = characterData.find("</StandPowerDescription>");
            std::string standPowerDescription = characterData.substr(standStartPos, standEndPos - standStartPos);

            // Add character name and stand power description to the unordered_map
            auto insertionResult = characterStandMap.insert({ characterName, standPowerDescription });
            if (!insertionResult.second) {
                // Failed to insert due to duplicate key
                std::cerr << "Duplicate character name found: " << characterName << std::endl;
            }

            // Move to the next position after the current character tag
            currentPosition = endPos + characterTagEnd.length();
        }
    }

    return characterStandMap;
}