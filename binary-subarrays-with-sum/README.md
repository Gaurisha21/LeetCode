<h2>930. Binary Subarrays With Sum</h2><h3>Medium</h3><hr><div><p>In an array <code>nums</code> of <code>0</code>s and <code>1</code>s, how many <strong>non-empty</strong> subarrays have sum <code>goal</code>?</p>

<p>&nbsp;</p>

<p><strong>Example 1:</strong></p>

<pre><strong>Input: </strong>nums = <span id="example-input-1-1">[1,0,1,0,1]</span>, goal = <span id="example-input-1-2">2</span>
<strong>Output: </strong><span id="example-output-1">4</span>
<strong>Explanation: </strong>
The 4 subarrays are bolded below:
[<strong>1,0,1</strong>,0,1]
[<strong>1,0,1,0</strong>,1]
[1,<strong>0,1,0,1</strong>]
[1,0,<strong>1,0,1</strong>]
</pre>

<p>&nbsp;</p>

<p><strong>Note:</strong></p>

<ol>
	<li><code>nums.length &lt;= 30000</code></li>
	<li><code>0 &lt;= goal &lt;= nums.length</code></li>
	<li><code>nums[i]</code>&nbsp;is either <code>0</code>&nbsp;or <code>1</code>.</li>
</ol>
</div>