import unittest


def unique_no_ds(string):
    for x in range(0, len(string) - 1):
        for y in range(x + 1, len(string)):
            if string[x] == string[y]:
                return False
    return True


def unique(string):
    if len(string) > 128:
        return False
    char_set = [False]*128
    for char in string:
        if char_set[ord(char)]:
            return False
        char_set[ord(char)] = True
    return True


class Test(unittest.TestCase):
    dataT = [('abcd'), ('s4fad'), ('')]
    dataF = [('23ds2'), ('hb 627jh=j ()')]

    def test_unique(self):
        # true check
        for test_string in self.dataT:
            actual = unique(test_string)
            self.assertTrue(actual)
        # false check
        for test_string in self.dataF:
            actual = unique(test_string)
            self.assertFalse(actual)


if __name__ == "__main__":
    unittest.main()
