#include "pch.h"
#include "EnumToBooleanConverter.h"

using namespace Platform;
using namespace Windows::Foundation;
using namespace Windows::Foundation::Collections;
using namespace Windows::Globalization::NumberFormatting;

using namespace RenderEngine::Converters;

EnumToBooleanConverter::EnumToBooleanConverter()
{
}

EnumToBooleanConverter::~EnumToBooleanConverter()
{
}

Object^ EnumToBooleanConverter::Convert(Object^ value, TypeName targetType, Object^ parameter, String^ language)
{
	return 0;
}

Object^ EnumToBooleanConverter::ConvertBack(Object^ value, TypeName targetType, Object^ parameter, String^ language)
{
	return 0;
}