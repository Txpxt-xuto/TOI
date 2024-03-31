N=int(input())
j=1;
i=2;
while j<N :
    k=1;
    while k<i :
        if i%k==0 :
            j=j+1
        k=k+1
    i=i+1
print(i)