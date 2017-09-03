#include "stdafx.h"
#include "Converters.h"

using namespace std;

const wstring BotsEngine::Tests::StringToWstring(const string & data)
{
	wstring result;
	result.resize(data.length(), L'\0');
	mbstowcs(&result[0], data.c_str(), data.size());
	return result;
}
