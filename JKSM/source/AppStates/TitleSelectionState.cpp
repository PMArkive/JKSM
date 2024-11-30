#include "AppStates/TitleSelectionState.hpp"
#include "Assets.hpp"
#include "StringUtil.hpp"
#include "UI/Strings.hpp"
#include <array>

TitleSelectionState::TitleSelectionState(Data::SaveDataType SaveType)
    : BaseSelectionState(SaveType), m_TitleView(std::make_unique<UI::TitleView>(SaveType))
{
    m_TextX = 200 - (m_Noto->GetTextWidth(12, UI::Strings::GetStringByName(UI::Strings::Names::StateName, m_SaveType)) / 2);
}

void TitleSelectionState::Update(void)
{
    m_TitleView->Update();
}

void TitleSelectionState::DrawTop(SDL_Surface *Target)
{
    m_TitleView->Draw(Target);
    SDL::DrawRect(Target, 0, 224, 400, 16, SDL::Colors::BarColor);
    m_Noto->BlitTextAt(Target, m_TextX, 225, 12, m_Noto->NO_TEXT_WRAP, UI::Strings::GetStringByName(UI::Strings::Names::StateName, m_SaveType));
}

void TitleSelectionState::DrawBottom(SDL_Surface *Target)
{
    BaseSelectionState::DrawTitleInformation(Target, m_TitleView->GetSelectedTitleData());
}

void TitleSelectionState::Refresh(void)
{
    m_TitleView->Refresh();
}
