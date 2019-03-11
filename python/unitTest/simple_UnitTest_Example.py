import unittest

class StringTests(unittest.TestCase):
    def test_simpleString(self):
        assert("FOO"=="foo".upper())
        
    def test_equalString(self):
        self.assertEqual("FOO", "foo".upper())

    def test_upperString(self):
        self.assertTrue("FOO" == "foo".upper())

    def test_lowerString(self):
        self.assertFalse("FOO" == "foo".lower())


if __name__ == "__main__":
    unittest.main()
