import math
from typing import Self

class Vector:
    def __init__(self, *args):
        self.__arr = tuple(args)
    
    def __len__(self):
        return len(self.__arr)
    
    def __getitem__(self, idx):
        if isinstance(idx, slice):
            return Vector(self.__arr[idx])
        else:
            return self.__arr[idx]
    
    def __setitem__(self, idx, value):
        self.__arr[idx] = value
    
    def __add__(self, p2: Self) -> Self:
        assert len(self) == len(p2)
        return Vector(*(self[i] + p2[i] for i in range(len(self))))
    
    def __sub__(self, p2: Self) -> Self:
        assert len(self) == len(p2)
        return Vector(*(self[i] - p2[i] for i in range(len(self))))
    
    def __mul__(self, val: float) -> Self:
        return Vector(*(self[i] * val for i in range(len(self))))
    
    def __truediv__(self, val: float) -> Self:
        return Vector(*(self[i] / val for i in range(len(self))))
    
    def __matmul__(self, p2: Self) -> float:
        assert len(self) == len(p2)
        return sum((self[i] * p2[i] for i in range(len(self))))
    
    def __str__(self) -> str:
        return '[' + ', '.join(map(str, self.__arr)) + ']'
    
    def rotate(self, rad: float) -> Self:
        assert len(self) == 2
        return Vector(math.cos(rad) * self[0] - math.sin(rad) * self[1], math.sin(rad) * self[0] + math.cos(rad) * self[1])
    
    def abs(self) -> float:
        return math.sqrt(self @ self)
    
class Line:
    def __init__(self, p1: Vector, p2: Vector):
        assert len(p1) == len(p2)
        self.p1 = p1
        self.p2 = p2
    
    def closest_point_to(self, p: Vector):
        s = self.p2 - self.p1
        l = s.abs()
        s /= l
        dst = s @ (p - self.p1)
        dst = max(0, dst)
        dst = min(l, dst)
        return self.p1 + (s * dst)
    
    def dist_to_point(self, p: Vector):
        pt = self.closest_point_to(p)
        return (p - pt).abs()
        
class Square:
    def __init__(self, p1: Vector, p3: Vector):
        assert len(p1) == 2
        assert len(p3) == 2
        center = (p1 + p3) / 2
        hand = (p3 - p1).rotate(math.pi / 2) / 2
        p2 = center + hand
        p4 = center - hand

        self.__points = [p1, p2, p3, p4]

    def closest_point_to(self, p: Vector):
        pts = self.__points[0]
        dist = (p - pts).abs()
        for i in range(4):
            l = Line(self.__points[i], self.__points[(i+1)%4])
            pts2 = l.closest_point_to(p)
            dist2 = (p - pts2).abs()
            if dist2 < dist:
                pts = pts2
                dist = dist2
        return pts

        
    
(d, x1, y1, x2, y2) = tuple(map(float, input().split(' ')))

squ = Square(Vector(x1, y1), Vector(x2, y2))
dist = squ.closest_point_to(Vector(0, 0))

print(dist)