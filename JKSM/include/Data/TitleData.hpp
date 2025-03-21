#pragma once
#include "Data/ExtData.hpp"
#include "Data/SMDH.hpp"
#include "Data/SaveDataType.hpp"
#include "SDL/ResourceManager.hpp"
#include <3ds.h>
#include <cstdint>

namespace Data
{
    typedef struct
    {
            bool HasSaveType[Data::SaveTypeTotal] = {false};
    } TitleSaveTypes;

    class TitleData
    {
        public:
            TitleData(void) = default;
            // Initialize from system. The last argument is because there's no point in running another test.
            TitleData(uint64_t TitleID, FS_MediaType MediaType, Data::TitleSaveTypes TitleSaveTypes);
            // Initialize from cache. Basically just copying this stuff.
            TitleData(uint64_t TitleID,
                      FS_MediaType MediaType,
                      const char *ProductCode,
                      const char16_t *Title,
                      const char16_t *Publisher,
                      TitleSaveTypes SaveTypes,
                      const void *IconData);

            // Returns if the title has any save data at all.
            bool HasSaveData(void) const;
            // Returns the full title id.
            uint64_t GetTitleID(void) const;
            // Returns the lower 32 bits of title id.
            uint32_t GetLowerID(void) const;
            // Returns the upper 32 bits of title id.
            uint32_t GetUpperID(void) const;
            // Returns the unique id
            uint32_t GetUniqueID(void) const;
            // Returns the ID used for opening ExtData
            uint32_t GetExtDataID(void) const;
            // Returns the media type of the title.
            FS_MediaType GetMediaType(void) const;
            // Returns if title is favorited in config.
            bool IsFavorite(void) const;
            // Returns product code
            const char *GetProductCode(void) const;
            // Returns Title
            const char16_t *GetTitle(void) const;
            // Returns scrubbed title
            const char16_t *GetPathSafeTitle(void) const;
            // Returns Publisher
            const char16_t *GetPublisher(void) const;
            // Returns types of saves title has.
            Data::TitleSaveTypes GetSaveTypes(void) const;
            // Returns icon.
            SDL::SharedSurface GetIcon(void);

        private:
            // Title ID;
            uint64_t m_TitleID = 0;
            // Media type.
            FS_MediaType m_MediaType;
            // Product code. I couldn't find any information on a maximum length for this...
            char m_ProductCode[0x20] = {0};
            // Title. This length is know because of SMDH
            char16_t m_Title[0x40] = {0};
            // This is the path safe, sanitized version of the title.
            char16_t m_PathSafeTitle[0x40] = {0};
            // Publisher
            char16_t m_Publisher[0x40] = {0};
            // Whether or not the title is a favorite.
            bool m_IsFavorite = false;
            // Types of save data the title has
            TitleSaveTypes m_TitleSaveTypes;
            // Icon.
            SDL::SharedSurface m_Icon = nullptr;
            // This function loads defaults in case of SDMH loading failure.
            void TitleInitializeDefault(void);
            // This method initializes TitleData using an SMDH
            void TitleInitializeSMDH(const Data::SMDH &SMDH);
    };
} // namespace Data
