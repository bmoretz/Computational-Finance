#include "pch.h"
#include "Distributions.xaml.h"
#include "FinancialChart.xaml.h"

#include "DistributionViewModel.h"

using namespace Platform;
using namespace Windows::Foundation;
using namespace Windows::Foundation::Collections;
using namespace Windows::UI::Xaml;
using namespace Windows::UI::Xaml::Controls;
using namespace Windows::UI::Xaml::Controls::Primitives;
using namespace Windows::UI::Xaml::Data;
using namespace Windows::UI::Xaml::Input;
using namespace Windows::UI::Xaml::Interop;
using namespace Windows::UI::Xaml::Media;
using namespace Windows::UI::Xaml::Navigation;
using namespace RenderEngine::Views;
using namespace RenderEngine::ViewModels;

using namespace RenderEngine::ViewModels;

Distributions::Distributions()
{
	InitializeComponent();

	this->viewModel = ref new DistributionViewModel();
}

void Distributions::DrawClick( Object ^ sender, RoutedEventArgs ^ e )
{
	auto points = viewModel->getDistribution( display->ActualWidth );

	display->setPoints( points );
}

void Distributions::DistributionClick( Object ^ sender, ItemClickEventArgs ^ e )
{
	viewModel->DataType = (DistributionType)e->ClickedItem;
}

void Distributions::CommandBar_Opening(Platform::Object^ sender, Platform::Object^ e)
{
}


void Distributions::CommandBar_Closed(Platform::Object^ sender, Platform::Object^ e)
{
}