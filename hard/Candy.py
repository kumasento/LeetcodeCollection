
class Solution:
    def candy(self, ratings):
        len_of_ratings = len(ratings)
        l_max_list = [None] * len_of_ratings
        r_max_list = [None] * len_of_ratings

        l_max_list[0] = 1
        r_max_list[len_of_ratings-1] = 1
        for idx in xrange(1,len_of_ratings):
            if ratings[idx] > ratings[idx-1]:
                l_max_list[idx] = l_max_list[idx-1] + 1
            else:
                l_max_list[idx] = 1

        for idx in reversed(xrange(len_of_ratings-1)):
            if ratings[idx] > ratings[idx+1]:
                r_max_list[idx] = r_max_list[idx+1] + 1
            else:
                r_max_list[idx] = 1

        sum_of_all = 0
        for idx in xrange(len_of_ratings):
            sum_of_all += max(r_max_list[idx], l_max_list[idx])
        return sum_of_all

sol = Solution()
print sol.candy([0, 1, 0])
print sol.candy([0, 1, 0, 1, 0])
print sol.candy([0, 1, 2, 3, 4])
