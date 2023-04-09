import math

p1 = (23, -88)
p2 = (6, 42)

horizontal_distance = p2[0] - p1[0]
vertical_distance = p2[1] - p1[1]

distance = math.sqrt(horizontal_distance + vertical_distance)

print(distance)