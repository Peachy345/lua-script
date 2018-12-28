#include <functional>
#include <ShlObj.h>
#include "Settings.h"
#include "Hooks.h"


/**
 * \brief Used to initialize settings parser. Call inside Hooks::init AFTER you initialized menu.
 * \param pMenuObj Pointer to your created menu object. In our case, its g_Hooks.nMenu
 */


/**


/**
 * \brief Updates vector with file names so you can use custom configs made by users (unlimited)
 * \param fsPath Path to the folder containing user configs
 */
void Settings::UpdateDirectoryContent(const fs::path& fsPath)
{
    this->vecFileNames.clear();

    /* Loop through directory content and save config files to your vector */
    for (const auto& it : fs::directory_iterator(fsPath))
    {
        if (!is_empty(it) && fsPath.extension() == ".yourextension")
            this->vecFileNames.push_back(it.path().filename().string());
    }
}


/**
 * \brief Gets the path to the userconfig folder. In this case - %APPDATA%\Antario\configs
 * \return std::experimental::filesystem::path containing folder path.
 */
fs::path Settings::GetFolderPath()
{
    /* Get %APPDATA% path in Windows system. */
    TCHAR szPath[MAX_PATH];
    SHGetFolderPath(nullptr, CSIDL_APPDATA, nullptr, 0, szPath);

    /* Save as filesystem::path and extend it so we use our own folder.*/
    auto fsPath = fs::path(szPath);
    fsPath.append(R"(\csgo-cheat\configs\)");
    return fsPath;
}
