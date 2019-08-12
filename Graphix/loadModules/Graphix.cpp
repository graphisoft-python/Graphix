// Graphix.cpp : 定义 DLL 应用程序的导出函数。
//

#include "..\stdafx.h"

#include "../implementations/NativeImageFunc.hpp"
#include "../implementations/NativeContextBaseFunc.hpp"
#include "../implementations/IBlitFunc.hpp"
#include "../implementations/DisplayArcFunc.hpp"
#include "../implementations/FillEffectsFunc.hpp"
#include "../implementations/ClipFunc.hpp"
#include "../implementations/BlitEffectsFunc.hpp"
#include "../implementations/NativeContextFunc.hpp"
#include "../implementations/NativeContextsFunc.hpp"


PYBIND11_MODULE(Graphix, m) {

	m.def("version", []() {	return "version 0.0.1"; });

// --- Add bindings here ------------------------------------------------------------------

	// --- NativeImage
	auto native_image= init_NativeImage(m);

	// --- NativeContextBase
	load_Filtering(m);
	load_NativeContextBase(m);

	// --- IBlit
	load_BlendMode(m);

	// --- DisplayArc
	load_DisplayArc(m);

	// --- FillEffects
	load_FillEffect(m);
	load_FillEffectEX(m);

	// --- ClipFunc
	load_Clip(m);

	// --- BlitEffects
	load_BlitEffect(m);
	load_FalseColorBlitEffect(m);

	// --- NativeContext
	load_NativeContextEnum(m);
	load_NativeContext(m);


	// --- NativeImage
	load_NativeImage(native_image);

	// --- NativeContexts
	//load_HDCContext(m);
	//load_GdiplusGraphicsContext(m);

// --- Add bindings end -------------------------------------------------------------------
}