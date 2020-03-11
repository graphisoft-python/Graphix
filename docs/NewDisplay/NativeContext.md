# Class NativeContext

## Inherit

* [NativeContextBase](NativeContextBase.md)

## Enum

### ExternalType

* T_Default
* T_HDC
* T_HDCForThemedDrawing
* T_Graphics
* T_OpenGL

## Methods

```
Arc(self, Graphix.DisplayArc) -> None
ArcTo(self, Graphix.DisplayArc) -> None
BeginClip(self) -> None
BeginPolygon(self, Graphix.FillEffect = None) -> None
Clear(self) -> None
DrawImage(self, Graphix.NativeImage, float, float, float, float, float, bool, float = 1.0, Graphix.Filtering = Filtering.Bilinear, Graphix.BlitEffect = None) -> None
DrawPlainMLText(self, unicode,TextEngine.IFont, int, float, float, float, float, float) -> None
DrawPlainMLTextSafe(self, unicode, TextEngine.IFont, int, float, float, float, float, float, Graphix.TextQuality = TextQuality.TQ_SystemDefault) -> None
DrawPlainText(self, unicode, TextEngine.IFont, float, float, float) -> None
DrawUIText(self, unicode, TextEngine.IFont, int, float, float, float, float, bool) -> None
EndClip(self) -> None
EndPolygon(self) -> None
FillRect(self, float, float, float, float, int, int, int, int = 255) -> None
FillRect(self, float, float, float, float, GSRoot.Color) -> None
FrameRect(self, float, float, float, float) -> None
GetCurrentPos(self) -> GSRoot.Point
GetDirtyRect(self) -> GSRoot.Rect
GetRoundLineCoordinates(self) -> bool
IsClipEmpty(self) -> bool
LineTo(self, float, float) -> None
MoveTo(self, float, float) -> None
RestoreClip(self) -> None
SaveClip(self) -> None
SetBackColor(self, int, int, int, int = 255) -> None
SetBackColor(self, GSRoot.Color) -> None
SetBlendMode(self, Graphix.BlendMode) -> None
SetClip(self, Graphix.Clip) -> None
SetClipToRect(self, GSRoot.Rect) -> None
SetFillPattern(self, GSRoot.Pattern) -> None
SetForeColor(self, int, int, int, int = 255) -> None
SetForeColor(self, GSRoot.Color) -> None
SetLineCap(self, Graphix.LineCapType) -> None
SetLineDashPattern(self, List[float]) -> None
SetLinePatternOffset(self, float) -> None
SetLineWidth(self, float) -> None
SetRoundLineCoordinates(self, bool) -> None
```
