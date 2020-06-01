import mock
import os

# function/class in another module
def somelibfunction(path):
    return os.listdir(path)

@mock.patch('os.listdir', mock.MagicMock(return_value=["one", "two"]))
def test_somelibfunction():
    ret = somelibfunction("/root/")
    assert ret!=None

test_somelibfunction()
