#include <Helpers/Macro.h>
#include <CMapData.h>

#include <map>

#include "../FA2sp.h"
#include "../Helpers/STDHelpers.h"
#include "../Helpers/ControlHelpers.h"
#include "../Helpers/Translations.h"
#include "StringtableLoader.h"

DEFINE_HOOK(43CE50, Miscs_LoadParamToCombobox, 7)
{
    GET_STACK(ppmfc::CComboBox*, pComboBox, 0x4);
    GET_STACK(int, nCode, 0x8);

    if (nCode <= 30) // 30 is our float
        return 0;

    if (nCode >= 500) // Custom params from FAData TriggerParamTypes section
	{
        ControlHelpers::ComboBox::LoadTriggerParamType(*pComboBox, nCode);
	    return 0x43D058;
	}
    auto const pINI = CMapData::GetMapDocument(true);

    // Consistence with FA2Ext
    switch (nCode)
    {
    case 31: // Enter Status
        pComboBox->DeleteAllStrings();
    { auto s = Translations::TranslateOrDefault("ScriptParam.Status.0", "0 - Sleep"); ::SendMessageA(pComboBox->m_hWnd, CB_ADDSTRING, 0, (LPARAM)s); }
    { auto s = Translations::TranslateOrDefault("ScriptParam.Status.1", "1 - Attack nearest enemy"); ::SendMessageA(pComboBox->m_hWnd, CB_ADDSTRING, 0, (LPARAM)s); }
    { auto s = Translations::TranslateOrDefault("ScriptParam.Status.2", "2 - Move"); ::SendMessageA(pComboBox->m_hWnd, CB_ADDSTRING, 0, (LPARAM)s); }
    { auto s = Translations::TranslateOrDefault("ScriptParam.Status.3", "3 - QMove"); ::SendMessageA(pComboBox->m_hWnd, CB_ADDSTRING, 0, (LPARAM)s); }
    { auto s = Translations::TranslateOrDefault("ScriptParam.Status.4", "4 - Retreat"); ::SendMessageA(pComboBox->m_hWnd, CB_ADDSTRING, 0, (LPARAM)s); }
    { auto s = Translations::TranslateOrDefault("ScriptParam.Status.5", "5 - Guard (default)"); ::SendMessageA(pComboBox->m_hWnd, CB_ADDSTRING, 0, (LPARAM)s); }
    { auto s = Translations::TranslateOrDefault("ScriptParam.Status.6", "6 - Sticky"); ::SendMessageA(pComboBox->m_hWnd, CB_ADDSTRING, 0, (LPARAM)s); }
    { auto s = Translations::TranslateOrDefault("ScriptParam.Status.7", "7 - Enter object"); ::SendMessageA(pComboBox->m_hWnd, CB_ADDSTRING, 0, (LPARAM)s); }
    { auto s = Translations::TranslateOrDefault("ScriptParam.Status.8", "8 - Capture object"); ::SendMessageA(pComboBox->m_hWnd, CB_ADDSTRING, 0, (LPARAM)s); }
    { auto s = Translations::TranslateOrDefault("ScriptParam.Status.9", "9 - Move into & get eaten"); ::SendMessageA(pComboBox->m_hWnd, CB_ADDSTRING, 0, (LPARAM)s); }
    { auto s = Translations::TranslateOrDefault("ScriptParam.Status.10", "10 - Harvest"); ::SendMessageA(pComboBox->m_hWnd, CB_ADDSTRING, 0, (LPARAM)s); }
    { auto s = Translations::TranslateOrDefault("ScriptParam.Status.11", "11 - Area Guard"); ::SendMessageA(pComboBox->m_hWnd, CB_ADDSTRING, 0, (LPARAM)s); }
    { auto s = Translations::TranslateOrDefault("ScriptParam.Status.12", "12 - Return (to refinery)"); ::SendMessageA(pComboBox->m_hWnd, CB_ADDSTRING, 0, (LPARAM)s); }
    { auto s = Translations::TranslateOrDefault("ScriptParam.Status.13", "13 - Stop"); ::SendMessageA(pComboBox->m_hWnd, CB_ADDSTRING, 0, (LPARAM)s); }
    { auto s = Translations::TranslateOrDefault("ScriptParam.Status.14", "14 - Ambush (wait until discovered)"); ::SendMessageA(pComboBox->m_hWnd, CB_ADDSTRING, 0, (LPARAM)s); }
    { auto s = Translations::TranslateOrDefault("ScriptParam.Status.15", "15 - Hunt"); ::SendMessageA(pComboBox->m_hWnd, CB_ADDSTRING, 0, (LPARAM)s); }
    { auto s = Translations::TranslateOrDefault("ScriptParam.Status.16", "16 - Unload/Deploy"); ::SendMessageA(pComboBox->m_hWnd, CB_ADDSTRING, 0, (LPARAM)s); }
    { auto s = Translations::TranslateOrDefault("ScriptParam.Status.17", "17 - Sabotage (move in & destroy)"); ::SendMessageA(pComboBox->m_hWnd, CB_ADDSTRING, 0, (LPARAM)s); }
    { auto s = Translations::TranslateOrDefault("ScriptParam.Status.18", "18 - Construction"); ::SendMessageA(pComboBox->m_hWnd, CB_ADDSTRING, 0, (LPARAM)s); }
    { auto s = Translations::TranslateOrDefault("ScriptParam.Status.19", "19 - Deconstruction"); ::SendMessageA(pComboBox->m_hWnd, CB_ADDSTRING, 0, (LPARAM)s); }
    { auto s = Translations::TranslateOrDefault("ScriptParam.Status.20", "20 - Repair"); ::SendMessageA(pComboBox->m_hWnd, CB_ADDSTRING, 0, (LPARAM)s); }
    { auto s = Translations::TranslateOrDefault("ScriptParam.Status.21", "21 - Rescue"); ::SendMessageA(pComboBox->m_hWnd, CB_ADDSTRING, 0, (LPARAM)s); }
    { auto s = Translations::TranslateOrDefault("ScriptParam.Status.22", "22 - Missile"); ::SendMessageA(pComboBox->m_hWnd, CB_ADDSTRING, 0, (LPARAM)s); }
    { auto s = Translations::TranslateOrDefault("ScriptParam.Status.23", "23 - Harmless"); ::SendMessageA(pComboBox->m_hWnd, CB_ADDSTRING, 0, (LPARAM)s); }
    { auto s = Translations::TranslateOrDefault("ScriptParam.Status.24", "24 - Open"); ::SendMessageA(pComboBox->m_hWnd, CB_ADDSTRING, 0, (LPARAM)s); }
    { auto s = Translations::TranslateOrDefault("ScriptParam.Status.25", "25 - Patrol"); ::SendMessageA(pComboBox->m_hWnd, CB_ADDSTRING, 0, (LPARAM)s); }
    { auto s = Translations::TranslateOrDefault("ScriptParam.Status.26", "26 - Paradrop approach drop zone"); ::SendMessageA(pComboBox->m_hWnd, CB_ADDSTRING, 0, (LPARAM)s); }
    { auto s = Translations::TranslateOrDefault("ScriptParam.Status.27", "27 - Paradrop overlay drop zone"); ::SendMessageA(pComboBox->m_hWnd, CB_ADDSTRING, 0, (LPARAM)s); }
    { auto s = Translations::TranslateOrDefault("ScriptParam.Status.28", "28 - Wait"); ::SendMessageA(pComboBox->m_hWnd, CB_ADDSTRING, 0, (LPARAM)s); }
    { auto s = Translations::TranslateOrDefault("ScriptParam.Status.29", "29 - Attack again"); ::SendMessageA(pComboBox->m_hWnd, CB_ADDSTRING, 0, (LPARAM)s); }
    { auto s = Translations::TranslateOrDefault("ScriptParam.Status.30", "30 - Spyplane approach (YR)"); ::SendMessageA(pComboBox->m_hWnd, CB_ADDSTRING, 0, (LPARAM)s); }
    { auto s = Translations::TranslateOrDefault("ScriptParam.Status.31", "31 - Spyplane overfly (YR)"); ::SendMessageA(pComboBox->m_hWnd, CB_ADDSTRING, 0, (LPARAM)s); }
        break;
    case 32: // Targets
        pComboBox->DeleteAllStrings();
    { auto s = Translations::TranslateOrDefault("ScriptParam.Target.0", "0 - Any target"); ::SendMessageA(pComboBox->m_hWnd, CB_ADDSTRING, 0, (LPARAM)s); }
    { auto s = Translations::TranslateOrDefault("ScriptParam.Target.1", "1 - Any target (same as 0)"); ::SendMessageA(pComboBox->m_hWnd, CB_ADDSTRING, 0, (LPARAM)s); }
    { auto s = Translations::TranslateOrDefault("ScriptParam.Target.2", "2 - Buildings"); ::SendMessageA(pComboBox->m_hWnd, CB_ADDSTRING, 0, (LPARAM)s); }
    { auto s = Translations::TranslateOrDefault("ScriptParam.Target.3", "3 - Ore miners and fields"); ::SendMessageA(pComboBox->m_hWnd, CB_ADDSTRING, 0, (LPARAM)s); }
    { auto s = Translations::TranslateOrDefault("ScriptParam.Target.4", "4 - Infantry"); ::SendMessageA(pComboBox->m_hWnd, CB_ADDSTRING, 0, (LPARAM)s); }
    { auto s = Translations::TranslateOrDefault("ScriptParam.Target.5", "5 - Vehicles"); ::SendMessageA(pComboBox->m_hWnd, CB_ADDSTRING, 0, (LPARAM)s); }
    { auto s = Translations::TranslateOrDefault("ScriptParam.Target.6", "6 - Production buildings"); ::SendMessageA(pComboBox->m_hWnd, CB_ADDSTRING, 0, (LPARAM)s); }
    { auto s = Translations::TranslateOrDefault("ScriptParam.Target.7", "7 - Defensive buildings"); ::SendMessageA(pComboBox->m_hWnd, CB_ADDSTRING, 0, (LPARAM)s); }
    { auto s = Translations::TranslateOrDefault("ScriptParam.Target.8", "8 - Base threats"); ::SendMessageA(pComboBox->m_hWnd, CB_ADDSTRING, 0, (LPARAM)s); }
    { auto s = Translations::TranslateOrDefault("ScriptParam.Target.9", "9 - Power plants"); ::SendMessageA(pComboBox->m_hWnd, CB_ADDSTRING, 0, (LPARAM)s); }
    { auto s = Translations::TranslateOrDefault("ScriptParam.Target.10", "10 - Garrisonable buildings"); ::SendMessageA(pComboBox->m_hWnd, CB_ADDSTRING, 0, (LPARAM)s); }
    { auto s = Translations::TranslateOrDefault("ScriptParam.Target.11", "11 - Tech buildings"); ::SendMessageA(pComboBox->m_hWnd, CB_ADDSTRING, 0, (LPARAM)s); }
        break;
    case 33: // Facing
        pComboBox->DeleteAllStrings();
    { auto s = Translations::TranslateOrDefault("ScriptParam.Facing.0", "0 - NE"); ::SendMessageA(pComboBox->m_hWnd, CB_ADDSTRING, 0, (LPARAM)s); }
    { auto s = Translations::TranslateOrDefault("ScriptParam.Facing.1", "1 - E"); ::SendMessageA(pComboBox->m_hWnd, CB_ADDSTRING, 0, (LPARAM)s); }
    { auto s = Translations::TranslateOrDefault("ScriptParam.Facing.2", "2 - SE"); ::SendMessageA(pComboBox->m_hWnd, CB_ADDSTRING, 0, (LPARAM)s); }
    { auto s = Translations::TranslateOrDefault("ScriptParam.Facing.3", "3 - S"); ::SendMessageA(pComboBox->m_hWnd, CB_ADDSTRING, 0, (LPARAM)s); }
    { auto s = Translations::TranslateOrDefault("ScriptParam.Facing.4", "4 - SW"); ::SendMessageA(pComboBox->m_hWnd, CB_ADDSTRING, 0, (LPARAM)s); }
    { auto s = Translations::TranslateOrDefault("ScriptParam.Facing.5", "5 - W"); ::SendMessageA(pComboBox->m_hWnd, CB_ADDSTRING, 0, (LPARAM)s); }
    { auto s = Translations::TranslateOrDefault("ScriptParam.Facing.6", "6 - NW"); ::SendMessageA(pComboBox->m_hWnd, CB_ADDSTRING, 0, (LPARAM)s); }
    { auto s = Translations::TranslateOrDefault("ScriptParam.Facing.7", "7 - N"); ::SendMessageA(pComboBox->m_hWnd, CB_ADDSTRING, 0, (LPARAM)s); }
        break;
    case 34: // Split
        pComboBox->DeleteAllStrings();
    { auto s = Translations::TranslateOrDefault("ScriptParam.SplitGroup.0", "0 - Keep transport, keep passengers"); ::SendMessageA(pComboBox->m_hWnd, CB_ADDSTRING, 0, (LPARAM)s); }
    { auto s = Translations::TranslateOrDefault("ScriptParam.SplitGroup.1", "1 - Keep transport, drop passengers"); ::SendMessageA(pComboBox->m_hWnd, CB_ADDSTRING, 0, (LPARAM)s); }
    { auto s = Translations::TranslateOrDefault("ScriptParam.SplitGroup.2", "2 - Drop transport, keep passengers"); ::SendMessageA(pComboBox->m_hWnd, CB_ADDSTRING, 0, (LPARAM)s); }
    { auto s = Translations::TranslateOrDefault("ScriptParam.SplitGroup.3", "3 - Drop transport, drop passengers"); ::SendMessageA(pComboBox->m_hWnd, CB_ADDSTRING, 0, (LPARAM)s); }
        break;
    case 35: // Camera Move Speed
        pComboBox->DeleteAllStrings();
    { auto s = Translations::TranslateOrDefault("ScriptParam.CameraSpeed.0", "0 - Very slow"); ::SendMessageA(pComboBox->m_hWnd, CB_ADDSTRING, 0, (LPARAM)s); }
    { auto s = Translations::TranslateOrDefault("ScriptParam.CameraSpeed.1", "1 - Slow"); ::SendMessageA(pComboBox->m_hWnd, CB_ADDSTRING, 0, (LPARAM)s); }
    { auto s = Translations::TranslateOrDefault("ScriptParam.CameraSpeed.2", "2 - Normal"); ::SendMessageA(pComboBox->m_hWnd, CB_ADDSTRING, 0, (LPARAM)s); }
    { auto s = Translations::TranslateOrDefault("ScriptParam.CameraSpeed.3", "3 - Fast"); ::SendMessageA(pComboBox->m_hWnd, CB_ADDSTRING, 0, (LPARAM)s); }
    { auto s = Translations::TranslateOrDefault("ScriptParam.CameraSpeed.4", "4 - Very fast"); ::SendMessageA(pComboBox->m_hWnd, CB_ADDSTRING, 0, (LPARAM)s); }
        break;
    case 37: // Radar Event Type
        pComboBox->DeleteAllStrings();
        for (int i = 0; i <= 16; ++i)
        {
            ppmfc::CString item;
            item.Format("%d - %s", i, Translations::TranslateOrDefault((std::string("ScriptParam.RadarEventType.") + std::to_string(i)).c_str(), (std::string("Type ") + std::to_string(i)).c_str()));
            ::SendMessageA(pComboBox->m_hWnd, CB_ADDSTRING, 0, (LPARAM)(LPCSTR)item.m_pchData);
        }
        break;
    case 38: // Tabpage
        pComboBox->DeleteAllStrings();
        {
            // Map to existing language keys for tab pages
            ppmfc::CString item;
            item.Format("0 - %s", Translations::TranslateOrDefault("TabPages.TilePlacement", "Tiles/Overlays"));
            ::SendMessageA(pComboBox->m_hWnd, CB_ADDSTRING, 0, (LPARAM)(LPCSTR)item.m_pchData);
            item.Format("1 - %s", Translations::TranslateOrDefault("TabPages.TriggerSort", "Triggers"));
            ::SendMessageA(pComboBox->m_hWnd, CB_ADDSTRING, 0, (LPARAM)(LPCSTR)item.m_pchData);
            item.Format("2 - %s", Translations::TranslateOrDefault("TabPages.TeamSort", "Teams"));
            ::SendMessageA(pComboBox->m_hWnd, CB_ADDSTRING, 0, (LPARAM)(LPCSTR)item.m_pchData);
            item.Format("3 - %s", Translations::TranslateOrDefault("TabPages.TaskforceSort", "TaskForces"));
            ::SendMessageA(pComboBox->m_hWnd, CB_ADDSTRING, 0, (LPARAM)(LPCSTR)item.m_pchData);
        }
        break;
    case 39: // SuperWeaponTypes (ID)
        ControlHelpers::ComboBox::LoadGenericList(*pComboBox, "SuperWeaponTypes", true, false, true);
        break;
    case 40: // Variable Operators
        ::SendMessageA(pComboBox->m_hWnd, CB_ADDSTRING, 0, (LPARAM)Translations::TranslateOrDefault("VariableOperators.0", "0 - Assign (=)     A=B"));
        ::SendMessageA(pComboBox->m_hWnd, CB_ADDSTRING, 0, (LPARAM)Translations::TranslateOrDefault("VariableOperators.1", "1 - Add (+)        A=A+B"));
        ::SendMessageA(pComboBox->m_hWnd, CB_ADDSTRING, 0, (LPARAM)Translations::TranslateOrDefault("VariableOperators.2", "2 - Subtract (-)    A=A-B"));
        ::SendMessageA(pComboBox->m_hWnd, CB_ADDSTRING, 0, (LPARAM)Translations::TranslateOrDefault("VariableOperators.3", "3 - Multiply (*)    A=A*B"));
        ::SendMessageA(pComboBox->m_hWnd, CB_ADDSTRING, 0, (LPARAM)Translations::TranslateOrDefault("VariableOperators.4", "4 - Divide (/)      A=A/B"));
        ::SendMessageA(pComboBox->m_hWnd, CB_ADDSTRING, 0, (LPARAM)Translations::TranslateOrDefault("VariableOperators.5", "5 - Modulo (%)      A=A%B"));
        ::SendMessageA(pComboBox->m_hWnd, CB_ADDSTRING, 0, (LPARAM)Translations::TranslateOrDefault("VariableOperators.6", "6 - Shift left (<<) A=A<<B"));
        ::SendMessageA(pComboBox->m_hWnd, CB_ADDSTRING, 0, (LPARAM)Translations::TranslateOrDefault("VariableOperators.7", "7 - Shift right (>>)A=A>>B"));
        ::SendMessageA(pComboBox->m_hWnd, CB_ADDSTRING, 0, (LPARAM)Translations::TranslateOrDefault("VariableOperators.8", "8 - Bitwise NOT (~) A=~A"));
        ::SendMessageA(pComboBox->m_hWnd, CB_ADDSTRING, 0, (LPARAM)Translations::TranslateOrDefault("VariableOperators.9", "9 - XOR (^)         A=A^B"));
        ::SendMessageA(pComboBox->m_hWnd, CB_ADDSTRING, 0, (LPARAM)Translations::TranslateOrDefault("VariableOperators.10", "10 - OR (|)         A=A|B"));
        ::SendMessageA(pComboBox->m_hWnd, CB_ADDSTRING, 0, (LPARAM)Translations::TranslateOrDefault("VariableOperators.11", "11 - AND (&)        A=A&B"));
		break;
    case 41: // House Addons
        ControlHelpers::ComboBox::LoadCountries(*pComboBox, true);
        ControlHelpers::ComboBox::LoadHousesAddonMulti(*pComboBox, true);
        ControlHelpers::ComboBox::LoadHousesAddon(*pComboBox, true);
        break;
    case 42: // House Addons for pb events
        ControlHelpers::ComboBox::LoadCountries(*pComboBox, true);
        ControlHelpers::ComboBox::LoadHousesAddonMulti(*pComboBox, true);
        ControlHelpers::ComboBox::LoadHousesAddon2(*pComboBox, true);
        break;
    case 43: //Tag List for action 70

        pComboBox->DeleteAllStrings();


        pComboBox->LockWindowUpdate();

        if (ExtConfigs::SortByTriggerName && pComboBox->GetDlgCtrlID() == 1402)
        {
            std::map<ppmfc::CString, ppmfc::CString> collector;

            if (auto const pSection = pINI->GetSection("Tags"))
            {
                for (auto& pair : pSection->GetEntities())
                {
                    auto splits = STDHelpers::SplitString(pair.second, 2);
                    ppmfc::CString buffer;
                    buffer.Format("%s (%s) (%s)", pair.first, splits[1], splits[2]);
                    collector.insert(std::make_pair(splits[1], buffer));
                }
            }

            for (auto& pair : collector)
                ::SendMessageA(pComboBox->m_hWnd, CB_ADDSTRING, 0, (LPARAM)(LPCSTR)pair.second.m_pchData);

            collector.clear();
        }
        else
        {
            if (auto pSection = pINI->GetSection("Tags"))
            {
                for (auto& pair : pSection->GetEntities())
                {
                    auto splits = STDHelpers::SplitString(pair.second, 2);
                    ppmfc::CString buffer;
                    buffer.Format("%s (%s) (%s)", pair.first, splits[1], splits[2]);
                    ::SendMessageA(pComboBox->m_hWnd, CB_ADDSTRING, 0, (LPARAM)(LPCSTR)buffer.m_pchData);
                }
            }
        }

        pComboBox->UnlockWindowUpdate();
        break;
    case 44: // Country Addons -1
        ControlHelpers::ComboBox::LoadCountries(*pComboBox, true);
        ControlHelpers::ComboBox::LoadHousesAddon3(*pComboBox, true);
        break;
    case 45: // pure House
        ControlHelpers::ComboBox::LoadCountries(*pComboBox, true);
        ControlHelpers::ComboBox::LoadHousesAddonMulti(*pComboBox, true);
        break;
    case 46: // Country Addons -1 + multi (ares)
        ControlHelpers::ComboBox::LoadCountries(*pComboBox, true);
        ControlHelpers::ComboBox::LoadHousesAddonMultiAres(*pComboBox, true);
        ControlHelpers::ComboBox::LoadHousesAddon3(*pComboBox, true);
        break;
    case 47: // Country + multi (ares)
        ControlHelpers::ComboBox::LoadCountries(*pComboBox, true);
        ControlHelpers::ComboBox::LoadHousesAddonMultiAres(*pComboBox, true);
        break;
    default: // Not a valid param
        break;
    }

    return 0x43D058;
}

