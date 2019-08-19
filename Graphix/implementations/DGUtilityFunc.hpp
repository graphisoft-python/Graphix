#pragma once

#include "../stdafx.h"

#include "DGUtility.hpp"
#include "Font.hpp"
#include "TextEngine.hpp"

using namespace DG;

void load_DG_Utils(py::module m) {
	py::class_<Utils> m_utils(m, "Utils");

	py::enum_<Utils::SystemColorType>(m_utils, "SystemColorType")
		.value("ShadowColorType", Utils::SystemColorType::ShadowColorType)
		.value("FaceColorType", Utils::SystemColorType::FaceColorType)
		.value("HighlightColorType", Utils::SystemColorType::HighlightColorType)
		.value("HighlightTextColorType", Utils::SystemColorType::HighlightTextColorType)
		.value("ForegroundTextColorType", Utils::SystemColorType::ForegroundTextColorType)
		.value("DisabledTextColorType", Utils::SystemColorType::DisabledTextColorType)
		.value("LightHighlightColorType", Utils::SystemColorType::LightHighlightColorType)
		.value("DarkHighlightColorType", Utils::SystemColorType::DarkHighlightColorType)
		.value("TrackerTextColorType", Utils::SystemColorType::TrackerTextColorType)
		.value("TrackerBackgroundColorType", Utils::SystemColorType::TrackerBackgroundColorType)
		.value("TrackerFrameColorType", Utils::SystemColorType::TrackerFrameColorType)
		.export_values()
		;

	py::enum_<Utils::Alignment>(m_utils, "Alignment")
		.value("RightTopOrLeftTop", Utils::Alignment::RightTopOrLeftTop)
		.value("RightBottomOrLeftBottom", Utils::Alignment::RightBottomOrLeftBottom)
		.value("LeftTopOrRightTop", Utils::Alignment::LeftTopOrRightTop)
		.value("RightCenter", Utils::Alignment::RightCenter)
		.value("BottomLeftRightOrTopLeftRight", Utils::Alignment::BottomLeftRightOrTopLeftRight)
		.value("BottomRight", Utils::Alignment::BottomRight)
		.value("OnlyKeepRectInScreen", Utils::Alignment::OnlyKeepRectInScreen)
		.export_values()
		;

	m_utils
		.def_static("FillRect", py::overload_cast<NewDisplay::NativeContext&, const DG::Rect &, const Gfx::Color &, bool, bool, bool>(&Utils::FillRect),
			py::arg("context"),
			py::arg("rect"),
			py::arg("color"),
			py::arg("drawFrame") = false,
			py::arg("roundEdge") = false,
			py::arg("modifyColorForDisabledControl") = false)
		.def_static("GetSystemColor",&Utils::GetSystemColor)
		.def_static("CanTextFitInArea",&Utils::CanTextFitInArea)
		.def_static("DrawText",&Utils::DrawText,
			py::arg("context"),
			py::arg("rect"),
			py::arg("text"),
			py::arg("inFontType"),
			py::arg("alignment"),
			py::arg("endEllipsis")=false,
			py::arg("color")=nullptr
		)
		.def_static("GetTextDimensions",&Utils::GetTextDimensions)
		.def_static("MeasurePlainText", [](GS::UniString &str, TE::Font &font) {
			double textWidth = 0.0;
			TE::textEngine.MeasurePlainText(str, font, &textWidth);
			return textWidth;
		})
		;

}