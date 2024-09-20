list_date=list(map(int,input().strip().split(" ")))
n=input()
month=[31,29,31,30,31,30,31,31,30,31,30,31]
date1=0
date2=0
# 그 사이 날짜 계산해서+1 //7  하면 됨
if list_date[0]==1:
    date1=list_date[1]

    if list_date[2]==1:
        date2=list_date[3]
    
    else:
        for i in range(0,list_date[2]-1):
            date2+=month[i]
        date2+=list_date[3]


else:
    for i in range(0,list_date[0]-1):
        date1+=month[i]
    date1+=list_date[1]


    for i in range(0,list_date[2]-1):
        date2+=month[i]
    date2+=list_date[3]

date=date2-date1+1
date//=7

if n=="Mon":
    date+=1
print(date)