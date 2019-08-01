#pragma once

#include "../stdafx.h"

#include "NativeImage.hpp"

using namespace NewDisplay;


// --- override NativeImage ---------------------------------------------------------------

class PyNativeImage : NativeImage
{
public:
	using NativeImage::NativeImage;
	
	PyNativeImage() : NativeImage() {};
	PyNativeImage(UInt32 width, UInt32 height, NativeImage &imageForColorData, double resolutionFactor = 1.0) : NativeImage(width, height, imageForColorData, resolutionFactor) {};
	PyNativeImage(std::string &file) : NativeImage(getData(), GetSize(), Getformat(file)) {};

	~PyNativeImage() {
		if(imgData != nullptr){
			delete[] imgData;
			imgData = nullptr;
		}
	};
	
	char* getData() { return this->imgData; };

	UINT32 GetSize() { return this->imgSize; };

	// --- get image's length,buffer and format -------------------------------------------
	NativeImage::Encoding Getformat(std::string &file) {
		// wait for writting...

		return NativeImage::Encoding::PNG;
	};

private:
	char *imgData;
	UINT32 imgSize;
};


// --- NativeImage ------------------------------------------------------------------------

void load_NativeImage(py::module m) {
	py::class_<NativeImage, PyNativeImage>m_nativeImage(m, "NativeImage"/*, pybind11::dynamic_attr()*/);

	py::enum_<NativeImage::Encoding>(m_nativeImage, "Encoding")
		.value("JPEG", NativeImage::Encoding::JPEG)
		.value("PNG", NativeImage::Encoding::PNG)
		.export_values();

	m_nativeImage
		.def(py::init_alias<>())
		.def(py::init_alias<UInt32, UInt32, NativeImage &, double>(),
			py::arg("width"),
			py::arg("height"), 
			py::arg("imageForColorData"), 
			py::arg("resolutionFactor") = 1.0 )
		.def(py::init_alias<std::string &>())
		.def("GetWidth", &NativeImage::GetWidth)
		.def("GetHeight", &NativeImage::GetHeight)
		.def("GetResolutionFactor", &NativeImage::GetResolutionFactor)
		.def("IsPerPixelAlpha", &NativeImage::IsPerPixelAlpha)
		.def("GetColorKey", &NativeImage::GetColorKey)
		.def("SetColorKey", &NativeImage::SetColorKey)
		.def("GetContext", &NativeImage::GetContext)
		.def("ReleaseContext", &NativeImage::ReleaseContext)
		//.def("Encode", &NativeImage::Encode)
		.def("CreateCopy", &NativeImage::CreateCopy)
		.def("Resize", &NativeImage::Resize);
}