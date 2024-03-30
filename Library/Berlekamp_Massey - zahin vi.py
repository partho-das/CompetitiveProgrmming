import sys
from copy import deepcopy
from itertools import accumulate


class Matrix:
    def __init__(self, dimension, modulo, diagonal=0):
        self.n = dimension
        self.modulo = modulo
        
        self.matrix = [[0 for _ in range(dimension)] for _ in range(dimension)]
        for i in range(dimension):
            self.matrix[i][i] = diagonal


    def multiply(self, multiplicand):
        result = Matrix(self.n, self.modulo)
        
        for i in range(self.n):
            for j in range(self.n):
                for k in range(self.n):
                    result.matrix[i][j] += self.matrix[i][k] * multiplicand.matrix[k][j]
                result.matrix[i][j] %= self.modulo
        
        return result
    
    
    def exponentiate(self, exponent):
        x = deepcopy(self)
        result = Matrix(self.n, self.modulo, 1)
        
        while exponent:
            if exponent & 1:
                result = result.multiply(x)
            
            exponent >>= 1
            x = x.multiply(x)
        
        return result


def convolution(first, second, modulo):
    assert len(first) == len(second)
    
    result = 0
    for f, s in zip(first, second):
        result = (result + f * s) % modulo
    
    return result


def berlekamp_massey(base_sequence, modulo):
    n = len(base_sequence)
    assert n and n % 2 == 0
    
    U = [int(i == 0) for i in range(n + 1)]
    V = [int(i == 0) for i in range(n + 1)]
    base_sequence = base_sequence[::-1]
    
    l, m, b, deg = 0, 1, 1, 0
    for i in range(n):
        d = base_sequence[n - i - 1]

        if l:
            d = (d + convolution(V[1:1+l], base_sequence[n-i:n-i+l], modulo)) % modulo
        
        if not d:
            m += 1
            continue

        if (l * 2) <= i:
            W = V[:l+1]

        x = (pow(b, modulo - 2, modulo) * (modulo - d) % modulo + modulo) % modulo
        for j in range(deg + 1):
            V[m + j] = (V[m + j] + x * U[j]) % modulo
        
        if (l * 2) <= i:
            U, W = W, U
            deg = len(U) - 1
            b, m, l = d, 1, i - l + 1
        else:
            m += 1
    
    V = V[:l+1] + [0 for _ in range(max(0, l - len(V) + 1))]
    return V[1:]
    

def solve_linear_recurrence(base_sequence, nth_term, modulo):
    n = len(base_sequence)
    if nth_term < n:
        return base_sequence[nth_term]
    
    recurrence = berlekamp_massey(base_sequence, modulo)
    
    l = len(recurrence)
    ar = Matrix(l, modulo)
    
    for i in range(l):
        ar.matrix[0][i] = modulo - recurrence[i]
        if i:
            ar.matrix[i][i - 1] = 1
    
    result = 0
    ar = ar.exponentiate(nth_term - n + 1)
    for i in range(l):
        result += ar.matrix[0][i] * base_sequence[n - i - 1]
    
    return result % modulo
    

def solve(n, c, k, modulo):
    s, a, b = 0, 0, 1
    
    fib = [int(i == 1) for i in range(400)]
    for i in range(2, 400):
        fib[i] = (fib[i - 1] + fib[i - 2]) % modulo
    
    base_sequence = [pow(fib[i * c], k, modulo) for i in range(30)]
    base_sequence = list(accumulate(base_sequence))
    base_sequence = [x % modulo for x in base_sequence]
    
    return solve_linear_recurrence(base_sequence, n, modulo)


def main():
    t = int(input())
    assert t >= 1 and t <= 100
    
    for i in range(t):
        n, c, k = map(int, input().split())
        assert n >= 0 and n <= 10**15 and c >= 0 and c <= 10 and k >= 0 and k <= 10
        print("Case {}: {}".format(i + 1, solve(n, c, k, 10**9 + 7)))
    
    
if __name__ == '__main__':
	main()