'''
cross matrix problem
'''
def solution(matrix):
    res = 0
    for i in range(len(matrix)):
        _r = matrix[i]
        for j in range(len(matrix[i])):
            r = [_r[k] for k in range(len(_r)) if k != j]
            c = [matrix[k][j] for k in range(len(matrix)) if k != i]
            # print(r, c)
            if r == c:
                res += 1
    return res
print(solution(matrix = [
  [1, 2],
  [2, 1]
]))

print(solution(matrix = [
  [1, 1, 1, 1],
  [2, 3, 1, 1],
  [1, 1, 1, 0],
  [1, 4, 1, 1]
]))

print(solution(matrix = [
  [1, 2, 3, 4],
  [5, 6, 7, 8],
  [9, 10, 11, 12],
  [13, 14, 15, 15]
]))