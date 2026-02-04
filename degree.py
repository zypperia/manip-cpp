from math import sqrt, acos, atan, degrees

l1 = float(input("Длина плеча 1:\t\t"))
l2 = float(input("Длина плеча 2:\t\t"))
ll = sqrt(l1*l1+l2*l2)

x = float(input("Конечная точка X:\t"))
y = float(input("Конечная точка Y:\t"))
z = float(input("Конечная точка Z:\t"))

# Work in 2D
xy = sqrt(x*x + y*y)


# a^2=b^2+c^2-2*b*c*cos(A)
# cos(A) = b^2+c^2-a^2 / 2*b*c
d = (l1*l1 + l2*l2 - ll*ll) / (2 * l1 * l2)
d = degrees(acos(d))

print(f"Угол меж плеч:\t\t{d}")

d = (l1*l1 + ll*ll - l2*l2) / (2 * l1 * ll)
d = degrees(acos(d))
d += degrees(atan(z / xy))
print(f"Угол плеча у башни:\t{d}")

d = degrees(atan(x / y))
print(f"Угол поворота башни:\t{d}")
