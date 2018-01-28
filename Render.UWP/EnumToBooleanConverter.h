#pragma once

#include "pch.h" 

using namespace Platform;
using namespace Windows::UI::Xaml::Data;
using namespace Windows::UI::Xaml::Interop;

namespace RenderEngine
{
	namespace Converters
	{
		public ref class EnumToBooleanConverter sealed : IValueConverter
		{
		public:
			EnumToBooleanConverter();
			virtual ~EnumToBooleanConverter();

			virtual Object^ Convert( Object^ value, TypeName targetType, Object^ parameter, String^ language );
			virtual Object^ ConvertBack( Object^ value, TypeName targetType, Object^ parameter, String^ language );
		};
	}
}
