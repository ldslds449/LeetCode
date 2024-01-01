class Solution {
public:
    int passThePillow(int n, int time) {
        int dir = time / (n-1);
        int offset = time % (n-1);
        return dir % 2 ? n - offset : 1 + offset;    
    }
};