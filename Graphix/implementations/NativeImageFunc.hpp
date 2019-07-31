#pragma once

#include "../stdafx.h"

#include <fstream>
#include "NativeImage.hpp"

using namespace NewDisplay;


// --- override NativeImage ---------------------------------------------------------------

class PyNativeImage : NativeImage
{
public:
	using NativeImage::NativeImage;
	
	//PyNativeImage() {};

	PyNativeImage(std::string file, UInt32 size, Encoding format) : NativeImage(OpenImage(), GetSize(), Getformat(file)) {
		
	};

	~PyNativeImage() {
		if(imgData != NULL){
			delete[] imgData;
			imgData = NULL;
		}
	};
	
	char* OpenImage() { return this->imgData; }

	UINT32 GetSize() { return this->imgSize; }

	// --- get image's length,buffer and format -------------------------------------------
	NativeImage::Encoding Getformat(std::string file) {
		std::ifstream is(file, std::ifstream::in);
		is.seekg(0, is.end);												
		this->imgSize = is.tellg();
		is.seekg(0, is.beg);

		this->imgData = new char[imgSize];
		is.read(imgData, imgSize);

		std::string suffixStr = file.substr(file.find_last_of('.') + 1);
		if (suffixStr == "JPEG" || suffixStr == "jpeg") {
			return NativeImage::Encoding::JPEG;
		}
		else if (suffixStr == "PNG" || suffixStr == "png") {
			return NativeImage::Encoding::PNG;
		}
	}

private:
	char *imgData;
	UINT32 imgSize;
	//UINT32 imgFormat;
};


// --- NativeImage ------------------------------------------------------------------------

void load_NativeImage(py::module m) {
	py::class_<NativeImage, PyNativeImage>m_nativeImage(m, "NativeImage"/*, pybind11::dynamic_attr()*/);

	py::enum_<NativeImage::Encoding>(m_nativeImage, "Encoding")
		.value("JPEG", NativeImage::Encoding::JPEG)
		.value("PNG", NativeImage::Encoding::PNG)
		.export_values();

	m_nativeImage
		//.def(py::init<>())
		.def(py::init<UInt32, UInt32, NativeImage &, double>(),
			py::arg("width"),
			py::arg("height"), 
			py::arg("imageForColorData"), 
			py::arg("resolutionFactor") = 1.0 )
		.def(py::init_alias<std::string, UInt32, NativeImage::Encoding>())
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