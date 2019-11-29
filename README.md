# hard-cp
CP is so hard

So as of 11/17/19 I have decided to start writing motivations to questions, in part so I actually remember them on USACO.

Additionally it would make it harder for me to copy the editorial mindlessly, which is honestly the only way for me to solve some questions since I suck.

**2019 February USACO Gold - Painting the Barn.** \
11/17/19 \
Estimated CF difficulty: 2500

Honestly a really difficult question. In contest I literally thought this to be a comp geo question, but then realized it couldn't be.

This is actually 2D DP.

Obviously this new rectangle must contain rectangles with K-1 layers. Otherwise the added areas would be useless.

However, we have to take into account areas with K layers since adding a layer of paint will ruin these areas.

In general, if the total area at (i,j) sums to K-1 (take prefix sums to avoid TLE) then set arr[i][j] = 1 and if the area sums to K then set arr[i][j] = -1. In all other cases leave arr[i][j] at 0.

To add a certain block we take prefix sums on arr vertically and proceed horizontally. We essentially use 1D Kadane here. By adjusting the subrectangle size, we can find the maximum for subrectangles across each line i. 

In the end we choose the two biggest subrectangles (in terms of largest value) across each line i (horizontal or vertical) to get the answer.

Originally did 2D Kadane's but the solution was flawed. The largest + largest mutually exclusive isn't necessarily the largest total combo. As I'm a moron this took around 8 hours to realize.

**USACO 2013 February USACO Gold - Route design** \
11/20/2019 \
Estimated CF Rating: 2000

Easier than paintbarn by a large margin. Also DP

We have a bipartite graph and a bunch of edges and we want to find the maximum value. Thus we can traverse up the graph and find the maximum values for each edge. As we go from one lower edge to one upper edge we simply see if we prefer keeping the current value or going from below and taking the edge up. We'd then find the best sum for all edges. 

At the end we simply loop through every vertex (on each side) and find the max.

**USACO 2018 December USACO Gold - Fine Dining** \
11/28/2019 \
Estimated CF Rating: 1700

Dijkstras but with one catch: We must account for the candy.

This is not bad. Simply take the original shortest paths.
Then, we input the haybales. For each haybale, let it lead to a point N+1 with weight (distance to n) - yumminess. Run Dijkstra again on a different distance array, and compare the distances at the end.

**USACO 2018 December USACO Gold - Teamwork** \
11/28/2019 \
Estimated CF Rating: 1600

DP

Let a[i] be the skill for cow i.
Base case: dp[0] = a[0]
Transition:
For each cow, loop through previous indices pre which is nonnegative and fits size constraints. If pre is 0 then we have only one team, and we just take the maximum skill value from the team. Otherwise we just add to the total from pre-1 downwards but keep a similar sum.