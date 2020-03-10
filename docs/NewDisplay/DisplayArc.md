# Class DisplayArc

## Enum

### Reflection

* NotReflected
* Reflected

## Methods

```
IsFullEllipse(self) -> bool
GetCenter(self) -> GSRoot.Point
GetBegCoordinate(self) -> GSRoot.Point
GetEndCoordinate(self) -> GSRoot.Point
GetBegAngle(self) -> float
GetEndAngle(self) -> float
GetDeltaAngle(self) -> float
GetXRadius(self) -> float
GetYRadius(self) -> float
GetFullEllipseBoundingRect(self) -> GSRoot.Rect
GetSegmentation(self, int) -> List[GSRoot.Point]
Scale(self, float) -> Graphix.DisplayArc
CreateFullCircle(GSRoot.Point, float) -> Graphix.DisplayArc
CreateCircularArc(GSRoot.Point, float, float, float) -> Graphix.DisplayArc
CreateFullEllipse(GSRoot.Point, float, float) -> Graphix.DisplayArc
CreateFullEllipse(float, float, float, float) -> Graphix.DisplayArc
CreateEllipticArcWithEndPoints(GSRoot.Point, float, float,GSRoot.Point ,GSRoot.Point, Graphix.DisplayArc.Reflection) -> Graphix.DisplayArc
CreateEllipticArc(GSRoot.Point, float, float, float, float) -> Graphix.DisplayArc
CreateEllipticArc(float, float, float, float, float, float) -> Graphix.DisplayArc
```
