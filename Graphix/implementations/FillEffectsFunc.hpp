#pragma once

#include "../stdafx.h"

#include "FillEffects.hpp"

using namespace NewDisplay;


// --- override ImageFillEffect ------------------------------------------------------

class PyImageFillEffect : ImageFillEffect
{
public:
	using ImageFillEffect::ImageFillEffect;

	PyImageFillEffect(NativeImage& image, GS::Array<double> &matrix, ImageFillEffect::WrapMode wrapModeHorizontal, ImageFillEffect::WrapMode wrapModeVertical)
		: ImageFillEffect(image, mx, getMatrix(matrix, wrapModeHorizontal), wrapModeVertical) {};

	~PyImageFillEffect() {};

	ImageFillEffect::WrapMode getMatrix(GS::Array<double> &arg, ImageFillEffect::WrapMode mode) {
		int i = { 0 };
		memset(mx, 0, 6);
		for (auto it = arg.Begin(); it != arg.End() && i < 8; it++) {
			mx[i] = *it;
			i++;
		}
		return mode;
	}

private:
	double mx[6];
};


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

	// --- ImageFillEffect -----------------------------------------------------------
	py::class_<ImageFillEffect, PyImageFillEffect, FillEffect>m_imageFillEffect(m, "ImageFillEffect");

	py::enum_<ImageFillEffect::WrapMode>(m_imageFillEffect, "WrapMode")
		.value("Wrap", ImageFillEffect::WrapMode::Wrap)
		.value("MirrorWrap", ImageFillEffect::WrapMode::MirrorWrap)
		.export_values();

	m_imageFillEffect
		.def(py::init_alias<NativeImage &, GS::Array<double> &, ImageFillEffect::WrapMode, ImageFillEffect::WrapMode>());
}