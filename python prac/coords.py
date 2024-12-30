class Point:
    def __init__(self, x, y):
        self.x = x
        self.y = y
    
    def __str__(self):
        return f"Point({self.x}, {self.y})"
    
    def distance(self, other):
        return ((self.x - other.x) ** 2 + (self.y - other.y) ** 2) ** 0.5

x1, y1 = map(int, input("Enter coordinates for Point 1 (x y): ").split())
x2, y2 = map(int, input("Enter coordinates for Point 2 (x y): ").split())

p1 = Point(x1, y1)
p2 = Point(x2, y2)

print(p1)
print(p2)
print("Distance between points:", p1.distance(p2))
