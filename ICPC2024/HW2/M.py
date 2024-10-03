from math import *

def exgcd(a, b):
	if b==0:
		return 1, 0
	p=a//b
	q, r=exgcd(b, a%b)
	return r, q-r*p

def crt(x1, m1, x2, m2):
	g=gcd(m1, m2)
	if (x2-x1)%g:
		return -1
	m1//=g
	m2//=g
	p, q=exgcd(m1, m2)
	l=m1*m2*g
	res=p*(x2-x1)*m1+x1
	return (res%l+l)%l

def ask(x):
	print('? '+str(x))
	return int(input())

u, v=input().split(' ')
u, v=int(u), int(v)
nu, nv=ask(u), ask(v)

p0, p1, p2=611953, 746773, 882389
vis0, vis1, vis2=[0]*p0, [0]*p1, [0]*p2
c0, c1, c2=0, 0, 0
x0, x1, x2=0, 0, 0
while True:
	if vis0[x0]:
		break
	vis0[x0]=1
	c0+=1
	x0=(11*x0+7)%p0
while True:
	if vis1[x1]:
		break
	vis1[x1]=1
	c1+=1
	x1=(13*x1+5)%p1
while True:
	if vis2[x2]:
		break
	vis2[x2]=1
	c2+=1
	x2=(53*x2+3)%p2
tmp=[int((u-v)%i==0) for i in [c0, c1, c2]]
pu, qu, pv, qv=0, 0, 0, 0
if sum(tmp)<2:
	if sum(tmp)==1:
		if tmp[0]:
			c0, c2=c2, c0
		if tmp[1]:
			c1, c2=c2, c1
	w0=crt(u, c0, v, c1)
	if w0%c2==0:
		w0+=c0*c1
	n0=ask(w0)
	pu, qv=gcd(nu, n0), gcd(nv, n0)
	w1=crt(v, c0, u, c1)
	if w1%c2==0:
		w1+=c0*c1
	n1=ask(w1)
	pv, qu=gcd(nv, n1), gcd(nu, n1)
else:
	if sum(tmp)==2:
		if tmp[0]==0:
			c0, c2=c2, c0
		if tmp[1]==0:
			c1, c2=c2, c1
	n0=ask(u+c0)
	n1=ask(u+c1)
	pu=pv=gcd(nu, n0)
	qu=qv=gcd(nu, n1)
ru=nu//pu//qu
rv=nv//pv//qv
print('! '+str(pu+qu+ru+pv+qv+rv))
