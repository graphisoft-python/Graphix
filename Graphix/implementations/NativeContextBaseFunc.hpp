#pragma once

#include "../stdafx.h"

#include <Win32Interface.hpp>
#include "NativeContextBase.hpp"
#include "GraphixDefinitions.hpp"		// GRAPHIX_DLL_EXPORT
#include "Pattern.hpp"					// Gfx::Pattern
#include "CountedPtr.hpp"
#include "Rect.hpp"

using namespace NewDisplay;


// --- Filtering -------------------------------------------------------------------------------

void load_Filtering(py::module m) {
	py::enum_<Filtering>(m, "Filtering")
		.value("NearestPixel", Filtering::NearestPixel)
		.value("Bilinear", Filtering::Bilinear)
		.value("HighQuality", Filtering::HighQuality)
		.value("DefaultFilter", Filtering::DefaultFilter)
		.export_values();
}


// --- NativeContextBase -----------------------------------------------------------------------

void load_NativeContextBase(py::module m) {
	py::class_<NativeContextBase>(m, "NativeContextBase")
		.def("IsAntialiasEnabled", &NativeContextBase::IsAntialiasEnabled)
		.def("SetAntialiasEnabled", &NativeContextBase::SetAntialiasEnabled)
		.def("Flush", &NativeContextBase::Flush)
		.def("GetCaps", &NativeContextBase::GetCaps)
		.def("GetResolutionFactor", &NativeContextBase::GetResolutionFactor)
		.def("InvalidateCaches", &NativeContextBase::InvalidateCaches)
		.def("GetDashImage", &NativeContextBase::GetDashImage,
			py::arg("dash"),
			py::arg("scale") = 1.0f, 
			py::arg("maxImageWidth") = 4096, 
			py::arg("dashColorArgb") = 0xFFFFFFFF,
			py::arg("spaceColorArgb") = 0x0)
		.def("GetPatternImage", &NativeContextBase::GetPatternImage,
			py::arg("pattern"),
			py::arg("scale") = 1.0f,
			py::arg("foreColorArgb") = 0xFFFFFFFF,
			py::arg("backColorArgb") = 0x0)
		//.def("CreateLowLevelContext", &NativeContextBase::CreateLowLevelContext,py::return_value_policy::reference)
		;
}