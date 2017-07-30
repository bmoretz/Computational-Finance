#pragma once

#include "Distributions.g.h"
#include "DistributionViewModel.h"

namespace RenderEngine
{
	namespace Views
	{
		/// <summary>
		/// A view for generating random distributions of data.
		/// </summary>
		[Windows::Foundation::Metadata::WebHostHidden]
        public ref class Distributions sealed : Windows::UI::Xaml::Data::INotifyPropertyChanged
		{
		private:
			RenderEngine::ViewModels::DistributionViewModel^ viewModel;

		public:
			Distributions();

			virtual event Windows::UI::Xaml::Data::PropertyChangedEventHandler^ PropertyChanged;

            property int ValuesPerFrame;

			property RenderEngine::ViewModels::DistributionViewModel^ ViewModel
			{
				RenderEngine::ViewModels::DistributionViewModel^ get() { return this->viewModel; };
			}

		protected:
			void OnPropertyChanged( Platform::String^ propertyName );

			void DrawClick(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);

		};
	}
}