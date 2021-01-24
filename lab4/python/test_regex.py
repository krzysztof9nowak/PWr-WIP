import unittest
from pseudo_regex import match

class test1(unittest.TestCase):
    def test_empty(self):
        self.assertTrue(match('', ''))

    def test_empty_pattern_non_empty_sequence(self):
        self.assertFalse(match('', 'a'))

    def test_empty_sequency_non_empty_pattern(self):
        self.assertFalse(match('a', ''))

    def test_one_letter(self):
        self.assertTrue(match('a', 'a'))

    def test_one_letter_mismatch(self):
        self.assertFalse(match('a', 'b'))

    def test_two_letter_match(self):
        self.assertTrue(match('ab', 'ab'))

    def test_two_letter_mismatch(self):
        self.assertFalse(match('ab', 'aa'))

    def test_different_lengths(self):
        self.assertFalse(match('amla', 'aml'))

    def test_long_words(self):
        self.assertTrue(match('halo', 'halo'))
        self.assertTrue(match('123', '123'))

    def test_single_letter_match(self):
        self.assertTrue(match('?', 'a'))

    def test_two_question(self):
        self.assertTrue(match('??', 'ab'))

    def test_question_in_word(self):
        self.assertTrue(match('a?a', 'ala'))

    def test_fail_with_question(self):
        self.assertFalse(match('a?b', 'ama'))

    def test_star_empty(self):
        self.assertTrue(match("*", ""))

    def test_star_letter(self):
        self.assertTrue(match("*", "a"))

    def test_star_two_letters(self):
        self.assertTrue(match("*", "aa"))

    def test_star_sentence(self):
        self.assertTrue(match("*", "ala ma kota"))

    def test_star_prepend(self):
        self.assertTrue(match("al*", "alamakota"))

    def test_star_append(self):
        self.assertTrue(match("*ota", "makota"))

    def test_star_append_fail(self):
        self.assertFalse(match("*a", "k"))

    def test_kobylanski1(self):
        self.assertTrue(match("a*b*a","abababababababababababa"))
    
    def test_kobylanski2(self):
        self.assertFalse(match("a*b*a","ababababababababababab"))

if __name__ == "__main__":
    unittest.main()
