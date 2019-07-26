// Graphix.cpp : 定义 DLL 应用程序的导出函数。
//

#include "..\stdafx.h"

#include "DGWImageCache.hpp"
#include "DGUtility.hpp"



GS::Array<float> ArrayCast(GS::Array<float> ary) {
	for (auto &value : ary) {
		value += 0.3;
	}
	return ary;
}

PYBIND11_MODULE(Graphix, m) {

	m.def("version", []() {	return "version 0.0.1"; });

	// --- Add bindings here ------------------------------------------------------------------

	// --- Test

	m.def("ArrayCast", ArrayCast);

	// --- Add bindings end -------------------------------------------------------------------
}