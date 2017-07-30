#include "pch.h"
#include "DistributionViewModel.h"

using namespace Platform;
using namespace Platform::Collections;
using namespace Windows::Foundation::Collections;

using namespace RenderEngine;
using namespace RenderEngine::ViewModels;

DistributionViewModel::DistributionViewModel()
{
}

IVector<double>^ DistributionViewModel::getDistribution( DistributionType type, int points )
{
	IVector<double>^ out_points;
	
	switch( type )
	{
		case DistributionType::Normal:
		{
			auto out = data.gaussianData( 1000, 0, 1);

			out_points = ref new Vector<double>(std::move(out));
		} break;
	}

	return out_points;
}
