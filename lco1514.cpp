#define pa pair<double,int>
#define mk make_pair
#define maxn 10010
struct node{
    int v<Plug>PeepOpenre;
    double t;

}e[maxn*4];
priority_queue<pa,vector<pa>>Q;
int num,head[maxn];
double dis[maxn];
void addEdge(int from,int to,double val){
    num++;
    e[num].v=to;
    e[num].t=val;
    e[num].pre=head[from];
    head[from]=num;

}

class Solution {
    public:

        void Dij(int start,int n){
            for(int i=0;i<n;i++)dis[i]=-1e9;
            dis[start]=0;
            Q.push(mk(0,start));
            while(!Q.empty()){
                pa now=Q.top();
                Q.pop();
                if(dis[now.second]>now.first)continue;
                for(int i=head[now.second];i;i=e[i].pre){
                    int v=e[i].v;
                    if(dis[v]<dis[now.second]+e[i].t){
                        dis[v]=dis[now.second]+e[i].t;
                        Q.push(mk(dis[v],v));

                    }

                }

            }

        }

        double maxProbability(int n, vector<vector<int>>& G, vector<double>& P, int start, int end) {
            num=0;
            for(int i=0;i<n;i++)head[i]=0;
            int m=G.size();
            for(int i=0;i<m;i++){
                addEdge(G[i][0],G[i][1],log10(P[i]));
                addEdge(G[i][1],G[i][0],log10(P[i]));

            }
            Dij(start,n);

            if(dis[end]<=-1e9)return 0;
            return pow(10,dis[end]);



        }

};

