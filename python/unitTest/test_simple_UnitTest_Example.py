#!/usr/bin/env python
import sys
import unittest
version = 1.1

class StringTests(unittest.TestCase):
    def setUp(self):
        print("running setup form StringTests")

    def tearDown(self):
        print("running tearDown form StringTests")

    def test_simpleString(self):
        assert("FOO"=="foo".upper())

    def test_equalString(self):
        self.assertEqual("FOO", "foo".upper())

    @unittest.skip("not implemented...")
    def test_no_implemented_String(self):
        self.assertEqual("FOO", "foo".upper())

    # skip this test if version == 1.1
    @unittest.skipIf(version==1.1, "version skip ...")
    def test_on_version_String(self):
        self.assertEqual("FOO", "foo".upper())

    # Skip test if platform is not windows
    @unittest.skipUnless(sys.platform.startswith("win"), "requires Windows")
    def test_on_platform_String(self):
        self.assertEqual("FOO", "foo".upper())

    # Consider failure of this test as success
    @unittest.expectedFailure
    def test_failure_is_success_String(self):
        self.assertEqual("FO", "foo".upper())





class StringTestsUpperLower(unittest.TestCase):
    def setUp(self):
        print("running setup form StringTestsUpperLower")

    def tearDown(self):
        print("running tearDown form StringTestsUpperLower")

    def test_upperString(self):
        self.assertTrue("FOO" == "foo".upper())

    def test_lowerString(self):
        self.assertFalse("FOO" == "foo".lower())



if __name__ == "__main__":
    unittest.main()
