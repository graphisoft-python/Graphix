#pragma once

#include "../stdafx.h"

#include "NativeContext.hpp"

using namespace NewDisplay;
using namespace Gfx;


// --- LineCapType and TextQuality ---------------------------------------------------------

void load_NativeContextEnum(py::module m) {
	py::enum_<LineCapType>(m, "LineCapType")
		.value("LCT_Round", LineCapType::LCT_Round)
		.value("LCT_Square", LineCapType::LCT_Square)
		.export_values();

	py::enum_<TextQuality>(m, "TextQuality")
		.value("TQ_NoAntialias", TextQuality::TQ_NoAntialias)
		.value("TQ_Antialias", TextQuality::TQ_Antialias)
		.value("TQ_Proof", TextQuality::TQ_Proof)
		.value("TQ_SystemDefault", TextQuality::TQ_SystemDefault)
		.export_values();
}


// --- NativeContext -----------------------------------------------------------------------

void load_NativeContextBase(py::module m) {
	py::class_<NativeContext, NativeContextBase>m_nativeContext(m, "NativeContext");

	py::enum_<NativeContext::ExternalType>(m_nativeContext, "ExternalType")
		.value("T_Default", NativeContext::ExternalType::T_Default)
		.value("T_HDC", NativeContext::ExternalType::T_HDC)
		.value("T_HDCForThemedDrawing", NativeContext::ExternalType::T_HDCForThemedDrawing)
		.value("T_Graphics", NativeContext::ExternalType::T_Graphics)
		.value("T_OpenGL", NativeContext::ExternalType::T_OpenGL)
		.export_values();

	m_nativeContext
		.def(py::init<NativeContextBase &>())
		// --- Drawing functions
		.def("SetForeColor", (void (NativeContext::*)(unsigned char, unsigned char, unsigned char, unsigned char))&NativeContext::SetForeColor,
			py::arg("red"),
			py::arg("green"),
			py::arg("blue"),
			py::arg("alpha") = 255)
		.def("SetForeColor", (void (NativeContext::*)(const Color &))&NativeContext::SetForeColor)
		.def("SetBackColor", (void (NativeContext::*)(unsigned char, unsigned char, unsigned char, unsigned char))&NativeContext::SetBackColor,
			py::arg("red"),
			py::arg("green"),
			py::arg("blue"),
			py::arg("alpha") = 255)
		.def("SetBackColor", (void (NativeContext::*)(const Color &))&NativeContext::SetBackColor)
		.def("SetLineWidth", &NativeContext::SetLineWidth)
		.def("SetLineCap", &NativeContext::SetLineCap)
		.def("SetLineDashPattern", &NativeContext::SetLineDashPattern)
		.def("SetLinePatternOffset", &NativeContext::SetLinePatternOffset)
		.def("SetFillPattern", &NativeContext::SetFillPattern)
		.def("SetBlendMode", &NativeContext::SetBlendMode)

		// --- Line drawing
		.def("MoveTo", &NativeContext::MoveTo)
		.def("LineTo", &NativeContext::LineTo)
		.def("ArcTo", &NativeContext::ArcTo)
		.def("Arc", &NativeContext::Arc)
		.def("FrameRect", &NativeContext::FrameRect)

		// --- Fill drawing
		.def("FillRect", &NativeContext::FillRect, 
			py::arg("left"), 
			py::arg("top"), 
			py::arg("right"), 
			py::arg("bottom"), 
			py::arg("red"), 
			py::arg("green"), 
			py::arg("blue"), 
			py::arg("alpha") = 255)
		.def("BeginPolygon", &NativeContext::BeginPolygon,
			py::arg("effect") = nullptr)
		.def("EndPolygon", &NativeContext::EndPolygon)

		// --- Text drawing
		//.def("DrawUIText", &NativeContext::DrawUIText)
		//.def("DrawPlainText", &NativeContext::DrawPlainText)
		//.def("DrawPlainMLText", &NativeContext::DrawPlainMLText)
		//.def("DrawPlainMLTextSafe", &NativeContext::DrawPlainMLTextSafe)
		//.def("DrawRichText", &NativeContext::DrawRichText)
		//.def("GreekDrawRichText", &NativeContext::GreekDrawRichText)

		// --- Clip handling
		.def("SaveClip", &NativeContext::SaveClip)
		.def("RestoreClip", &NativeContext::RestoreClip)
		.def("BeginClip", &NativeContext::BeginClip)
		.def("EndClip", &NativeContext::EndClip)
		.def("SetClipToRect", &NativeContext::SetClipToRect)
		.def("SetClip", &NativeContext::SetClip)
		.def("IsClipEmpty", &NativeContext::IsClipEmpty)

		// --- Bitting


		// Clear, etc.
		.def("Clear", &NativeContext::Clear)
		.def("GetCurrentPos", &NativeContext::GetCurrentPos)
		.def("GetDirtyRect", &NativeContext::GetDirtyRect)
		.def("GetRoundLineCoordinates", &NativeContext::GetRoundLineCoordinates)
		.def("SetRoundLineCoordinates", &NativeContext::SetRoundLineCoordinates);
}