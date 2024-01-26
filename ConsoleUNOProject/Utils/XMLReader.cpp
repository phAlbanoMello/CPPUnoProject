#include "XMLReader.h"
#include <iostream>
#include <fstream>
#include <sstream>

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
