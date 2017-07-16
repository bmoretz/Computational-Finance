//
// PageHeader.xaml.cpp
// Implementation of the PageHeader class
//

#include "pch.h"
#include "PageHeader.xaml.h"

using namespace Platform;
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
        DependencyProperty^ PageHeader::m_headerContentProperty = DependencyProperty::Register
    	(
            "HeaderContent",
            TypeName( UIElement::typeid ),
            TypeName( PageHeader::typeid ),
            ref new PropertyMetadata( nullptr )
        );

        PageHeader::PageHeader()
        {
            InitializeComponent();

            PageHeader::Loaded += ref new Windows::UI::Xaml::RoutedEventHandler( this, &PageHeader::OnLoaded );
            PageHeader::Unloaded += ref new Windows::UI::Xaml::RoutedEventHandler( this, &PageHeader::OnUnloaded );
        }

        void PageHeader::OnLoaded( Platform::Object ^sender, Windows::UI::Xaml::RoutedEventArgs ^e )
        {
            m_toggleButtonRectChangedToken = AppShell::Current->TogglePaneButtonRectChanged +=
                ref new TypedEventHandler<AppShell^, Rect>( this, &PageHeader::Current_TogglePaneButtonSizeChanged );

            titleBar->Margin = Thickness( AppShell::Current->TogglePaneButtonRect.Right, 0, 0, 0 );
        }

        void PageHeader::OnUnloaded( Platform::Object ^sender, Windows::UI::Xaml::RoutedEventArgs ^e )
        {
			AppShell::Current->TogglePaneButtonRectChanged -= m_toggleButtonRectChangedToken;
        }

        void PageHeader::Current_TogglePaneButtonSizeChanged( AppShell^ sender, Rect e )
        {
            titleBar->Margin = Thickness( e.Right, 0, 0, 0 );
        }
    }
}