#pragma once

#include "../stdafx.h"

#include "Point.hpp"
#include "DisplayArc.hpp"

using namespace NewDisplay;


// --- DisplayArc ------------------------------------------------------------------------

void load_DisplayArc(py::module m) {
	py::class_<DisplayArc>m_displayArc(m, "DisplayArc");

	py::enum_<DisplayArc::Reflection>(m_displayArc, "Reflection")
		.value("NotReflected", DisplayArc::Reflection::NotReflected)
		.value("Reflected", DisplayArc::Reflection::Reflected)
		.export_values();

	m_displayArc
		.def("IsFullEllipse", &DisplayArc::IsFullEllipse)
		.def("GetCenter", &DisplayArc::GetCenter)
		.def("GetBegCoordinate", &DisplayArc::GetBegCoordinate)
		.def("GetEndCoordinate", &DisplayArc::GetEndCoordinate)
		.def("GetBegAngle", &DisplayArc::GetBegAngle)
		.def("GetEndAngle", &DisplayArc::GetEndAngle)
		.def("GetDeltaAngle", &DisplayArc::GetDeltaAngle)
		.def("GetXRadius", &DisplayArc::GetXRadius)
		.def("GetYRadius", &DisplayArc::GetYRadius)
		.def("GetFullEllipseBoundingRect", &DisplayArc::GetFullEllipseBoundingRect)
		.def("GetSegmentation", &DisplayArc::GetSegmentation)
		.def("Scale", &DisplayArc::Scale)
		.def_static("CreateFullCircle", &DisplayArc::CreateFullCircle)
		.def_static("CreateCircularArc", &DisplayArc::CreateCircularArc)
		.def_static("CreateFullEllipse", (DisplayArc (*)(const GS::Point<float> &, float, float)) &DisplayArc::CreateFullEllipse)
		.def_static("CreateFullEllipse", (DisplayArc (*)(float, float, float, float)) &DisplayArc::CreateFullEllipse)
		.def_static("CreateEllipticArcWithEndPoints", &DisplayArc::CreateEllipticArcWithEndPoints)
		.def_static("CreateEllipticArc", (DisplayArc (*)(const GS::Point<float> &, float, float, float, float)) &DisplayArc::CreateEllipticArc)
		.def_static("CreateEllipticArc", (DisplayArc (*)(float, float, float, float, float, float)) &DisplayArc::CreateEllipticArc);
}