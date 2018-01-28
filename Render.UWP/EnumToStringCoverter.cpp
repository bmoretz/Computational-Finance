#include "pch.h"
#include "EnumToStringCoverter.h"

using namespace Platform;
using namespace Windows::Foundation;
using namespace Windows::Foundation::Collections;
using namespace Windows::Globalization::NumberFormatting;

using namespace RenderEngine::Converters;

EnumToStringCoverter::EnumToStringCoverter()
{
}

EnumToStringCoverter::~EnumToStringCoverter()
{
}

Object^ EnumToStringCoverter::Convert(Object^ value, TypeName targetType, Object^ parameter, String^ language)
{
	return value->ToString();
}

Object^ EnumToStringCoverter::ConvertBack(Object^ value, TypeName targetType, Object^ parameter, String^ language)
{
	return 0;
}