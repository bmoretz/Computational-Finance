#pragma once

#include "pch.h" 

using namespace Platform;
using namespace Windows::UI::Xaml::Data;
using namespace Windows::UI::Xaml::Interop;

namespace RenderEngine
{
	namespace Converters
	{
		public ref class EnumDescriptionCoverter sealed : IValueConverter
		{
		public:
			EnumDescriptionCoverter();
			virtual ~EnumDescriptionCoverter();

			virtual Object^ Convert(Object^ value, TypeName targetType, Object^ parameter, String^ language);
			virtual Object^ ConvertBack(Object^ value, TypeName targetType, Object^ parameter, String^ language);
		};
	}
}
