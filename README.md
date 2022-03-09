# DailyExercise


## 202112-5

Find the number of paths which satisfy the follow condition:

 **min(x,y)-k1<=min(path)<=max(path)<=max(x,y)+k2**

### violent solution:
O(n\*n) enumerate every paths, then O(logn) get max and min values by LCA.      **12 points**

### heap solution(eg big heap)
dp[u] means the number of legal path in subtree u. Obviously, dp[u]=(sigma dp[son]) + W, W means path that cross point u. Path W can be divided into 2 parts, half in son i, half in son j(son j actually represent all remaining son). Due to the features of big heap, the max value in W is u, the min value in W is one of the end points in son i or j.
Let's define the number of points less than w-k2 in son i is A, which in son j is B, the last part in son i is C, which in son j is D.
Then A\*D, C\*B, C\*D is ok, A\*B is not ok. So W=sigma (A[k]\*D[k]+C[k]\*B[k]+C[k]\*D[k]).

### k2==0 solution
Assuming that y=max(x,y), then y=max{S}, let's enumerate y to get all legal path. All path from y can be divided to 2 group, one y -> son[y] -> ,  one y -> fa[y] -> , define the first is dp\[y][0], the second is dp\[y][1].
We can get dp\[u][0] first by dp\[u][0]=sigma dp\[son][0] where satisfy son is less than u; then dp\[u][1]=dp\[fa][1]+dp\[fa][0]-dp\[u][0];
k2==0 solution has some bug.   **24 points**

//TODO

## DOJ 460
easy dp

## DOJ 451
xor[root->u]^xor[root->v]+val[lca] or just lca
**remember the last for in lca must 20->1**

## DOJ 464
zhuxi tree

## DOJ 454
according to the features of OR, we can process from high bit to low avidly. Specificly, for bit k, if we can still span a tree by delete all related edges, then directly delete them, and this bit don't contribute to the answer. 
!! 32 * BFS will get TLE whether using vector or hash table to store the graph. Finally I use Union-find set to optimize it.

## cf775
A:simple sort
B:violent for, it can be provable that can break soon
rating dorp like a fk eagle

## DOJ 289
simple dp

## Lco 1514
A*B*C --> e^(log(A)+log(B)+log(C))
then dij+head or sth.

## doj 496
simple set
