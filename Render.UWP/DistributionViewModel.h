#pragma once

#include "BindableBase.h"

#include "../Engine/DistrubutionData.h"

using namespace Platform;
using namespace Windows::UI::Xaml::Input;

namespace RenderEngine
{
	public enum class DistributionType
	{
		Normal,
		Log,
		Exponential,
		ChiSquared,
	};

	namespace ViewModels
	{
		public ref class DistributionViewModel sealed : 
			public Common::BindableBase
		{
		internal:

		public:
			DistributionViewModel();

			property DistributionType DataType;
			
			property Windows::Foundation::Collections::IObservableVector<Platform::String^>^ DistributionTypes
			{
				Windows::Foundation::Collections::IObservableVector<Platform::String^>^ get()
				{
					if( m_DistributionTypes == nullptr )
					{
						m_DistributionTypes = ref new Platform::Collections::Vector<Platform::String^>();

						m_DistributionTypes->Append( DistributionType::Normal.ToString() );
						m_DistributionTypes->Append( DistributionType::Log.ToString() );
						m_DistributionTypes->Append( DistributionType::Exponential.ToString() );
						m_DistributionTypes->Append( DistributionType::ChiSquared.ToString() );
					}
					
					return m_DistributionTypes;
				}
			}
			
			property Windows::UI::Xaml::Input::ICommand^ RenderCommand
			{
				Windows::UI::Xaml::Input::ICommand^ get()
				{
					return m_renderCommand;
				};
			}

			Windows::Foundation::Collections::IVector<double>^ getDistribution( int points );

		private:
			NumericalMethods::DistrubutionData data;
			DistributionType m_distributionType;

			Platform::Collections::Vector<Platform::String^>^ m_DistributionTypes;

			Windows::UI::Xaml::Input::ICommand^ m_renderCommand;

			void Render( Platform:: Object^ parameter );
		};
	}
}