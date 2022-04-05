# Previous number in one swap
## Medium 
<div class="problem-statement">
                <p><a onclick="gtagHelperFunction('clickopen','salesevent_gsc_problemspage_promobanner')" href="https://practice.geeksforgeeks.org/summer-carnival-2022?utm_source=practiceproblems&amp;utm_medium=problemspromobanner&amp;utm_campaign=gsc22" target="_blank"></a></p><div style="margin: 14px 0px !important;" class="row"><a onclick="gtagHelperFunction('clickopen','salesevent_gsc_problemspage_promobanner')" href="https://practice.geeksforgeeks.org/summer-carnival-2022?utm_source=practiceproblems&amp;utm_medium=problemspromobanner&amp;utm_campaign=gsc22" target="_blank">             <div class="col-md-12" style="cursor:pointer;background: #EFF8F3 0% 0% no-repeat padding-box; display: flex; align-items: center; position:                 relative; padding: 1.5%; border-radius: 10px; display: inline-block; text-align: center; font-weight: 600; color: #333"> <img src="https://media.geeksforgeeks.org/img-practice/gcs2022thumbnail-1649059370.png" alt="Lamp" width="46" height="40" style="background: transparent 0% 0% no-repeat padding-box;opacity: 1; margin: 0 16px;" class="img-responsive"> Geeks Summer Carnival is LIVE NOW &nbsp; <i class="fa fa-external-link" aria-hidden="true"></i> </div></a></div><p><span style="font-size:18px">Given a non-negative number N in the form of string. The task is to apply at most one swap operation on the number N so that the result is just a previous possible number.</span></p>

<p><span style="font-size:18px"><strong>Note:&nbsp; </strong>Leading zeros are not allowed.</span></p>

<p>&nbsp;</p>

<p><span style="font-size:18px">Example 1:</span></p>

<pre><span style="font-size:18px"><strong>Input :
</strong>S = "12435"
<strong>Output: 
</strong>12345
<strong>Explanation:
</strong>Although the number 12354 
will be the largest smaller 
number from 12435. But it is 
not possible to make it using 
only one swap. So swap 
4 and 3 and get 12345.</span></pre>

<p>&nbsp;</p>

<p><span style="font-size:18px">Example 2:</span></p>

<pre><span style="font-size:18px"><strong>Input: 
</strong>S = " 12345"
<strong>Output: 
</strong>-1
<strong>Explanation:
</strong>Digits are in increasing order. 
So it is not possible to 
make a smaller number from it.</span></pre>

<p>&nbsp;</p>

<p><strong><span style="font-size:18px">Your Task:</span></strong></p>

<p><span style="font-size:18px">You don't need to read input or print anything. Your task is to complete the function previousNumber() which takes the string S and returns the previous number of S. If no such number exists return -1;</span></p>

<p>&nbsp;</p>

<p><span style="font-size:18px">Expected Time Complexity: O(N)<br>
Expected Auxiliary Space: O(1)</span></p>

<p>&nbsp;</p>

<p><span style="font-size:18px"><strong>Constraints:</strong><br>
2&lt;=|Number length |&lt;=10<sup>5</sup></span></p>

<p>&nbsp;</p>
 <p></p>
            </div>