public class Solution {
    /*对于不能排序的要考虑使用空间解决，使用Set Map等*/
    
    /*很巧妙的，一次扫描就得出了结果*/
    public int longestConsecutive(int[] num) {
        Map<Integer, Integer> sequence = new HashMap<Integer, Integer>();
        int longest = 0;
        for (int i = 0; i < num.length; i++) {
            if (sequence.containsKey(num[i])) continue;
            int lowerbound = num[i];
            int upperbound = num[i];
            if (sequence.containsKey(num[i] - 1)) // Get the lowerbound
                lowerbound = sequence.get(num[i] - 1);
            if (sequence.containsKey(num[i] + 1))// Get the Upperbound
                upperbound = sequence.get(num[i] + 1);
            longest = Math.max(longest, (upperbound - lowerbound)+ 1);
            sequence.put(num[i],num[i]);
            sequence.put(lowerbound, upperbound);
            sequence.put(upperbound, lowerbound);
        }
        return longest;
    }
}