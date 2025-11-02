#include "Body.h"

CCredits* CCreditsExt::Instance = nullptr;

void CCreditsExt::ProgramStartupInit()
{
	RunTime::ResetMemoryContentAt(0x592810, &CCreditsExt::PreTranslateMessageExt);
}

BOOL CCreditsExt::PreTranslateMessageExt(MSG* pMsg)
{
	// Remove all easter-egg game triggers (CChineseChess/CGoBang) and fall back to default handling
	return this->ppmfc::CDialog::PreTranslateMessage(pMsg);
}