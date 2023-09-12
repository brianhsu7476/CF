void dijk(int n, vector<P> *G, int s, vi &res){ // (v, w)
	static bool vis[kN];
	rep(i, n)vis[i]=0;
	res.resize(n, oo);
	priority_queue<P> pq;
	pq.push(P(0, s)), res[s]=0;
	while(!pq.empty()){
		P p=pq.top(); pq.pop();
		if(vis[p.y])break;
		vis[p.y]=1;
		for(P u:G[p.y])if(res[p.y]+u.y<res[u.x])pq.push(P(res[u.x]=res[p.y]+u.y, u.x));
	}
}
