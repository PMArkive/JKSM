#include "JKSM.hpp"
#include <3ds.h>

extern "C"
{
    // This is needed so minizip can function without crashing 3DS.
    u32 __stacksize__ = 0x20000;
    /*
        // This is here for the sole purpose of stopping JKSM from initializing and being tainted by the nightmare
        that is ctrulib's archive_dev.c
    */
    void __appInit()
    {
        srvInit();
    }

    void __appExit()
    {
        srvExit();
    }
}

int main(void)
{
    JKSM::Initialize();
    while (JKSM::IsRunning() && aptMainLoop())
    {
        JKSM::Update();
        JKSM::Render();
    }
    JKSM::Exit();
    return 0;
}
