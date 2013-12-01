float getPR(int hp, int d, int s) {
	int P1 = 0;
	int P2 = 0;
	float pR = -1;

	if (hp < 1 || hp > 999) return pR;
	if (d < 1 || d > 1000) return pR;
	if (s < 1 || s > 100) return pR;
	
	int x = isPrime(hp);
	if (x==1) {
		P1=1000;
		P2=(hp+s)%1000;
	}
	else {
		P1=hp; 
		P2=(hp+d)%100;
	}
		
	int c = 0; 
	float g = 0;
	int t=(d+s);
	int s6 = s%6;
	
	if(s6 == 0) g= s/2.0;
	else if(s6 == 1) g=2.0*s;
	else if(s6 == 2) g=(s%9)*(s%9)*(s%9)*(-1.0)/5;
	else if(s6 == 3) g=( (s%30)*(s%30)*(-1.0)+3*s);
	else if (s6 == 4) g=s*(-1.0);
	else {
		c=((s%5)+5);
		g=c*(c+1)*(-1.0)/2;
	}
	
	float f = 0;
	if (d<200)
	{
		if (t==2||t==3|| t==5|| t==8|| t==13||t==21|| t==34|| t==55|| t==89|| t==144 || t==233)
		{
			f=40.0- abs(d-500.0)/20+g;
			pR=(P1+P2*f)/(1000.0 + abs(P2*f));
		}
		else {
			f=0.0;
			pR=(P1+P2*f)/(1000.0 + abs(P2*f));
		}
	}
	else if (d>=200 && d<=800)
	{
		f=40.0 - abs(d-500)/20.0+g;
		if (d<300 && d > 200)
		{
			float z = (d + P1+ P2)/1000.0;
			if (z>0.8)
				pR=0;
			else 
				pR=(P1+P2*f)/(1000.0+abs(P2*f));
		}
		else pR=(P1+P2*f)/(1000+abs(P2*f)); // CAU LENH LOI
	} else {
		f= -(d*s)/1000.0;
		pR=(P1+P2*f)/(1000.0+abs(P2*f));
	}
	
	if (pR<0) pR=0;
	else if (pR>1)	pR=1;
	
	return pR;
}
