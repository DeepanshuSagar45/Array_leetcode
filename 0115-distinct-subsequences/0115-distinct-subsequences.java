class Solution {

    public int numDistinct(String s, String t) {

        int[][] dp = new int[s.length()][t.length()];

        for (int[] row : dp) {
            java.util.Arrays.fill(row, -1);
        }

        return solve(s, t, 0, 0, dp);
    }

    private int solve(String s, String t, int i, int j, int[][] dp) {

        // We have formed t completely
        if (j == t.length()) {
            return 1;
        }

        // s is finished but t is not
        if (i == s.length()) {
            return 0;
        }

        // Already calculated
        if (dp[i][j] != -1) {
            return dp[i][j];
        }

        if (s.charAt(i) == t.charAt(j)) {

            // Pick the current character
            int pick = solve(s, t, i + 1, j + 1, dp);

            // Skip the current character
            int skip = solve(s, t, i + 1, j, dp);

            return dp[i][j] = pick + skip;
        }

        // Characters don't match, so we can only skip
        int skip = solve(s, t, i + 1, j, dp);

        return dp[i][j] = skip;
    }
}