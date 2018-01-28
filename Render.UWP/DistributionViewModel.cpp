#include "pch.h"
#include "DistributionViewModel.h"
#include "DelegateCommand.h"

using namespace Platform;
using namespace Platform::Collections;
using namespace Windows::UI::Xaml;
using namespace Windows::UI::Xaml::Input;
using namespace Windows::UI::Xaml::Navigation;
using namespace Windows::Foundation::Collections;

using namespace RenderEngine;
using namespace RenderEngine::Common;
using namespace RenderEngine::ViewModels;

DistributionViewModel::DistributionViewModel()
{
	m_renderCommand =
		ref new DelegateCommand( ref new ExecuteDelegate(this, &DistributionViewModel::Render ), nullptr);

}

IVector<double>^ DistributionViewModel::getDistribution( int points )
{
	IVector<double>^ out_points;
	
	switch( DataType )
	{
		case DistributionType::Normal:
		{
			auto out = data.gaussianData( points, 0, 1);

			// sort(out.begin(), out.end());

			out_points = ref new Vector<double>( std::move( out ) );
		} break;

		case DistributionType::Log:
		{
			auto out = data.logNormalData(points, 0, 1);

			sort(out.begin(), out.end());

			out_points = ref new Vector<double>(std::move(out));
		} break;
	}

	return out_points;
}

void DistributionViewModel::Render( Object^ parameter )
{
	
}