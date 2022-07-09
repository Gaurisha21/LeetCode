# Number of Distinct Islands
## Medium 
<div class="problem-statement">
                <p></p><p><span style="font-size:18px">Given a boolean 2D matrix <strong>grid&nbsp;</strong>of size <strong>n</strong> * <strong>m</strong>. You have to find the number of distinct islands where a group of connected 1s (horizontally or vertically) forms an island. Two islands are considered to be distinct if and only if one island is equal to another (not rotated or reflected).</span></p>

<p><strong><span style="font-size:18px">Example 1:</span></strong></p>

<pre><span style="font-size:18px"><strong>Input:</strong></span>
<span style="font-size:18px">grid[][] = {{1, 1, 0, 0, 0},
            {1, 1, 0, 0, 0},
            {0, 0, 0, 1, 1},
            {0, 0, 0, 1, 1}}</span>
<span style="font-size:18px"><strong>Output:</strong></span>
<span style="font-size:18px">1</span>
<span style="font-size:18px"><strong>Explanation:</strong></span>
<span style="font-size:18px">Island 1, 1 at the top left corner is same as island
1, 1 at the bottom right corner.</span>
</pre>

<p><strong><span style="font-size:18px">Example 2:</span></strong></p>

<pre><span style="font-size:18px"><strong>Input:</strong></span>
<span style="font-size:18px">grid[][] = {{1, 1, 0, 1, 1},
            {1, 0, 0, 0, 0},
            {0, 0, 0, 0, 1},
            {1, 1, 0, 1, 1}}</span>
<span style="font-size:18px"><strong>Output:</strong></span>
<span style="font-size:18px">3</span>
<span style="font-size:18px"><strong>Explanation:</strong></span>
<span style="font-size:18px">Distinct islands are: 1, 1 at the top left corner;
1, 1 at the top right corner and 1 at the bottom 
right corner. We ignore the island 1, 1 at the 
bottom left corner since 1, 1 it is identical to the 
top right corner.</span>
</pre>

<p><span style="font-size:18px"><strong>Your Task:</strong></span></p>

<p><span style="font-size:18px">You don't need to read or print anything. Your task is to complete the function <strong>countDistinctIslands()&nbsp;</strong>which takes the <strong>grid</strong> as an input parameter and returns the total number of <strong>distinct</strong> islands.</span></p>

<p><span style="font-size:18px"><strong>Expected Time Complexity:&nbsp;</strong>O(n * m)<br>
<strong>Expected Space Complexity:&nbsp;</strong>O(n * m)</span></p>

<p><span style="font-size:18px"><strong>Constraints:</strong></span></p>

<ul>
	<li><span style="font-size:18px">1 ≤ n, m ≤ 500</span></li>
	<li><span style="font-size:18px">grid[i][j] == 0 or grid[i][j] == 1</span></li>
</ul>

<ul>
</ul>
 <p></p>
            </div>