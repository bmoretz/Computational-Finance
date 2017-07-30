#pragma once

#include "pch.h"

using namespace Platform;
using namespace Windows::UI::Xaml::Interop;

namespace RenderEngine
{
	namespace Converters
	{
		public ref class EnumToBooleanConverter sealed : Windows::UI::Xaml::Data::IValueConverter
		{
		public:
			EnumToBooleanConverter();

			virtual Object^ Convert(Object^ value, TypeName targetType, Object^ parameter, String^ language)
			{
				return value == parameter;
			}

			virtual Object^ ConvertBack(Object^ value, TypeName targetType, Object^ parameter, String^ language)
			{
				return value == true ? parameter : nullptr;
			}
		};
	}
}