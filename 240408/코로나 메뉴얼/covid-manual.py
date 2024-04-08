A=input().split()
A_g=A[0]
A_t=int(A[1])

B=input().split()
B_g=B[0]
B_t=int(B[1])

C=input().split()
C_g=A[0]
C_t=int(C[1])

if A_g=="Y" and A_t>=37:
    if B_g=="Y" and B_t>=37 or C_g=="Y" and C_t>=37:
        print("E")
    else :
        print("N")
elif B_g=="Y" and B_t>=37:
    if C_g=="Y" and C_t>=37:
        print("E")
    else :
        print("N")
else:
    print("N")