DEFINE_HOOK(43D037, Miscs_LoadParams_AdjustComboboxDropdownWidth, C)
{
    if (ExtConfigs::AdjustDropdownWidth)
    {
        GET_STACK(ppmfc::CComboBox*, pComboBox, STACK_OFFS(0x18, -0x4));

        int nWidth = 120;
        for (int i = 0; i < pComboBox->GetCount() && nWidth <= ExtConfigs::AdjustDropdownWidth_Max; ++i)
            nWidth = std::max(nWidth, pComboBox->GetLBTextLen(i) * ExtConfigs::AdjustDropdownWidth_Factor);

        nWidth = std::min(nWidth, ExtConfigs::AdjustDropdownWidth_Max);
        pComboBox->SetDroppedWidth(nWidth);
    }

    return 0;
}

DEFINE_HOOK(43CFE4, Miscs_LoadParams_SpeechBubble, 6)
{
    auto AddString = [](HWND hComboBox, const char* lpString)
    {
        // Use ANSI explicitly to avoid UNICODE LPWSTR mismatch
        SendMessageA(hComboBox, CB_ADDSTRING, 0, (LPARAM)lpString);
    };

    GET(HWND, hComboBox, ECX);
    while (SendMessage(hComboBox, CB_GETCOUNT, 0, NULL) > 0)
        SendMessage(hComboBox, CB_DELETESTRING, 0, 0);
    AddString(hComboBox, Translations::TranslateOrDefault("ScriptParam.TalkBubble.0", "0 - None"));
    AddString(hComboBox, Translations::TranslateOrDefault("ScriptParam.TalkBubble.1", "1 - Friendly (*)"));
    AddString(hComboBox, Translations::TranslateOrDefault("ScriptParam.TalkBubble.2", "2 - Question (?)"));
    AddString(hComboBox, Translations::TranslateOrDefault("ScriptParam.TalkBubble.3", "3 - Alert (!)") );
    return 0x43D037;
}

