class Solution {
public:
    
int sumOddLengthSubarrays(vector<int>& arr) {
    
    int sum = 0, n = arr.size();
    if(n % 2) {
        for(int _ = 0; _ < arr.size() / 2; _++) {
            int i = _ + 1;
            if(i % 2) {
                sum += (arr[_] * (((i * (i + 1) / 2) - (i / 2)) + ((n + 1) / 2 - i) * i)) +
                 (arr[n - _ - 1] * (((i * (i + 1) / 2) - (i / 2)) + ((n + 1) / 2 - i) * i));
                // debug(i, (((i * (i + 1) / 2) - (i / 2)) + ((n + 1) / 2 - i) * i));
                //  debug(sum);
            }
            else {
                sum += (arr[_] * ( i * i / 2 + ((n + 1) / 2 - i) * i))  +
                (arr[n - _ - 1] * ( i * i / 2 + ((n + 1) / 2 - i) * i) );
                // debug(i, ( i * i / 2 + ((n + 1) / 2 - i) * i) );
                // debug(sum);
            }
        }
        int i = (n+1) /2;

        sum += arr[i - 1] * (i % 2 ? ((i * (i + 1) / 2) - (i / 2)) : (i * i) / 2 );
    }
    else {
        for(int _ = 0; _ < n / 2; _++) {
            int i = _ + 1;
            if(i % 2) {
                // debug(i, (i * (i + 1) / 2 + (n / 2 - i) * i));
                sum += (arr[_] * (i * (i + 1) / 2 + (n / 2 - i) * i)) + 
                        (arr[n - _ - 1] * (i * (i + 1) / 2 + (n / 2 - i) * i));
            }
            else {
                // debug(i, (((i * (i + 2)/ 2) - i/2) + (n / 2 - i) * i));
                sum += (arr[_] * (((i * (i + 2)/ 2) - i/2) + (n / 2 - i) * i)) + 
                        (arr[n - _ - 1] * (((i * (i + 2)/ 2) - i/2) + (n / 2 - i) * i));
            }
        }
    }
    // debug((i % 2 ? ((i * (i + 1) / 2) - (i / 2)) : (i * i) / 2 ));
    return sum;
}
};