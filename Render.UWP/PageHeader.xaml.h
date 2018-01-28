#pragma once

#include "PageHeader.g.h"
#include "AppShell.xaml.h"

using namespace Windows::Foundation;
using namespace Windows::UI::Xaml;

namespace RenderEngine
{
    namespace Controls
    {
        [Windows::Foundation::Metadata::WebHostHidden]
        public ref class PageHeader sealed
        {
        public:
            PageHeader();

            void OnLoaded( Platform::Object ^sender, Windows::UI::Xaml::RoutedEventArgs ^e );
            void OnUnloaded( Platform::Object ^sender, Windows::UI::Xaml::RoutedEventArgs ^e );

            static property DependencyProperty^ HeaderContentProperty
            {
                DependencyProperty^ get() { return m_headerContentProperty; }
            }

            property UIElement^ HeaderContent
            {
                UIElement^ get() { return ( UIElement^ )GetValue( m_headerContentProperty ); }
                void set( UIElement^ value ) { SetValue( m_headerContentProperty, value ); }
            }

        private:
            
        	static DependencyProperty^ m_headerContentProperty;
			Windows::Foundation::EventRegistrationToken m_toggleButtonRectChangedToken;

            void Current_TogglePaneButtonSizeChanged( AppShell^ sender, Rect e );
        };
    }
}