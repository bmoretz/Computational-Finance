//
// FinancialChart.xaml.h
// Declaration of the FinancialChart class
//

#pragma once

#include "FinancialChart.g.h"

using namespace Windows::Foundation::Collections;
using namespace Microsoft::Graphics::Canvas::UI::Xaml;

namespace RenderEngine
{
	namespace Controls
	{
		[Windows::Foundation::Metadata::WebHostHidden]
		public ref class FinancialChart sealed
		{
		public:

			FinancialChart();

			void OnLoaded( Platform::Object ^sender, Windows::UI::Xaml::RoutedEventArgs ^e );
			void OnUnloaded( Platform::Object ^sender, Windows::UI::Xaml::RoutedEventArgs ^e );

			void OnDraw( CanvasControl ^sender, CanvasDrawEventArgs ^args );

			void setPoints( IVector<double>^ points );

        private:
			IVector<double>^ m_points;
		};
	}
}