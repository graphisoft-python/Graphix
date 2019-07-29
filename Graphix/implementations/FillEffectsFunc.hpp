#pragma once

#include "../stdafx.h"

#include "FillEffects.hpp"

using namespace NewDisplay;
using namespace Gfx;
using namespace GS;


// --- FillEffect --------------------------------------------------------------------

void load_FillEffect(py::module m) {
	py::class_<FillEffect>(m, "FillEffect");
}


// --- FillEffectEX ------------------------------------------------------------------

void load_FillEffectEX(py::module m) {
	// --- Linear Gradient effect ----------------------------------------------------
	py::class_<LinearGradientFillEffect, FillEffect>(m, "LinearGradientFillEffect")
		.def(py::init<Color, Color, Point<float> &, Point<float> &>());

	// --- Radial Gradient effect --------------------------------------------------
	py::class_<RadialGradientFillEffect, FillEffect>(m, "RadialGradientFillEffect")
		.def(py::init<Color, Color, Point<float> &, double, double>());

	// --- Image effect ------------------------------------------------------------
	// wait for writting......
}