struct Pcmp{
	bool operator()(const P a, const P b)const{
		return a.y>b.y||a.y==b.y&&a.x>b.x;
	}
};

void dijk(int n, vector<P> *G, int s, vi &res){ // (v, w)
	static bool vis[kN];
	rep(i, n)vis[i]=0;
	res.resize(n, oo);
	priority_queue<P, vector<P>, Pcmp> pq;
	pq.push(P(s, 0)), res[s]=0;
	while(!pq.empty()){
		P p=pq.top(); pq.pop();
		if(vis[p.x])break;
		vis[p.x]=1;
		for(P u:G[p.x])if(res[p.x]+u.y<res[u.x])pq.push(P(res[u.x]=res[p.x]+u.y, u.x));
	}
}
