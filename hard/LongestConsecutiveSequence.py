
class Solution:
    def longestConsecutive(self, num):
        marked_dict = {}
        for x in num:
            marked_dict[x] = False

        max_all = 0
        for x in num:
            if marked_dict[x]:
                continue
            current_length = 1
            marked_dict[x] = True
            x_to_upper = x + 1
            x_to_lower = x - 1
            while marked_dict.has_key(x_to_upper):
                marked_dict[x_to_upper] = True
                x_to_upper += 1
                current_length += 1
            while marked_dict.has_key(x_to_lower):
                marked_dict[x_to_lower] = True
                x_to_lower -= 1
                current_length += 1

            if current_length > max_all:
                max_all = current_length
        return max_all

sol = Solution()
print sol.longestConsecutive([100,4,200,1,3,2])

test_list = [x for x in reversed(xrange(9000))]
print sol.longestConsecutive(test_list)
