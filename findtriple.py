
def find_triple(a,b,c):
    if a < b < c:
        if a+b+c==1000:
            if a*a + b*b == c*c:
                print(a)
                print(b)
                print(c)



for a in range(1,1000):
    for b in range(1,1000):
        for c in range(1,1000):
            find_triple(a,b,c)