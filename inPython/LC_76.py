# Minimum Window Substring

class Solution:
    def minWindow(self, s: str, t: str) -> str:
        if t == "":
            return ""

        countT, window = {}, {}

        # Count frequencies of characters in t
        for c in t:
            countT[c] = 1 + countT.get(c, 0)

        have, need = 0, len(countT)
        res, resLen = [-1, -1], float("infinity")
        l = 0

        # Expand the window by moving 'r'
        for r in range(len(s)):
            c = s[r]
            window[c] = 1 + window.get(c, 0)

            # Check if current character satisfies the condition
            if c in countT and window[c] == countT[c]:
                have += 1

            # Shrink the window if all characters are satisfied
            while have == need:
                # Update the result if the current window is smaller
                if (r - l + 1) < resLen:
                    res = [l, r]
                    resLen = r - l + 1

                # Remove the leftmost character from the window
                window[s[l]] -= 1
                if s[l] in countT and window[s[l]] < countT[s[l]]:
                    have -= 1
                l += 1

        l, r = res
        return s[l:r+1] if resLen != float("infinity") else ""

# Example usage
if __name__ == "__main__":
    solution = Solution()
    s = "ADOBECODEBANC"
    t = "ABC"
    print("Minimum window substring:", solution.minWindow(s, t))