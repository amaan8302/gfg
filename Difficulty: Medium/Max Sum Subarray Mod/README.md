<h2><a href="https://www.geeksforgeeks.org/problems/max-sum-subarray-mod/1?page=1&sortBy=latest">Max Sum Subarray Mod</a></h2><h3>Difficulty Level : Difficulty: Medium</h3><hr><div class="problems_problem_content__Xm_eO"><p><span style="font-size: 14pt;">Given an array of<span style="font-family: math;"> </span><span style="font-size: 14pt;">n </span>elements and an integer <span class="katex">m</span>, find the maximum value of the sum of any subarray modulo m.</span></p>
<p>.<strong style="font-size: 18.6667px;">Examples:</strong></p>
<pre><span style="font-size: 14pt;"><strong>Input</strong>: arr[] = [10, 7, 18], m = 13
<strong>Output</strong>: 12
<strong>Explanation</strong>: All subarrays and their modulo values:<br></span><span style="font-size: 18.6667px;">[10] → 10 mod 13 = 10  
[7] → 7 mod 13 = 7  
[18] → 18 mod 13 = 5  
[10, 7] → 17 mod 13 = 4  
[7, 18] → 25 mod 13 = 12  
[10, 7, 18] → 35 mod 13 = 9<br></span></pre>
<pre><span style="font-size: 14pt;"><strong>Input</strong>: arr[] = [3, 3, 9, 9, 5], m = 7
<strong>Output</strong>: 6
<strong>Explanation</strong>: The subarray [3,3] has maximum sub-array sum modulo 7</span></pre>
<p><span style="font-size: 14pt;"><strong>Constraints:</strong></span></p>
<p><span style="font-size: 14pt;">1 ≤ arr.size() ≤ 10<sup>5<br></sup></span><span style="font-size: 14pt;">1 ≤ m ≤&nbsp;10<sup>9</sup><br>1 ≤ arr[i] ≤ 10<sup>8</sup></span></p></div><br><p><span style=font-size:18px><strong>Topic Tags : </strong><br><code>prefix-sum</code>&nbsp;<code>Mathematical</code>&nbsp;<code>Data Structures</code>&nbsp;<code>Algorithms</code>&nbsp;