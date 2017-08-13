#include "pch.h"
#include "Distributions.xaml.h"
#include "FinancialChart.xaml.h"

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

Distributions::Distributions()
{
	InitializeComponent();

	this->viewModel = ref new DistributionViewModel();
}

void RenderEngine::Views::Distributions::DrawClick(Platform::Object ^ sender, Windows::UI::Xaml::RoutedEventArgs ^ e)
{
	auto points = viewModel->getDistribution( display->ActualWidth );

	display->setPoints( points );
}