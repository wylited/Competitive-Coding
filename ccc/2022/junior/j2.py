(p,ps,tg)=(int(input()),0,0)
for(i)in range(p):
    (ps,tg)=((ps+(int(input())*5)-(int(input())*3)),((tg+1)if(ps>40)else(tg + 0)))
print((str(tg+1))if((tg+1)!=p)else(str(tg+1)+"+")) 