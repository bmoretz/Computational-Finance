//
// FinancialChart.xaml.cpp
// Implementation of the FinancialChart class
//

#include "pch.h"
#include "FinancialChart.xaml.h"
#include "AppShell.xaml.h"

using namespace RenderEngine::Controls;

using namespace Platform;
using namespace Windows;
using namespace Windows::Foundation;
using namespace Windows::Foundation::Collections;
using namespace Windows::UI::Xaml;
using namespace Windows::UI::Xaml::Controls;
using namespace Windows::UI::Xaml::Controls::Primitives;
using namespace Windows::UI::Xaml::Data;
using namespace Windows::UI::Xaml::Input;
using namespace Windows::UI::Xaml::Media;
using namespace Windows::UI::Xaml::Navigation;

namespace RenderEngine
{
    namespace Controls
    {
        FinancialChart::FinancialChart()
        {
            InitializeComponent();

            FinancialChart::Loaded += ref new Windows::UI::Xaml::RoutedEventHandler( this, &FinancialChart::OnLoaded );
            FinancialChart::Unloaded += ref new Windows::UI::Xaml::RoutedEventHandler( this, &FinancialChart::OnUnloaded );
        }

        void FinancialChart::OnLoaded( Platform::Object ^sender, Windows::UI::Xaml::RoutedEventArgs ^e )
        {
        }

        void FinancialChart::OnUnloaded( Platform::Object ^sender, Windows::UI::Xaml::RoutedEventArgs ^e )
        {

        }
		
		void FinancialChart::OnDraw( CanvasControl ^sender, CanvasDrawEventArgs ^e )
        {
			auto background = UI::ColorHelper::FromArgb( 255, 0, 0, 0 );

			e->DrawingSession->Clear( background );

			sender->Invalidate();
        }
    }
}
