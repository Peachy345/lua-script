#pragma once

#include <filesystem>

namespace fs = std::experimental::filesystem;

class Settings
{
public:

private:
    void UpdateDirectoryContent(const fs::path& fsPath);
    inline fs::path GetFolderPath();

    fs::path                 fsPath{};
    std::vector<std::string> vecFileNames{};

public:
    /* All our settings variables will be here  *
    * The best would be if they'd get          *
    * initialized in the class itself.         */

    bool  bCheatActive = true;
    bool  bMenuOpened  = false;
    bool  bBhopEnabled = true;
    bool  bShowBoxes   = true;
    bool  bShowNames   = true;
    bool  bShowWeapons = true;
};

extern Settings g_Settings;

