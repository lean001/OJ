/*AC
一只青蛙一次可以跳上1级台阶，也可以跳上2级。求该青蛙跳上一个n级的台阶总共有多少种跳法。
http://www.nowcoder.com/books/coding-interviews/8c82a5b80378478f9484d87d1c5f12a4?rp=1
*/
class Solution {
public:
    int jumpFloor(int number) {
        int first = 0, second = 1, sum = 0, i = 0;
        if (number == 0)
            return 0;
        if (number == 1)
            return 1;
         
       for(; i < number; i++) {
            sum = first + second;
            first = second;
            second = sum;
        }
        return sum;           
    }
};
