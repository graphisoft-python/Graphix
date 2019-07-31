#pragma once

#include "../stdafx.h"

#include "FillEffects.hpp"

using namespace NewDisplay;


// --- FillEffect --------------------------------------------------------------------

void load_FillEffect(py::module m) {
	// --- FillEffect ----------------------------------------------------------------
	py::class_<FillEffect>(m, "FillEffect");
}


// --- FillEffectEX ------------------------------------------------------------------

void load_FillEffectEX(py::module m) {
	// --- Linear Gradient effect ----------------------------------------------------
	py::class_<LinearGradientFillEffect, FillEffect>(m, "LinearGradientFillEffect")
		.def(py::init< Gfx::Color, Gfx::Color, GS::Point<float> &, GS::Point<float> &>());

	// --- Radial Gradient effect ----------------------------------------------------
	py::class_<RadialGradientFillEffect, FillEffect>(m, "RadialGradientFillEffect")
		.def(py::init<Gfx::Color, Gfx::Color, GS::Point<float> &, double, double>());

	// --- Image effect --------------------------------------------------------------
	// wait for writting......
}