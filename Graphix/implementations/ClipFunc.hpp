#pragma once

#include "../stdafx.h"

#include "Clip.hpp"


// --- Clip -----------------------------------------------------------------

void load_Clip(py::module m) {
	py::class_<Clip>(m,"Clip")
		.def(py::init<>())
		.def("Begin", &Clip::Begin)
		.def("MoveTo", &Clip::MoveTo)
		.def("LineTo", &Clip::LineTo)
		.def("End", &Clip::End)
		.def("SetToRect", &Clip::SetToRect)
		.def("IsRect", &Clip::IsRect)
		.def("IsEmpty", &Clip::IsEmpty)
		.def("IsNull", &Clip::IsNull)
		.def("GetBoundRect", &Clip::GetBoundRect)
		.def("GetClipPolyData", &Clip::GetClipPolyData);
}
