# hard-cp
CP is so hard

So as of 11/17/19 I have decided to start writing motivations to questions, in part so I actually remember them on USACO.

Additionally it would make it harder for me to copy the editorial mindlessly, which is honestly the only way for me to solve some questions since I suck.

**USACO 2013 February USACO Gold - Route design** \
11/20/2019 \
Estimated CF Rating: 2000

DP

Easier than paintbarn by a large margin. Also DP

We have a bipartite graph and a bunch of edges and we want to find the maximum value. Thus we can traverse up the graph and find the maximum values for each edge. As we go from one lower edge to one upper edge we simply see if we prefer keeping the current value or going from below and taking the edge up. We'd then find the best sum for all edges. 

At the end we simply loop through every vertex (on each side) and find the max.

**USACO 2014 December USACO Gold - Marathon** \
12/1/2019 \
Estimated CF Rating: 2000

Segment Tree (:rage: :deciduous_tree:)

Let dist(a,b) be the manhattan distance between two checkpoints a,b.

Realize that skipping from a to a+2 is equal to dist(a, a+1) + dist(a+1, a+2) - dist(a, a+2) off of the total distance. With this we can store a segtree with the original lengths (dist(a, a+1) foreach a), and one with the skip length. Then just perform normal queries.

But be sure to update *each* node. I forgot to do this so it took v long for me to realize :sob:

> Bessie realizes that the other cows may not have the stamina to run the full route.

just like how i don't have the stamina to do cp

**USACO 2018 December USACO Gold - Fine Dining** \
11/28/2019 \
Estimated CF Rating: 1700

Graph Theory

Dijkstras but with one catch: We must account for the candy.

This is not bad. Simply take the original shortest paths.
Then, we input the haybales. For each haybale, let it lead to a point N+1 with weight (distance to n) - yumminess. Run Dijkstra again on a different distance array, and compare the distances at the end.

**USACO 2018 December USACO Gold - Cowpatibility**\
11/28/2019 \
Estimated CF Rating: 2300

Math, Combinatorics

We complementary count to find the number that are compatible and subtract from n*(n-1)/2.

As we have at most 31n subsets by including solely numbers mentioned we should be in time.

Use an unordered_map to find all the subsets and the frequencies of each. Then simply run PIE at the end to find the number of pairs.

Implementation details:
unordered_map is better because it processes adds in O(1), while map may take O(lg n). Additionally, ensure to sort the flavors in ascending order or else you will WA. You will count different subsets multiple times due to ordering.

(btw you is in reference to me, because i want to tell my future self about this new geniosity that i have temporarily acquired)

**USACO 2018 December USACO Gold - Teamwork** \
11/28/2019 \
Estimated CF Rating: 1600

DP

Let a[i] be the skill for cow i.
Base case: dp[0] = a[0]
Transition:
For each cow, loop through previous indices pre which is nonnegative and fits size constraints. If pre is 0 then we have only one team, and we just take the maximum skill value from the team. Otherwise we just add to the total from pre-1 downwards but keep a similar sum.

**2019 February USACO Gold - Cow Land** \
Solved earlier \
Estimated CF difficulty: 1900

Graph Theory, Data Structures

Vanilla HLD but with XOR because problem statement blatantly says to do seg tree on a tree. This is the function of HLD so just spend 3 hours re-implementing HLD and crying. Or alternatively I could SAVE the HLD IMPLEMENTATION and REUSE it if it comes up!

Very big thanks to xiaowuc1 for helping me temporarily acquire geniosity after an arml practice and explaining HLD :)

**2019 February USACO Gold - Painting the Barn.** \
11/17/19 \
Estimated CF difficulty: 2500

DP

Honestly a really difficult question. In contest I literally thought this to be a comp geo question, but then realized it couldn't be.

This is actually 2D DP.

Obviously this new rectangle must contain rectangles with K-1 layers. Otherwise the added areas would be useless.

However, we have to take into account areas with K layers since adding a layer of paint will ruin these areas.

In general, if the total area at (i,j) sums to K-1 (take prefix sums to avoid TLE) then set arr[i][j] = 1 and if the area sums to K then set arr[i][j] = -1. In all other cases leave arr[i][j] at 0.

To add a certain block we take prefix sums on arr vertically and proceed horizontally. We essentially use 1D Kadane here. By adjusting the subrectangle size, we can find the maximum for subrectangles across each line i. 

In the end we choose the two biggest subrectangles (in terms of largest value) across each line i (horizontal or vertical) to get the answer.

Originally did 2D Kadane's but the solution was flawed. The largest + largest mutually exclusive isn't necessarily the largest total combo. As I'm a moron this took around 8 hours to realize.