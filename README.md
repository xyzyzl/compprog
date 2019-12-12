# hard-cp
CP is so hard

So as of 11/17/19 I have decided to start writing motivations to questions, in part so I actually remember them on USACO.

Additionally it would make it harder for me to copy the editorial mindlessly, which is honestly the only way for me to solve some questions since I suck.

**POI 2014 - Salad Bar** \
12.11.2019 \
Estimated CF Rating: 2200

Ranch dressing, Implementation, borderline dp (?)

Let an apple have value -1 and an orange have value 1. We see that by taking the prefix sums (which we put in psum[x]) we can determine whether there are more apples or oranges in a given interval. If psum[i] > psum[j<i], then index i has more oranges than in psum[j]. Thus, if we pick the interval from j to i, we will have more oranges than apples at index j.

However, psum[i-1] <= psum[x] <= psum[j] must be true for all indices x in the interval [i,j]. Thus we need to check and see if the current index is below the final value. If psum[i] > psum[i+1] clearly the rightmost for i must be i itself. However, otherwise we can recurse. The rightmost, first, is clearly the rightmost for the next index. Additionally, we can store the last instance of this prefix sum value. If the prefix sum for the rightmost of that is greater than or equal to that of the current rightmost, we can just set our rightmost to the rightmost of the last instance.

Remember to reset the last instance and take a running max.

Mistakes I made: Binary searching for the right/leftmost does not work because just because a prefix sum is greater doesn't mean everything in between is greater.

**POI 2014 - Hotels** \
12/8/2019 \
Estimated CF Rating: 1900

Tree Algos

Run DFS to find the total number of children that have the same depth from a central node. Maintain all sets of these children and find the number at the end.

(This DFS should have multiple starting points)

**USACO 2013 February Gold - Route design** \
11/20/2019 \
Estimated CF Rating: 2000

DP

Easier than paintbarn by a large margin. Also DP

We have a bipartite graph and a bunch of edges and we want to find the maximum value. Thus we can traverse up the graph and find the maximum values for each edge. As we go from one lower edge to one upper edge we simply see if we prefer keeping the current value or going from below and taking the edge up. We'd then find the best sum for all edges. 

At the end we simply loop through every vertex (on each side) and find the max.

**USACO 2014 March Gold - Sabotage** \
12/2/2019 \
Estimated CF Rating: 2400

We are minimizing the average. Thus, it suffices to binary search over the average until we find a working one.

At each mid, we check if mid can be put into a contiguous subarray. As we are taking away an average of mid from each index, we can simply loop through while subtracting mid. If the overall is feasible then mid works, else it does not.

**USACO 2014 December Gold - Guard Mark** \
12/1/2019 \
Estimated CF Rating: 2100

Greedy (:flag_us:)

Take all the subset sums of the weights.

We see that we simply add each cow from another already visited subset to get the current subset, so we can set up a recursion. I'm too lazy to describe so just look at my code.

Mistakes included refusing to calculate values that didn't stack up to Mark's height, so the whole thing turned into 0. :cry:

**USACO 2014 December Gold - Marathon** \
12/1/2019 \
Estimated CF Rating: 2000

Segment Tree (:rage: :deciduous_tree:)

Let dist(a,b) be the manhattan distance between two checkpoints a,b.

Realize that skipping from a to a+2 is equal to dist(a, a+1) + dist(a+1, a+2) - dist(a, a+2) off of the total distance. With this we can store a segtree with the original lengths (dist(a, a+1) foreach a), and one with the skip length. Then just perform normal queries.

But be sure to update *each* node. I forgot to do this so it took v long for me to realize :sob:

> Bessie realizes that the other cows may not have the stamina to run the full route.

just like how i don't have the stamina to do cp

**USACO 2015 January Gold - Moovie Mooving** \
12.8.2019 \
Estimated CF Difficulty: 2100

Bitmasks, DP

Note: Folder name is free_punjabi_movie_... 

