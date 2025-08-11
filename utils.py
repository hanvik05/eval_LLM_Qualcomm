def add_numbers(numbers):
    # BUG: forgot to use sum()
    result = 0
    for num in numbers:
        result =+ num  # wrong operator — should be +=
    return result
