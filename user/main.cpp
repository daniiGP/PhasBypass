// Generated C++ file by Il2CppInspector - http://www.djkaty.com - https://github.com/djkaty
// Custom injected code entry point

#include "pch-il2cpp.h"

#define WIN32_LEAN_AND_MEAN
#define VC_EXTRALEAN
#include <codecvt>
#include <Windows.h>
#include <iostream>
#include <detours.h>
#include <locale>

#include "il2cpp-appdata.h"
#include "helpers.h"

using namespace app;

extern const LPCWSTR LOG_FILE = L"bypass-log.txt";

const std::string NotMelonLoader = "totally_not_melon_loader";
String* not_melon_loader;
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

std::string ConvertString(String* stringName)
{
	std::string newString(((char*)&stringName->fields.m_firstChar), stringName->fields.m_stringLength * 2);
	newString.erase(std::remove(newString.begin(), newString.end(), 0x00), newString.end());

	return newString;
}

void DoNothingMethod(MethodInfo* method)
{
#ifdef _DEEPDEBUG
	SetConsoleTextAttribute(hConsole, 12);
	il2cppi_log_write("[DaniiGP] [PhasByP] [LOG] DoNothingMethod");
	SetConsoleTextAttribute(hConsole, 15);
#endif
}

bool File_Exists_Hook(String* str, MethodInfo* method)
{
	std::wstring_convert<std::codecvt_utf8<wchar_t>> wideToNarrow;
	std::string skey = wideToNarrow.to_bytes(std::wstring((const wchar_t*)
		(&((Il2CppString*)str)->chars), ((Il2CppString*)str)->length));
	if(skey.find("dll") != std::string::npos || skey.find(NotMelonLoader) != std::string::npos)
	{
		return false;
	}

#ifdef _DEBUG
	SetConsoleTextAttribute(hConsole, 12);
	//il2cppi_log_write("[DaniiGP] [PhasByP] [LOG] File_Exists_Hook: " + skey);
	SetConsoleTextAttribute(hConsole, 15);
#endif

	return File_Exists(str, method);
}

bool Directory_Exists_Hook(String* str, MethodInfo* method)
{
	std::wstring_convert<std::codecvt_utf8<wchar_t>> wideToNarrow;
	std::string skey = wideToNarrow.to_bytes(std::wstring((const wchar_t*)
		(&((Il2CppString*)str)->chars), ((Il2CppString*)str)->length));
	if(skey.find("MelonLoader") != std::string::npos || skey.find(NotMelonLoader) != std::string::npos)
	{
		return false;
	}

#ifdef _DEBUG
	SetConsoleTextAttribute(hConsole, 12);
	//il2cppi_log_write("[DaniiGP] [PhasByP] [LOG] Directory_Exists_Hook: " + skey);
	SetConsoleTextAttribute(hConsole, 15);
#endif

	return Directory_Exists(str, method);
}

bool String_Contains_Hook(String* str, String* str2, MethodInfo* method)
{
	std::wstring_convert<std::codecvt_utf8<wchar_t>> wideToNarrow;
	std::string skey = wideToNarrow.to_bytes(std::wstring((const wchar_t*)
		(&((Il2CppString*)str)->chars), ((Il2CppString*)str)->length));

	if(skey.find("MelonLoader") != std::string::npos
		|| skey.find(NotMelonLoader) != std::string::npos
		|| skey.find("bypass-log.txt") != std::string::npos
		|| skey.find("imgui.ini") != std::string::npos
		|| skey.find("PhasBypass.dll") != std::string::npos
		|| skey.find("phasbypass.dll") != std::string::npos
		|| skey.find("version.dll") != std::string::npos
		|| skey.find("winhttp.dll") != std::string::npos
		|| skey.find("doorstop_config.ini") != std::string::npos
		|| skey.find("phasmobootstrapper.exe") != std::string::npos
		|| skey.find("phasmobootstrapper (steam).exe") != std::string::npos)
	{
		return false;
	}

#ifdef _DEBUG
	SetConsoleTextAttribute(hConsole, 12);
	//il2cppi_log_write("[DaniiGP] [PhasByP] [LOG] String_Contains_Hook: " + skey);
	SetConsoleTextAttribute(hConsole, 15);
#endif

	return String_Contains(str, str2, method);
}

