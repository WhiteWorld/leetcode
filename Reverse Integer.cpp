class Solution {
public:
    int reverse(int x) {
        if (x == 0)
            return 0;
        
        bool negtive = x < 0;
        x = negtive ? -x : x;
        while (x % 10 == 0)
            x = x / 10;
        
        int y = 0;
        while (x > 0) {
            y += x % 10;
            y *= 10;
            x /= 10;
        }
        y /= 10;
        return negtive ? -y : y;       
    }
};