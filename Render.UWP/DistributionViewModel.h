#pragma once

#include "../Engine/DistrubutionData.h"

using namespace Platform::Metadata;

namespace RenderEngine
{
	[Flags]
	public enum class DistributionType
		: unsigned int
	{
		Normal = 0x0,
		Log = 0x2
	};

	namespace ViewModels
	{
		public ref class DistributionViewModel sealed
		{
		private:
			NumericalMethods::DistrubutionData data;
		public:
			DistributionViewModel();

			property DistributionType DataType;

			Windows::Foundation::Collections::IVector<double>^ getDistribution(DistributionType type, int points );
		};
	}
}