void* TryGetModuleHandleHook(String* str, MethodInfo* method)
{
	std::wstring_convert<std::codecvt_utf8<wchar_t>> wideToNarrow;
	std::string skey = wideToNarrow.to_bytes(std::wstring((const wchar_t*)
		(&((Il2CppString*)str)->chars), ((Il2CppString*)str)->length));
	#ifdef _DEBUG
	SetConsoleTextAttribute(hConsole, 12);
	//il2cppi_log_write("[DaniiGP] [PhasByP] [LOG] TryGetModuleHandleHook: " + skey);
	SetConsoleTextAttribute(hConsole, 15);
	#endif

	return nullptr;
}

String* GetMelonLoaderSearchStrings(Byte__Array* theArray, bool b, MethodInfo* method)
{
	#ifdef _DEBUG
		SetConsoleTextAttribute(hConsole, 12);
		//il2cppi_log_write("[DaniiGP] [PhasByP] [LOG] GetMelonLoaderSearchStrings");
		SetConsoleTextAttribute(hConsole, 15);
	#endif
	return not_melon_loader;
}

#ifdef _DEBUG
void DebugLog(Object* message, MethodInfo* method)
{
	SetConsoleTextAttribute(hConsole, 12);
	std::string str = ConvertString(Logger_GetString(message, NULL));
	//il2cppi_log_write("[DaniiGP] [PhasByP] [DEBUG] DebugLog: " + str);
	SetConsoleTextAttribute(hConsole, 15);
}

void DebugLogException(Exception* exception, MethodInfo* method)
{
	SetConsoleTextAttribute(hConsole, 12);
	std::string str = ConvertString(exception->fields._message);
	il2cppi_log_write("[DaniiGP] [PhasByP] [DEBUG] DebugLogException: " + str);
	SetConsoleTextAttribute(hConsole, 15);
}
#endif

void Run()
{
	il2cppi_new_console();
	SetConsoleTextAttribute(hConsole, 12);
	il2cppi_log_write("[DaniiGP] [PhasByP] !!! ONLY FOR !!! Server version: VR Overhaul | Hotfix v0.6.1.7");
	il2cppi_log_write("[DaniiGP] [PhasByP] !!! ONLY FOR !!! Steam Build ID: 8629104");
	SetConsoleTextAttribute(hConsole, 14);
	il2cppi_log_write("[DaniiGP] [PhasByP] Creating Hooks!");
	not_melon_loader = (String*)il2cpp_string_new(NotMelonLoader.c_str());
	DetourTransactionBegin();
	DetourUpdateThread(GetCurrentThread());
	DetourAttach(&(PVOID&)__400_____________10, TryGetModuleHandleHook);
	DetourAttach(&(PVOID&)File_Exists, File_Exists_Hook);
	DetourAttach(&(PVOID&)Directory_Exists, Directory_Exists_Hook);
	DetourAttach(&(PVOID&)String_Contains, String_Contains_Hook);


	#ifdef _DEBUG
		DetourAttach(&(PVOID&)Application_Quit_1, DoNothingMethod);
		DetourAttach(&(PVOID&)Application_Quit, DoNothingMethod);
		DetourAttach(&(PVOID&)Debug_2_Log, DebugLog);
		DetourAttach(&(PVOID&)Debug_2_LogError, DebugLog);
		DetourAttach(&(PVOID&)Debug_2_LogException, DebugLogException);
		DetourAttach(&(PVOID&)Debug_2_LogWarning, DebugLog);
	#endif
	LONG lError = DetourTransactionCommit();
	if(lError != NO_ERROR)
	{
		SetConsoleTextAttribute(hConsole, 12);
		il2cppi_log_write("[DaniiGP] [PhasByP] Hook creation failed!");
	}
	else
	{
		SetConsoleTextAttribute(hConsole, 10);
		il2cppi_log_write("[DaniiGP] [PhasByP] Hooks created!");
	}
	SetConsoleTextAttribute(hConsole, 15);
}
