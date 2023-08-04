'''
cross matrix problem
'''
def solution(matrix):
    res = 0
    for i in range(len(matrix)):
        r = [matrix[i][k] for k in range(len(matrix[0])) if i!=k]
        for j in range(len(matrix[0])):
            c = [matrix[k][j] for k in range(len(matrix)) if k!=j]
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