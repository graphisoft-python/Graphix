#pragma once

#include "../stdafx.h"

#include "IBlit.hpp"

using namespace NewDisplay;


// --- BlendMode --------------------------------------------------------------------------

void load_BlendMode(py::module m) {
	py::enum_<BlendMode>(m, "BlendMode")
		.value("SrcBlend", BlendMode::SrcBlend)
		.value("SrcCopy", BlendMode::SrcCopy)
		.export_values();
}