Let dp[S] be the amount of time taken for the subset S of movies. If this is at least L we are done.

We see that because N < 20, we can run an exponential-time solution. Thus, we use bitmasks. We can add a movie i to our existing subset. If we do, we have to find the latest time that is before dp[existing subset]. This can be done with binary search. Given the best time, we simply add the duration of the movie to our total.

Just take the minimum length of __builtin_popcount(mask).

**USACO 2016 February Gold - Circular Barn Revisited** \
12.9.2019 \
Estimated CF Difficulty: 1700

Simple DP. We can assume the start position is O, and wrap around as needed. (Or we could rotate the entire array at each step)

Then at each index i, we loop through all indices j and open the jth door. Then we find the number of cows from i to j. We then find the best j and store that into our current state. We refresh the dp array n times, and each time we take the minimum that gets us to the end with k doors unlocked.

Total time is O(n * n^2 k) = O(n^3 k).

**USACO 2016 February Gold - Fenced in** \
12.9.2019 \
Estimated CF Difficulty: 2000

Just run an MST algorithm, but don't store the edges. Instead find the edges when you are at some pair of point. Doing Kruskal like this should not be very different from the original variant

Storing the edges = MLE. I did that and got 7/10.

**USACO 2017 January Gold - Cow Navigation** \
12.10.2019 \
Estimated CF Difficulty: 1800

BFS

Just BFS regularly, but the states and transitions are slightly modified to fit the problem. For each state, we keep track of Bessie's location if she were facing forwards or to the right, plus the direction of each. Then we just do our BFS. We start with our original state, and either rotate left, rotate right, or go forward. When we reach (N,N) for both movesets we just output the value since it's guaranteed to be the minimum if it reaches first.

Issues (originally): Didn't freeze bessie when she reached (N,N) on only one direction, got 3/10.

Total time is O(n^4), which passed in time for me.

**USACO 2018 Open Gold - Out of Sorts** \
12.5.2019 \
Estimated CF Difficulty: 1800

Greedy + BIT (:pig: :deciduous_tree:)

For each operation, we observe that one lower element (which breaks the sorted condition) moves to the top, and one higher element (which breaks the sorted condition) moves down. So we see that the number of moos is the number of swapped elements.

Take an arbitrary index i. If some value appears on one side of i on the unsorted and another side of i on the sorted, then it suffices that that value must be swapped. So we can simply keep track of which elements in the sorted are not present in the unsorted up to i.

This can be done with a BIT. This functions as a faster visited array; it stores 1 if a number exists at or before i, and 0 otherwise. At each i, we find the amount that is i-sum before i, which finds the number of zeroes in the tree. Over all i, we clearly take the max.

Errors I made:
1) the answer starts at 1 because we're guaranteed to go through the loop >=1 times.

**USACO 2018 December Gold - Fine Dining** \
11/28/2019 \
Estimated CF Rating: 1700

Graph Theory

Dijkstras but with one catch: We must account for the candy.

This is not bad. Simply take the original shortest paths.
Then, we input the haybales. For each haybale, let it lead to a point N+1 with weight (distance to n) - yumminess. Run Dijkstra again on a different distance array, and compare the distances at the end.

**USACO 2018 December Gold - Cowpatibility**\
11/28/2019 \
Estimated CF Rating: 2300

Math, Combinatorics

We complementary count to find the number that are compatible and subtract from n*(n-1)/2.

As we have at most 31n subsets by including solely numbers mentioned we should be in time.

Use an unordered_map to find all the subsets and the frequencies of each. Then simply run PIE at the end to find the number of pairs.

Implementation details:
unordered_map is better because it processes adds in O(1), while map may take O(lg n). Additionally, ensure to sort the flavors in ascending order or else you will WA. You will count different subsets multiple times due to ordering.

(btw you is in reference to me, because i want to tell my future self about this new geniosity that i have temporarily acquired)

**USACO 2018 December Gold - Teamwork** \
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