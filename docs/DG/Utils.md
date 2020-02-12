# Class Utils

## Inherit

* Object

## Enum

### SystemColorType

* ShadowColorType
* FaceColorType
* HighlightColorType
* HighlightTextColorType
* ForegroundTextColorType
* DisabledTextColorType
* LightHighlightColorType
* DarkHighlightColorType
* TrackerTextColorType
* TrackerBackgroundColorType
* TrackerFrameColorType

### Alignment

* RightTopOrLeftTop
* RightBottomOrLeftBottom
* LeftTopOrRightTop
* RightCenter
* BottomLeftRightOrTopLeftRight
* BottomRight
* OnlyKeepRectInScreen

## Methods

```
FillRect(Graphix.NativeContext, DGLib.Rect, GSRoot.Color, bool=false, bool=false, bool=false) -> None
GetSystemColor(Graphix.Utils.SystemColorType) -> GSRoot.Color
CanTextFitInArea(unicode,DGLib.Rect,bool,int,float) -> bool
DrawText(Graphix.NativeContext, DGLib.Rect, unicode, int, int, bool=false, GSRoot.Color=nullptr) -> None
GetTextDimensions(unicode, int, int, int, float, bool) -> DGLib.Rect
MeasurePlainText(unicode, TextEngine.Font) -> float
```
