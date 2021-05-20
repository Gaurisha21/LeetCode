class Solution {
public:
    int mod = (int) 1e9 + 7;
    int kadanesAlgo(vector<int> arr, int k) {
        int n = arr.size();
        long gsum = 0, csum = 0;

        for (int i = 0; i < k * n; i++) {
            int ele = arr[i % n];
            csum += ele;

            if (csum > gsum)
                gsum = csum;
            if (csum <= 0)
                csum = 0;
        }

        return (int) gsum % mod;
    }

    int kConcatenationMaxSum(vector<int>arr, int k) {
        long prevSum = 0, sum = 0;
        for (int i = 1; i <= 3; i++) {
            prevSum = sum;
            sum = kadanesAlgo(arr, i);
            if (i == k)
                return (int) sum;
        }

        return (int) ((prevSum + (k - 2) * (sum - prevSum)) % mod);
    }
};