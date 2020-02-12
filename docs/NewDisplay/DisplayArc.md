# Class DisplayArc

## Enum

### Reflection

* NotReflected
* Reflected

## Methods

```
IsFullEllipse(self) -> bool
GetCenter(self) -> GSRoot.FloatPoint
GetBegCoordinate(self) -> GSRoot.FloatPoint
GetEndCoordinate(self) -> GSRoot.FloatPoint
GetBegAngle(self) -> float
GetEndAngle(self) -> float
GetDeltaAngle(self) -> float
GetXRadius(self) -> float
GetYRadius(self) -> float
GetFullEllipseBoundingRect(self) -> GSRoot.FloatRect
GetSegmentation(self, int) -> List[GSRoot.FloatPoint]
Scale(self,float) -> Graphix.DisplayArc
CreateFullCircle(GSRoot.FloatPoint,float) -> Graphix.DisplayArc
CreateCircularArc(GSRoot.FloatPoint,float,float,float) -> Graphix.DisplayArc
CreateFullEllipse(GSRoot.FloatPoint,float,float) -> Graphix.DisplayArc
CreateFullEllipse(float,float,float,float) -> Graphix.DisplayArc
CreateEllipticArcWithEndPoints(GSRoot.FloatPoint,float,float,GSRoot.FloatPoint,GSRoot.FloatPoint,Graphix.DisplayArc.Reflection) -> Graphix.DisplayArc
CreateEllipticArc(GSRoot.FloatPoint, float, float, float, float) -> Graphix.DisplayArc
CreateEllipticArc(float,float,float,float,float,float) -> Graphix.DisplayArc
```
