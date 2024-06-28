// 374. Guess Number Higher or Lower

/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        long long low=1;
        long long high=n;
        long long num=n/2;

        while(guess(num)!=0)
        {
            if(guess(num)==-1)
            {
                high=num-1;
            }
            else if(guess(num)==1)
            {
                low=num+1;
            }
        }
        return num;
    }
};