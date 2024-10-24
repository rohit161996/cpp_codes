def find_row_col_sum(matrix, x):
    """
    Finds the row number, column number, and sum of digits of even/odd numbers in a matrix.

    Args:
        matrix: A square matrix of integers.
        x: The target element to search for.

    Returns:
        The sum of digits of even/odd numbers in the matrix, depending on the sum of the row and column numbers.
    """

    n = len(matrix)
    for i in range(n):
        for j in range(n):
            if matrix[i][j] == x:
                row, col = i, j
                break

    row_col_sum = row + col
    if row_col_sum % 2 == 0:
        return sum(sum(digit for digit in str(num) if int(digit) % 2 == 0) for num in matrix)
    else:
        return sum(sum(digit for digit in str(num) if int(digit) % 2 != 0) for num in matrix)

if __name__ == "__main__":
    n = 3
    matrix = []
    for _ in range(n):
        row = list(map(int, input().split()))
        matrix.append(row)
    x = 5

    result = find_row_col_sum(matrix, x)
    print(result)