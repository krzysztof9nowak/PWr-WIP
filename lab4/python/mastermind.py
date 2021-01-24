from collections import Counter
codes = []

def generate_all_posible_codes(dim, array):
    if dim == 0:
        codes.append(array)
        return
    for i in range(1,6+1):
        new_array = array[:]
        new_array.append(i)
        generate_all_posible_codes(dim - 1, new_array)

def count_matching_colors(a, b):
    matches = 0
    a = Counter(a)
    b = Counter(b)
    for color, count in a.items():
        if color in b:
            matches += min(count, b[color])
    return matches

def count_matching_only_colors(a, b):
    return count_matching_colors(a,b) - count_matching_colors_and_pos(a,b)

def count_matching_colors_and_pos(a, b):
    return sum([x[0] == x[1] for x in zip(a,b)])

def match(a, b, col, pos):
    return col == count_matching_only_colors(a,b) and pos == count_matching_colors_and_pos(a,b)


generate_all_posible_codes(4, [])
while len(codes) > 1:
    print(f"Pozostało {len(codes)} potencjalnych kodów")
    guess = codes[0]
    print(f"Zgaduję: {guess}")
    pos = int(input("Red: "))
    colors = int(input("White: "))
    codes = [x for x in codes if match(guess, x, colors, pos)]

if len(codes) == 1:
    print("bot wins!")
else:
    print("cheeeater!")