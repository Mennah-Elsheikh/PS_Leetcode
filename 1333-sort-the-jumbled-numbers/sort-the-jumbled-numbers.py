class Solution(object):
    def sortJumbled(self, mapping, nums):
        def get_mapped_value(num):
            mapped_str = ''.join(str(mapping[int(digit)]) for digit in str(num))
            return int(mapped_str)
        mapped_nums = [(num, get_mapped_value(num)) for num in nums]
        mapped_nums.sort(key=lambda x: x[1])
        sorted_nums = [num for num, _ in mapped_nums]        
        return sorted_nums