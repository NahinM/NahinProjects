def primeFactor(n):
    i=2
    pf = []
    while i<=n:
        total = 0
        while n%i==0:
            n/=i
            total+=1
        if total!=0: pf.append((i,total))
        i+=1
    return pf

pf = primeFactor(int(input("Enter number: ")))
for p in pf: print(f"{p[0]}^({p[1]}) {"+" if(p!=pf[-1]) else ""}" , end="")
print()