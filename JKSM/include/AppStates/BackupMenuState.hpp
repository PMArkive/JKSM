#pragma once
#include "AppStates/AppState.hpp"
#include "Data/TitleData.hpp"
#include "FsLib.hpp"
#include "UI/Menu.hpp"
#include <memory>

class BackupMenuState : public AppState
{
    public:
        BackupMenuState(AppState *CreatingState, const Data::TitleData *Data, Data::SaveDataType SaveType);
        ~BackupMenuState();

        void Update(void);
        void DrawTop(SDL_Surface *Target);
        void DrawBottom(SDL_Surface *Target);

    private:
        // Pointer to state that created this one so we can draw the top screen.
        AppState *m_CreatingState = nullptr;
        // Keep the pointer just in case.
        const Data::TitleData *m_Data = nullptr;
        // Backup menu.
        std::unique_ptr<UI::Menu> m_BackupMenu = nullptr;
        // Directory Path
        FsLib::Path m_DirectoryPath;
        // Directory Listing.
        FsLib::Directory m_DirectoryListing;
        // X coordinate for centering bottom text header thingy.
        int m_TextX = 0;
        // Reloads listing and refreshes menu.
        void Refresh(void);
};
