// Graphix.cpp : 定义 DLL 应用程序的导出函数。
//

#include "..\stdafx.h"

#include "DGWImageCache.hpp"
#include "DGUtility.hpp"


PYBIND11_MODULE(Graphix, m) {

	m.def("version", []() {	return "version 0.0.1"; });

	// --- Add bindings here ------------------------------------------------------------------

	// --- Test

	

	// --- Add bindings end -------------------------------------------------------------------
}