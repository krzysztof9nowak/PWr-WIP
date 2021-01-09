def match(pattern, sequence):
    if len(pattern) == 0 and len(sequence) == 0:
        return True
    if len(pattern) == 0:
        return False
    if pattern[0] == '?':
        return match(pattern[1:], sequence[1:])
    if pattern[0] == '*':
        if len(sequence) == 0:
            return match(pattern[1:], '')
        else:
            return match(pattern[1:], sequence[1:]) or match(pattern, sequence[1:])
    if len(sequence) == 0:
        return False
    if pattern[0] == sequence[0]:
        return match(pattern[1:], sequence[1:]) 
    return False
    