# Solution
We can use the Euler tree technique and binary indexed trees to solve this question.

First, we compute the in and out times for the tree in question using the Euler tree technique highlighted in this section, calculating each vertex's in and out times (which we will represent as **i_x** and **o_x**). We observe that this transforms the tree into an array, with subtrees as "ranges" in the new array.

This inspires us to use binary indexed trees, which support range queries and range updates. We know that the range in which vertex **x** is represented is [**i_x**,**o_x**). Therefore, we can xor **e_i** at the points **i_x** and **o_x** in the grid. Using solely the BIT, we can find path xor's from node 1 to every node.

To find path queries for all paths, we find the LCA. Some binary logic gives us that the formula for the path xor is XOR(bit.xor(**i_u**), bit.xor(**i_v**), **e_lca(u,v)**).