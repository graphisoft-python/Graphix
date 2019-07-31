#pragma once

#include "../stdafx.h"

#include "BlitEffects.hpp"

using namespace NewDisplay;


// --- BlitEffect ---------------------------------------------------------------------

void load_BlitEffect(py::module m) {
	py::class_<BlitEffect>(m, "BlitEffect")
		.def("Clone", &BlitEffect::Clone, py::return_value_policy::reference);
}


// --- FalseColorBlitEffect -----------------------------------------------------------

void load_FalseColorBlitEffect(py::module m) {
	py::class_<FalseColorBlitEffect, BlitEffect>(m, "FalseColorBlitEffect")
		.def(py::init<Gfx::Color, Gfx::Color>())
		.def("Clone", &FalseColorBlitEffect::Clone, py::return_value_policy::reference);
}