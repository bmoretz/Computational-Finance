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

using namespace Windows::Foundation::Numerics;

using namespace Microsoft::Graphics::Canvas::Text;
using namespace Microsoft::Graphics::Canvas::Geometry;
using namespace Microsoft::Graphics::Canvas::UI::Xaml;

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
		
		void FinancialChart::setPoints( IVector<double>^ points )
		{
			m_points = points;
		}

		void FinancialChart::OnDraw( CanvasControl ^canvas, CanvasDrawEventArgs ^e )
		{
			auto background = UI::ColorHelper::FromArgb( 0, 0, 0, 0 );

			e->DrawingSession->Clear( background );

			auto width = canvas->ActualWidth;
			auto height = canvas->ActualHeight;

			auto midWidth = ( float )( width * .5 );
			auto midHeight = ( float )( height * .5 );

			{
				// X-Axis
				CanvasPathBuilder^ cpb = ref new CanvasPathBuilder( e->DrawingSession );

				cpb->BeginFigure(float2( 0, midHeight ));
				cpb->AddLine(float2( width, midHeight ));
				cpb->EndFigure( CanvasFigureLoop::Open );

				e->DrawingSession->DrawGeometry( CanvasGeometry::CreatePath( cpb ), UI::Colors::Gray, 1);
				e->DrawingSession->DrawText( "0", 0, midHeight, UI::Colors::Gray );
                e->DrawingSession->DrawText(canvas->ActualWidth.ToString(), width - 50, midHeight - 30, UI::Colors::Gray);
			}

			{
				// Y-Axis
				CanvasPathBuilder^ cpb = ref new CanvasPathBuilder( e->DrawingSession );

				cpb->BeginFigure( float2( midWidth, 0 ) );
				cpb->AddLine( float2( midWidth, width ) );
				cpb->EndFigure( CanvasFigureLoop::Open );

				cpb->BeginFigure( float2( midWidth - 3, 10 ) );
				cpb->AddLine( float2( midWidth, 0 ) );
				cpb->AddLine( float2( midWidth + 3, 10 ) );
				cpb->EndFigure( CanvasFigureLoop::Open );

				e->DrawingSession->DrawGeometry(CanvasGeometry::CreatePath( cpb ), UI::Colors::Gray, 1);
				e->DrawingSession->DrawText("0", midWidth + 5, height - 30, UI::Colors::Gray);
				e->DrawingSession->DrawText("1", midWidth + 5, 5, UI::Colors::Gray);
			}

			if( m_points != nullptr )
			{
				CanvasPathBuilder^ cpb = ref new CanvasPathBuilder(e->DrawingSession);

				cpb->BeginFigure(float2(0, midHeight));

				for( auto index = 0; index < m_points->Size; index++ )
				{
					auto x = m_points->GetAt(index) * midWidth;
					auto y = m_points->GetAt( index ) * midHeight;
					
					cpb->AddLine( float2( x, y ) );
				}

				cpb->EndFigure( CanvasFigureLoop::Open );
				e->DrawingSession->DrawGeometry(CanvasGeometry::CreatePath(cpb), UI::Colors::Black , 1 );
			}

			canvas->Invalidate();
		}
	}
}
