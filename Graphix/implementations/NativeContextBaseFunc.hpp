#pragma once

#include "../stdafx.h"

#include "NativeContextBase.hpp"

using namespace NewDisplay;


// --- NativeContextBase -----------------------------------------------------------------------

void load_NativeContextBase(py::module m) {
	py::class_<NativeContextBase>(m, "NativeContextBase")
		.def("IsAntialiasEnabled", &NativeContextBase::IsAntialiasEnabled)
		.def("SetAntialiasEnabled", &NativeContextBase::SetAntialiasEnabled)
		.def("Flush", &NativeContextBase::Flush)
		.def("GetCaps", &NativeContextBase::GetCaps)
		.def("GetResolutionFactor", &NativeContextBase::GetResolutionFactor)
		.def("InvalidateCaches", &NativeContextBase::InvalidateCaches);
		//.def("GetDashImage", &NativeContextBase::GetDashImage)
		//.def("GetPatternImage", &NativeContextBase::GetPatternImage)
		//.def("CreateLowLevelContext", &NativeContextBase::CreateLowLevelContext);
}