# Accepted

def max_zeros(L, K):
    if K == 0:
        return L
    zeros = L - K
    max_length = zeros // (K + 1)
    remaining = zeros % (K + 1)
    if remaining > 0:
        max_length += 1
    return max_length

    
L, K = map(int, input().split())


print(max_zeros(L, K),end="")