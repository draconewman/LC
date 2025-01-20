# 556. Next Greater Element III

class Solution:
    def nextGreaterElement(self, n: int) -> int:
        # Convert the number to a list of characters for easy manipulation
        s = list(str(n))
        i = len(s) - 2  # Start from the second-to-last digit

        # Step 1: Find the first decreasing element from the right
        while i >= 0 and s[i] >= s[i + 1]:
            i -= 1

        # If no decreasing element is found, the number is the largest possible permutation
        if i == -1:
            return -1

        # Step 2: Find the smallest element larger than s[i] to the right of s[i]
        j = len(s) - 1
        while s[j] <= s[i]:
            j -= 1

        # Step 3: Swap the two elements to create a larger number
        s[i], s[j] = s[j], s[i]

        # Step 4: Reverse the portion of the list after the swapped element to get the smallest permutation
        s = s[:i + 1] + s[i + 1:][::-1]

        # Convert the list back to an integer
        result = int(''.join(s))

        # Step 5: Check if the result is within the 32-bit integer range
        return result if result <= 2**31 - 1 else -1
    
# Example usage
sol = Solution()
n = 123459876
result = sol.nextGreaterElement(n)
print(f"Next greater element for {n} is: {result}")