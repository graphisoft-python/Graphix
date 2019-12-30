#pragma once

#include "../stdafx.h"

#include "NativeImage.hpp"
#include "Color.hpp"

#include "GXImage.hpp"

using namespace NewDisplay;

NativeImage _openNativeImage(GS::UniString &file, double resolutionFactor) {
	ExportFuns *extFuncs = GetExtFuncs();
	IO::RelativeLocation _relativePath(file);
	IO::Location _appBaseDir = extFuncs->ApplicationPath();
	_appBaseDir.AppendToLocal(_relativePath);

	GX::Image image(_appBaseDir);

	if (image.IsEmpty()) {
		throw py::value_error("Path Error.");
	}
	else {
		return image.ToNativeImage(resolutionFactor);
	}
}


// --- NativeImage ------------------------------------------------------------------------

py::class_< NativeImage> init_NativeImage(py::module m) {
	py::class_<NativeImage> m_nativeImage(m, "NativeImage"/*, pybind11::dynamic_attr()*/);

	return m_nativeImage;
}

void load_NativeImage(py::class_< NativeImage> m_nativeImage) {

	m_nativeImage
		.def(py::init<>())
		.def(py::init<UInt32, UInt32, NativeImage &, double>(),
			py::arg("width"),
			py::arg("height"), 
			py::arg("imageForColorData"), 
			py::arg("resolutionFactor") = 1.0 )
		.def(py::init([](UInt32 width, UInt32 height, UInt32 bitDepth, bool perPixelAlpha = false, UInt32 bytesPerRow = 0, bool enableMemoryOptimization = true, double resolutionFactor = 1.0) {
		return new NativeImage(width, height, bitDepth, nullptr, perPixelAlpha, bytesPerRow, enableMemoryOptimization, resolutionFactor);
		}),py::arg("width"),
			py::arg("height"),
			py::arg("bitDepth"),
			py::arg("perPixelAlpha")=false,
			py::arg("bytesPerRow")=0,
			py::arg("enableMemoryOptimization")=true,
			py::arg("resolutionFactor")=1.0)
		.def(py::init<>([](GS::UniString &file) {
			return _openNativeImage(file, 1.0);
		}))
		.def(py::init<>([](GS::UniString &file,double resolutionFactor) {
			return _openNativeImage(file, resolutionFactor);
		}))
		.def("GetWidth", &NativeImage::GetWidth)
		.def("GetHeight", &NativeImage::GetHeight)
		.def("GetResolutionFactor", &NativeImage::GetResolutionFactor)
		.def("IsPerPixelAlpha", &NativeImage::IsPerPixelAlpha)
		.def("GetColorKey", [](NativeImage &self) {
			unsigned char red, green, blue;
			self.GetColorKey(red, green, blue);
			return new Gfx::Color(red, green, blue);
	
		})
		.def("SetColorKey", [](NativeImage &self, Gfx::Color &color) {
			self.SetColorKey(color.GetRed(), color.GetGreen(), color.GetBlue());
		})
		.def("GetContext", &NativeImage::GetContext)
		.def("ReleaseContext", &NativeImage::ReleaseContext)
		.def("CreateCopy", &NativeImage::CreateCopy)
		.def("Resize", &NativeImage::Resize);

}