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

            FinancialChart::Loaded += 
				ref new Windows::UI::Xaml::RoutedEventHandler( this, &FinancialChart::OnLoaded );
            
        	FinancialChart::Unloaded += 
				ref new Windows::UI::Xaml::RoutedEventHandler( this, &FinancialChart::OnUnloaded );
        }

        void FinancialChart::OnLoaded( Platform::Object ^sender, Windows::UI::Xaml::RoutedEventArgs ^e )
        {
        }

        void FinancialChart::OnUnloaded( Platform::Object ^sender, Windows::UI::Xaml::RoutedEventArgs ^e )
        {

        }
		
		void FinancialChart::setPoints(IVector<double>^ points)
        {
			m_points = points;
        }

		void FinancialChart::OnDraw( CanvasControl ^sender, CanvasDrawEventArgs ^e )
        {
			auto background = UI::ColorHelper::FromArgb( 0, 0, 0, 0 );

			e->DrawingSession->Clear( background );

			if (m_points != nullptr)
			{
				for (auto index = 0; index < m_points->Size; index++)
				{
					auto x = index;
					auto y = m_points->GetAt(index);

					e->DrawingSession->DrawLine(x, y, x, y, UI::ColorHelper::FromArgb(255, 255, 255, 255), 10 );
				}
			}

			sender->Invalidate();
        }
    }
}