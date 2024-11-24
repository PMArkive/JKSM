#include "AppStates/TaskState.hpp"

void TaskState::Update(void)
{
    if (m_Task.IsFinished())
    {
        AppState::Deactivate();
    }
}

void TaskState::DrawTop(SDL_Surface *Target)
{
    std::string ThreadStatus = m_Task.GetStatus();
    int TextX = 200 - (m_Noto->GetTextWidth(12, ThreadStatus.c_str()));

    m_CreatingState->DrawTop(Target);
    m_Noto->BlitTextAt(Target, TextX, 114, 12, SDL::Font::NO_TEXT_WRAP, ThreadStatus.c_str());
}

void TaskState::DrawBottom(SDL_Surface *Target)
{
    m_CreatingState->DrawBottom(Target);
}
