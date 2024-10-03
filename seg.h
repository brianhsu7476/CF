struct seg{ // if use mn not mx, remember to change some -oo to oo
	int l, r, m, mx, sm, lz=0, lzt=oo;
	seg *left=NULL, *right=NULL;
	seg(){}
	seg(int l, int r, int *a):l(l), r(r), m(l+r>>1){
		if(r-l<2)mx=sm=a[l], left=right=NULL;
		else left=new seg(l, m, a), right=new seg(m, r, a), pull();
	}
	void addlz(int lz1, int lzt1){
		if(lzt1<oo)mx=lzt=lzt1, sm=mx*(r-l), lz=0;
		else if(lzt<oo)mx=lzt+=lz1, sm=mx*(r-l), lz=0;
		else mx+=lz1, lz+=lz1, sm+=lz1*(r-l);
	}
	void push(){
		if(lz!=0||lzt!=oo)left->addlz(lz, lzt), right->addlz(lz, lzt), lz=0, lzt=oo;
	}
	void pull(){
		mx=max(left->mx, right->mx), sm=left->sm+right->sm;
	}
	void upd(int ll, int rr, int ad, int to){ // if no to, then to=oo
		if(ll<=l&&r<=rr)addlz(ad, to);
		push();
		if(ll<=m)left->upd(ll, rr, ad, to);
		if(m<=rr)right->upd(ll, rr, ad, to);
		pull();
	}
	P qry(int ll, int rr){
		if(ll<=l&&r<=rr)return P(mx, sm);
		auto f=[](P a, P b){return P(max(a.x, b.x), a.y+b.y);};
		P res=P(-oo, 0);
		push();
		if(ll<=m)res=f(res, left->qry(ll, rr));
		if(m<=rr)res=f(res, right->qry(ll, rr));
		return res;
	}
};