DEFINE_HOOK(441910, Miscs_LoadParams_TutorialTexts, 7)
{
    GET_STACK(ppmfc::CComboBox*, pComboBox, 0x4);
    if (ExtConfigs::TutorialTexts_Hide)
    {
        pComboBox->DeleteAllStrings();
        return 0x441A34;
    }
    if (ExtConfigs::TutorialTexts_Fix)
    {
        pComboBox->DeleteAllStrings();
        // Populate from loaded CSF string table instead of a non-existent map
        for (const auto& kv : StringtableLoader::CSFFiles_Stringtable)
        {
            ppmfc::CString item;
            item.Format("%s : %s", kv.first.c_str(), kv.second.c_str());
            ::SendMessageA(pComboBox->m_hWnd, CB_ADDSTRING, 0, (LPARAM)(LPCSTR)item.m_pchData);
        }
        Logger::Debug("%d csf entries added.\n", (int)StringtableLoader::CSFFiles_Stringtable.size());
        return 0x441A34;
    }
    return 0;
}

DEFINE_HOOK(441A40, Miscs_LoadParams_Triggers, 6)
{
    GET_STACK(ppmfc::CComboBox*, pComboBox, 0x4);

    pComboBox->DeleteAllStrings();

    auto const pINI = CMapData::GetMapDocument(true);
    pComboBox->LockWindowUpdate();

    if (ExtConfigs::SortByTriggerName && pComboBox->GetDlgCtrlID() == 1402)
    {
        std::map<ppmfc::CString, ppmfc::CString> collector;

        if (auto const pSection = pINI->GetSection("Triggers"))
        {
            for (auto& pair : pSection->GetEntities())
            {
                auto splits = STDHelpers::SplitString(pair.second, 2);
                ppmfc::CString buffer;
                buffer.Format("%s (%s)", pair.first, splits[2]);
                collector.insert(std::make_pair(splits[2], buffer));
            }
        }

        for (auto& pair : collector)
            ::SendMessageA(pComboBox->m_hWnd, CB_ADDSTRING, 0, (LPARAM)(LPCSTR)pair.second.m_pchData);

        collector.clear();
    }
    else
    {
        if (auto pSection = pINI->GetSection("Triggers"))
        {
            for (auto& pair : pSection->GetEntities())
            {
                auto splits = STDHelpers::SplitString(pair.second, 2);
                ppmfc::CString buffer;
                buffer.Format("%s (%s)", pair.first, splits[2]);
                ::SendMessageA(pComboBox->m_hWnd, CB_ADDSTRING, 0, (LPARAM)(LPCSTR)buffer.m_pchData);
            }
        }
    }

    pComboBox->UnlockWindowUpdate();
    return 0x441DF6;
}

