from decimal import *

n = int(input())
for i in range(n):
    a, b, c, k = map(Decimal, input().split())
    getcontext().prec = 400
    delta = Decimal(Decimal(b*b) - Decimal(4*a*c)).quantize(Decimal('10')**(-k))
    if delta < 0:
        print(0)
    elif delta == 0:
        x = Decimal(Decimal(-b)/Decimal(2*a)).quantize(Decimal('10')**(-k))
        print(f"1 {x}") 
    elif a == 0:
        if b == 0:
            print(0)
        else:
            x = Decimal(Decimal(-c)/Decimal(b)).quantize(Decimal('10')**(-k))
            print(f"1 {x}") 
    else:
        x1 = Decimal(Decimal(Decimal(-b) - Decimal(delta.sqrt())))/Decimal(2*a).quantize(Decimal('10')**(-k))
        x2 = Decimal(Decimal(Decimal(-b) + Decimal(delta.sqrt())))/Decimal(2*a).quantize(Decimal('10')**(-k))
        if x1 > x2:
            print(f"2 {x2} {x1}")
        else:
            print(f"2 {x1} {x2}")
